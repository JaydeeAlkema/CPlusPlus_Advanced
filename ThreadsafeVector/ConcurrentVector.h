#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <condition_variable>
#include <mutex>

class ConcurrentVector
{
public:
	ConcurrentVector();
	virtual ~ConcurrentVector();

	void push_back(int in);
	void print();

private:
	std::vector<int> vec;
	std::mutex mut;
	std::condition_variable cond;

	bool ready = false;
};