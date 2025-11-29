#include "CircularQueue.h"
#include "bucket.h"
#include <iostream>

int main() {
	Bucket b;
	for (int i = 0; i < 5; i++) {
		b.add(10);
		std::cout << b.test << '\n';
	}
	return 0;
}