#include <condition_variable>
#include <deque>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

namespace {
std::vector<std::string> splitCsvLine(const std::string& line) {
	std::vector<std::string> cells;
	std::stringstream stream(line);
	std::string cell;

	while (std::getline(stream, cell, ',')) {
		cells.push_back(cell);
	}

	return cells;
}

std::string joinCells(const std::vector<std::string>& cells, const std::string& separator) {
	std::ostringstream joined;
	for (size_t i = 0; i < cells.size(); ++i) {
		joined << cells[i];
		if (i + 1 < cells.size()) {
			joined << separator;
		}
	}
	return joined.str();
}
} // namespace

int main() {
	const std::string csvPath = "data.csv";
	std::deque<std::string> queue;
	std::mutex mutex;
	std::condition_variable cv;
	bool done = false;

	std::thread loader([&]() {
		std::ifstream file(csvPath);
		if (!file) {
			std::lock_guard<std::mutex> lock(mutex);
			queue.push_back("CSVファイルを開けませんでした: " + csvPath);
			done = true;
			cv.notify_all();
			return;
		}

		std::string line;
		while (std::getline(file, line)) {
			auto cells = splitCsvLine(line);
			auto message = joinCells(cells, " ");
			{
				std::lock_guard<std::mutex> lock(mutex);
				queue.push_back(message);
			}
			cv.notify_all();
		}

		{
			std::lock_guard<std::mutex> lock(mutex);
			done = true;
		}
		cv.notify_all();
	});

	while (true) {
		std::unique_lock<std::mutex> lock(mutex);
		cv.wait(lock, [&]() { return done || !queue.empty(); });

		while (!queue.empty()) {
			std::string message = queue.front();
			queue.pop_front();
			lock.unlock();
			std::cout << message << '\n';
			lock.lock();
		}

		if (done) {
			break;
		}
	}

	loader.join();

	return 0;
}