#include "Bucket.h"
#include <iostream>
#include <vector>
#include <stdexcept>

Bucket::Bucket() {               // 생성자: 벡터 자동 초기화
    test = 0;
}

Bucket::~Bucket() {             // 소멸자: 모든 동적 할당 메모리 해제
    for (int* ptr : data) {
        delete ptr;
    }
    data.clear();
}

void Bucket::add(int value) {             // 데이터 추가
    int* ptr = new int(value);
    data.push_back(ptr);
    test += value;
}

int Bucket::get(int index) const {               // 데이터 조회
    if (index >= static_cast<int>(data.size()) || data[index] == nullptr) {
		throw std::out_of_range("Index out of range or null pointer");
    }
    return *(data[index]);
}

int Bucket::size() const {                           // 버킷 크기 반환
    return static_cast<int>(data.size());
}