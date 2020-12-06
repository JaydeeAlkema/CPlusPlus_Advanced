#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>

int c = 0;
bool done = false;
std::queue<int> goods;

std::mutex mut;
std::condition_variable cv;

void producer()
{
	std::lock_guard<std::mutex> lock(mut);

	for (int i = 0; i < 500; ++i) {
		std::cout << "Producing..." << std::endl;
		goods.push(i);
		c++;
	}

	std::cout << "Producing done." << std::endl;
	done = true;
	cv.notify_one();
}

void consumer()
{
	std::unique_lock<std::mutex> lock(mut);
	cv.wait(lock, [] { return done; });

	while (!goods.empty()) {
		std::cout << "Consuming..." << std::endl;
		goods.pop();
		c--;
	}

	std::cout << "Consuming done." << std::endl;
}

int main()
{
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();
	std::cout << "Net: " << c << std::endl;
}