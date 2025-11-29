#include "Bucket.h"
#include <iostream>
#include <stdexcept>

Bucket::Bucket() : front(0), rear(0), current_size(0), test(0) {       // 생성자
    data[0] = nullptr;
    data[1] = nullptr;
}

Bucket::~Bucket() {              // 소멸자
    if (data[0]) delete data[0];
    if (data[1]) delete data[1];
}

void Bucket::add(int value) {           // 데이터 추가
    if (current_size == 2) {
        int old_value = *(data[front]);
        delete data[front];
        data[front] = nullptr;
        test -= old_value;
        front = (front + 1) % 2;
        current_size--;
    }

    data[rear] = new int(value);
    test += value;
    rear = (rear + 1) % 2;
    current_size++;
}

int Bucket::get(int index) const {          // 데이터 조회
    if (index >= current_size || index < 0) {
        throw std::out_of_range("Index out of range");
    }
    int pos = (front + index) % 2;
    if (data[pos] == nullptr) {
        throw std::out_of_range("Null pointer at position");
    }
    return *(data[pos]);
}

int Bucket::size() const {            // 버킷 크기 반환
    return current_size;
}
