#include "Bucket.h"
#include <iostream>
#include <stdexcept>
#include <vector>
Bucket::Bucket() {       // 생성자
}
Bucket::~Bucket() {              // 소멸자
}
void Bucket::add(int& value) {           // 데이터 추가
    data.push_back(value);
    rear++;
    current_size++;
    std::cout <<"add:" << value << " |  rear:" << rear << '\n';
}

void Bucket::get(int& index) {          // 데이터 조회
    if (current_size) {
        index = data.at(front);
        front++;
        current_size--;
        std::cout <<"get:" << index << " |  front:" << front << '\n';
    }
    else {
        std::cerr << "\nerror: underflow\n";
    }
}