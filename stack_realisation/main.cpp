#include <iostream>
#include "stack.h"

int main() {

	int n;
	std::cout << "Enter the number of elements: ";
	std::cin >> n;

	Numbers<int> stack;

	for (size_t i = 0; i < n; i++)
	{
		int x = rand() % 31;
		stack.push(x);

	}

	stack.showAll();

	std::cout << stack.head() << "\n";

	stack.pop();

	stack.push(2);
	stack.push(1);

	stack.showAll();

	stack.sort();

	stack.showAll();

	return 0;



}
