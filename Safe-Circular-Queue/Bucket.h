#ifndef BUCKET_H
#define BUCKET_T

#include <vector>


class Bucket {
	public:
		Bucket();
		~Bucket();

		void add(int data);
		int get(int index) const;
		int size() const;
		int test = 0;
private:
	std::vector<int*> data;


};
#endif // !BUCKET_H