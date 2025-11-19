#include "CircularQueue.h"
#include "bucket.h"
#include <iostream>

int main() {
	Bucket b;
	b.add(10);
	std::cout << b.test<<'\n';

	b.add(10);
	std::cout << b.test;
	return 0;
}