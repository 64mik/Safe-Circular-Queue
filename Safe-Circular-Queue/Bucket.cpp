#include "Bucket.h"
#include <iostream>
#include <stdexcept>
#include <vector>

Bucket::Bucket() {
    std::cout << "Bucket 생성자 호출\n";
}

Bucket::~Bucket() {
    std::cout << "Bucket 소멸자 호출\n";
}

void Bucket::add(int& value) {   // 데이터 추가
    data.push_back(value);
    rear++;
    current_size++;
    std::cout << "add: " << value << " | rear: " << rear << '\n';
}

void Bucket::get(int& output) {  // 데이터 조회
    if (current_size > 0) {
        output = data.at(front);
        std::cout << "get: " << output << " | front: " << front << '\n';
    }
    else {
        std::cerr << "error: underflow (데이터 없음)\n";
    }
}


// Queue 방식 pop
void Bucket::removeFront() {
    if (current_size > 0) {
        int removed = data.at(front);
        front++;
        current_size--;
        std::cout << "removeFront: " << removed
            << " | front: " << front << '\n';
    }
    else {
        std::cerr << "error: underflow (삭제할 데이터 없음)\n";
    }
}

// 현재 저장된 데이터 수
int Bucket::size() {
    return current_size;
}

// 비었는지 확인
bool Bucket::isEmpty() {
    return (current_size == 0);
}

