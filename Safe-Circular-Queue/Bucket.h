#ifndef BUCKET_H
#define BUCKET_T

#include <vector>


class Bucket {
	public:
		Bucket();
		~Bucket();

private:
	int* data[2];
	int front;
	int rear;
	int current_size;
public:
	int test;

		void add(int data);
		int get(int index) const;
		int size() const;
		int test = 0;
private:
	std::vector<int*> data;


};
#endif // !BUCKET_H