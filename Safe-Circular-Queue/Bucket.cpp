#include "Bucket.h"
#include "Visualizer.h"
#include <iostream>
#include <stdexcept>
#include <vector>

Bucket::Bucket() {
}

Bucket::~Bucket() {
}

bool Bucket::add(int& value) {
    if (isEmpty()) {
        front = 0;
        rear = 0;
    }
    rear++;
    data.push_back(value);
    return true;
}

bool Bucket::pop(int& output) {  // 데이터 조회
    if (data.empty()) {
        Visualizer::getInstance().printErr("Bucket is empty");
        front = -1;
        rear = -1;
        return false;
    }
    output = data.front();
    data.erase(data.begin());
    front++;
    if (front == rear) {
        front = -1;
        rear = -1;   
    }
    return true;
}
int Bucket::getFront() {
    return front;
}
int Bucket::getRear() {
    return rear;
}

// 현재 저장된 데이터 수
int Bucket::getSize() {
    return rear - front - 1;
}

// 비었는지 확인
bool Bucket::isEmpty() {
    return front == -1;
}

