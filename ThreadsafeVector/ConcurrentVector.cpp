#include "ConcurrentVector.h"

ConcurrentVector::ConcurrentVector()
{
	std::cout << "CTOR: " << this << std::endl;
}

ConcurrentVector::~ConcurrentVector()
{
	std::cout << "DTOR: " << this << std::endl;
}

void ConcurrentVector::push_back(int in)
{
	std::unique_lock<std::mutex> lock(mut);
	cond.wait(lock);

	this->vec.push_back(in);
	std::cout << "pushed back " << in << ", at index " << this->vec.size() << std::endl;

	cond.notify_one();
}

void ConcurrentVector::print()
{
	std::lock_guard<std::mutex> lock(mut);

	std::cout << "This concurrentVector holds: \n";
	for (auto& i : this->vec)
	{
		std::cout << i << std::endl;
	}
	std::cout << std::endl;

	cond.notify_one();
}
