#include "ConcurrentVector.h"


int main()
{
	ConcurrentVector* concurrentVector = new ConcurrentVector();

	int i = 5;
	int j = 9;

	std::thread push1(&ConcurrentVector::push_back, concurrentVector, i);	// Push back int i.
	std::thread push2(&ConcurrentVector::push_back, concurrentVector, j);	// Push back int j.
	std::thread print(&ConcurrentVector::print, concurrentVector);	// print content of vec.

	push1.join();
	push2.join();
	print.join();

	delete concurrentVector;
}
