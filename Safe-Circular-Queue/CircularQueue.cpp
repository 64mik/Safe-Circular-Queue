#include "CircularQueue.h"
#include <iostream>
#include <cstdlib>

CircularQueue::CircularQueue(int max_size) {
    if (max_size <= 0) {
        std::cerr << "오류: 큐 크기는 양수여야 합니다." << std::endl;
        exit(EXIT_FAILURE);
    }
    // 동적 메모리 할당
    items = new int[max_size];
    capacity = max_size; // 큐의 최대 크기 설정
    front = -1;
    rear = -1;
    std::cout << "큐 생성 완료. 최대 크기: " << capacity << std::endl;
}
CircularQueue::~CircularQueue() {
    delete[] items;
    std::cout << "큐 메모리 해제 완료." << std::endl;
}

bool CircularQueue::isFull() {
    // MAX_SIZE 대신 capacity 사용
    return (rear + 1) % capacity == front;
}

bool CircularQueue::isEmpty() {
    return front == -1;
}

void CircularQueue::overflowError() {
    std::cerr << "\n[ERROR] (Overflow) 큐가 가득 찼습니다." << std::endl;
    //exit(EXIT_FAILURE);
}

void CircularQueue::underflowError() {
    std::cerr << "\n[ERROR] (Underflow) 큐가 비어 있습니다." << std::endl;
    //exit(EXIT_FAILURE);
}

bool CircularQueue::enqueue(int& element) {
    if (isFull()) {
        overflowError();
		status = "overflow";
		return false;
    }

    if (isEmpty()) {
        front = 0;
    }

    // rear 포인터를 모듈러 연산으로 증가
    rear = (rear + 1) % capacity;

    items[rear] = element;
    std::cout << "삽입: " << element << " (front: " << front << ", rear: " << rear << ")" << std::endl;
	return true;
}

bool CircularQueue::dequeue(int& output) {
    if (isEmpty()) {
        underflowError();
		status = "underflow";
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

    std::cout << "삭제: " << element << " (front: " << front << ", rear: " << rear << ")" << std::endl;
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