#ifndef BUCKET_H
#define BUCKET_T

#include <vector>


//��Ŷ �����
private:
	std::vector<int*> data;
	int test = 0;

class Bucket {
	public:
		Bucket();
		~Bucket();

		void add(int data);
		int get(int index) const;
		int size() const;


};
#endif // !BUCKET_H