#ifndef BUCKET_H
#define BUCKET_T
//버킷 선언부
class Bucket {
	public:
		Bucket();
		~Bucket();
		void add(int data);
		int get(int index) const;
		int size() const;
	int test = 0;
};
#endif // !BUCKET_H