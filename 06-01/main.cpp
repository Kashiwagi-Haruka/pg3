#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

int main() {
	std::condition_variable cv;
	std::mutex mutex;
	int turn = 1;

	auto run = [&](int id) {
		std::unique_lock<std::mutex> lock(mutex);
		cv.wait(lock, [&] { return turn == id; });
		std::cout << "thread " << id << std::endl;
		++turn;
		lock.unlock();
		cv.notify_all();
	};

	std::thread t1(run, 1);
	std::thread t2(run, 2);
	std::thread t3(run, 3);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}