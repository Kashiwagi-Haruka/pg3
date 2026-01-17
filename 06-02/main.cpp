#include <chrono>
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

void showMarquee(const std::string& text, size_t width, std::chrono::milliseconds delay) {
	if (text.empty()) {
		return;
	}

	std::string padding(width, ' ');
	std::string scrollText = padding + text + padding;
	for (size_t offset = 0; offset + width <= scrollText.size(); ++offset) {
		std::cout << '\r' << scrollText.substr(offset, width) << std::flush;
		std::this_thread::sleep_for(delay);
	}
	std::cout << "\r" << std::string(width, ' ') << "\r";
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
			auto message = joinCells(cells, " | ");
			{
				std::lock_guard<std::mutex> lock(mutex);
				queue.push_back(message);
			}
			cv.notify_all();
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}

		{
			std::lock_guard<std::mutex> lock(mutex);
			done = true;
		}
		cv.notify_all();
	});

	const size_t marqueeWidth = 50;
	while (true) {
		std::unique_lock<std::mutex> lock(mutex);
		cv.wait(lock, [&]() { return done || !queue.empty(); });

		while (!queue.empty()) {
			std::string message = queue.front();
			queue.pop_front();
			lock.unlock();
			showMarquee(message, marqueeWidth, std::chrono::milliseconds(80));
			std::cout << '\n';
			lock.lock();
		}

		if (done) {
			break;
		}
	}

	loader.join();

	return 0;
}