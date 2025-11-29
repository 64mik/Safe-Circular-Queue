#include "CircularQueue.h"
#include <iostream>
#include <cstdlib>

// ----------------------------------------------------
// 1. 생성자 정의 (매개변수 사용)
// ----------------------------------------------------
CircularQueue::CircularQueue(int max_size) {
    if (max_size <= 0) {
        std::cerr << "🚨 오류: 큐 크기는 양수여야 합니다." << std::endl;
        exit(EXIT_FAILURE);
    }
    // 💡 동적 메모리 할당
    items = new int[max_size];
    capacity = max_size; // 큐의 최대 크기 설정
    front = -1;
    rear = -1;
    std::cout << "✅ 큐 생성 완료. 최대 크기: " << capacity << std::endl;
}

// ----------------------------------------------------
// 2. 소멸자 정의 (메모리 해제)
// ----------------------------------------------------
CircularQueue::~CircularQueue() {
    // 💡 동적 메모리 해제
    delete[] items;
    std::cout << "✅ 큐 메모리 해제 완료." << std::endl;
}

// ----------------------------------------------------
// 3. 상태 및 오류 처리 함수 정의 (MAX_SIZE 대신 capacity 사용)
// ----------------------------------------------------

bool CircularQueue::isFull() {
    // MAX_SIZE 대신 capacity 사용
    return (rear + 1) % capacity == front;
}

bool CircularQueue::isEmpty() {
    return front == -1;
}

void CircularQueue::overflowError() {
    std::cerr << "\n🚨 [ERROR] 큐가 가득 찼습니다 (Overflow). 프로그램을 강제 종료합니다." << std::endl;
    exit(EXIT_FAILURE);
}

void CircularQueue::underflowError() {
    std::cerr << "\n🚨 [ERROR] 큐가 비어 있습니다 (Underflow). 더 이상 삭제할 수 없습니다. 프로그램을 강제 종료합니다." << std::endl;
    exit(EXIT_FAILURE);
}

// ----------------------------------------------------
// 4. 삽입 (Enqueue) 함수 정의 (capacity 사용)
// ----------------------------------------------------
void CircularQueue::enqueue(int element) {
    if (isFull()) {
        overflowError();
    }

    if (isEmpty()) {
        front = 0;
    }

    // rear 포인터를 모듈러 연산으로 증가 (capacity 사용)
    rear = (rear + 1) % capacity;

    items[rear] = element;
    std::cout << "➕ 삽입: " << element << " (front: " << front << ", rear: " << rear << ")" << std::endl;
}

// ----------------------------------------------------
// 5. 삭제 (Dequeue) 함수 정의 (capacity 사용)
// ----------------------------------------------------
int CircularQueue::dequeue() {
    if (isEmpty()) {
        underflowError();
        return -1;
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

    std::cout << "➖ 삭제: " << element << " (front: " << front << ", rear: " << rear << ")" << std::endl;
    return element;
}

// ----------------------------------------------------
// 6. 디버깅 및 확인 함수 정의
// ----------------------------------------------------
int CircularQueue::getFront() {
    return front;
}

int CircularQueue::getRear() {
    return rear;
}

int CircularQueue::getCapacity() {
    return capacity;
}