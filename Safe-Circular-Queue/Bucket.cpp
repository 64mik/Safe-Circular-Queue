#include "Bucket.h"
#include <iostream>
#include <vector>

Bucket::Bucket() {
	//생성자 구현
}
Bucket::~Bucket() {
	//소멸자 구현
}
void Bucket::add(int data) {
	//데이터 추가 구현
	test += data;
}
int Bucket::get(int index) const {
	//데이터 조회 구현
	return 0; //임시 반환값
}
int Bucket::size() const {
	//버킷 크기 반환 구현
	return 0; //임시 반환값
}


//버킷 구현부
//수정