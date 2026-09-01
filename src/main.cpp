#include <iostream>
#include "heap-test.h"

int main()
{
	tests::heap::heap_test heap_test;
	heap_test.run();
	
	std::cin.get();
	return 0;
}