#include <iostream>
#include <vector>
#include "Parent.h"

int main() {
	std::vector<std::shared_ptr<Parent>> parents;

	std::shared_ptr<Parent> p1 = std::make_shared<Parent>("Parent 1");
	std::cout << "p1: " << *p1 << std::endl;

	std::shared_ptr<Parent> p2 = std::make_shared<Parent>(*p1); // roept de copy constructor aan
	std::cout << "\np2: " << *p2 << std::endl;

	std::shared_ptr<Parent> p3 = std::make_shared<Parent>("Parent 3");
	std::cout << "\np3: " << *p3 << std::endl;

	std::shared_ptr<Parent> p4 = std::make_unique<Parent>("Parent 4"); // roept de copy constructor aan
	std::cout << "\np4: " << *p4 << std::endl;
	std::cout << "p4 Use Count: " << p4.use_count() << std::endl;

	std::shared_ptr<Parent> p5(p4); // roept de copy constructor aan
	std::cout << "\np5: " << *p5 << std::endl;
	std::cout << "p4 Use Count: " << p4.use_count() << std::endl;
	p5.get()->removeChild();

	*p3 = *p1; // roept de assignment operator aan
	std::cout << "\np1: " << *p3 << std::endl;

	parents.push_back(p1);
	parents.push_back(p2);
	parents.push_back(p3);
	parents.push_back(p4);
	parents.push_back(p5);
	for (auto& p : parents)
	{
		std::cout << p.get()->getName() << ", Child Count " << p.get()->getChildCount() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}