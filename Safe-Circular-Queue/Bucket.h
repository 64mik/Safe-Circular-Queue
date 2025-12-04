#ifndef BUCKET_H
#define BUCKET_T

#include <vector>


class Bucket {
	public:
		Bucket();
		~Bucket();
		void add(int& input);
		void get(int& output);
	private:
		std::vector<int> data;
		int front=0;
		int rear=0;
		int current_size=0;


};
#endif // !BUCKET_H