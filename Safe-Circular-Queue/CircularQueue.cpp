#include "CircularQueue.h"
#include "Visualizer.h"
#include <iostream>
#include <cstdlib>
#include <string> // std::to_string 사용을 위해 추가


CircularQueue::CircularQueue(int max_size) {
    if (max_size <= 0) {
        Visualizer::getInstance().printErr("오류: 큐 크기는 양수여야 합니다.");
        exit(EXIT_FAILURE);
    }
    // 동적 메모리 할당
    items = new int[max_size];
    capacity = max_size; // 큐의 최대 크기 설정
    front = -1;
    rear = -1;
    Visualizer::getInstance().print("큐 생성 완료. 최대 크기: " + std::to_string(capacity));
}

CircularQueue::~CircularQueue() {
    delete[] items;
    Visualizer::getInstance().print("큐 메모리 해제 완료.");
}

bool CircularQueue::isFull() {
    // MAX_SIZE 대신 capacity 사용
    return (rear + 1) % capacity == front;
}

bool CircularQueue::isEmpty() {
    return front == -1;
}

void CircularQueue::overflowError() {
    Visualizer::getInstance().printErr("(Overflow) 큐가 가득 찼습니다.");
}

void CircularQueue::underflowError() {
    Visualizer::getInstance().printErr("(Underflow) 큐가 비어 있습니다. //큐 포인터 초기화");
}

bool CircularQueue::enqueue(int& element) {
    if (isFull()) {
        overflowError();
        // status = "overflow"; // status 멤버 변수가 없으므로 주석 처리
        return false;
    }

    if (isEmpty()) {
        front = 0;
    }

    // rear 포인터를 모듈러 연산으로 증가
    rear = (rear + 1) % capacity;
    items[rear] = element;
    std::string msg = "삽입: " + std::to_string(element) + " (front: " + std::to_string(front) + ", rear: " + std::to_string(rear) + ")";
    Visualizer::getInstance().print(msg);
    return true;
}

bool CircularQueue::dequeue(int& output) {
    if (isEmpty()) {
        underflowError();
        // status = "underflow"; // status 멤버 변수가 없으므로 주석 처리
        return false;
    }

    int element = items[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        // front 포인터를 모듈러 연산으로 증가 (capacity 사용)
        front = (front + 1) % capacity;
    }
    std::string msg = "삭제: " + std::to_string(element) + " (front: " + std::to_string(front) + ", rear: " + std::to_string(rear) + ")";
    Visualizer::getInstance().print(msg);
    output = element;
    return true;
}

// 디버깅 함수 구현
int CircularQueue::getFront() {
    return front;
}

int CircularQueue::getRear() {
    return rear;
}

int CircularQueue::getCapacity() {
    return capacity;
}