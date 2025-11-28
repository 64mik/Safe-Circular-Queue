#include "Bucket.h"
#include <iostream>


// 생성자
Bucket::Bucket() {
    test = 0;
}

// 소멸자
Bucket::~Bucket() {
}

// 데이터 추가
void Bucket::add(int data) {
    test += data;
}

// 데이터 조회
int Bucket::get(int index) const {
    return test;
}

// 버킷 크기
int Bucket::size() const {
    return (test == 0) ? 0 : 1;
}


//��Ŷ ������
//����