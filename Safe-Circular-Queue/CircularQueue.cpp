#include "CircularQueue.h"
#include <iostream>
#include <cstdlib> // exit() 함수

// ----------------------------------------------------
// 1. 생성자 정의
// ----------------------------------------------------
CircularQueue::CircularQueue() {
    front = -1; // front와 rear가 -1이면 비어 있는 상태
    rear = -1;
}

// ----------------------------------------------------
// 2. 상태 및 오류 처리 함수 정의
// ----------------------------------------------------

// 큐가 가득 찼는지 확인 (한 칸 비우기 전략)
bool CircularQueue::isFull() {
    // (rear + 1) % MAX_SIZE가 front와 같으면 가득 찬 것으로 간주
    return (rear + 1) % MAX_SIZE == front;
}

// 큐가 비어 있는지 확인
bool CircularQueue::isEmpty() {
    // front가 -1이면 큐가 비어 있음
    return front == -1;
}

// 오버플로우 오류 처리 (강제 종료)
void CircularQueue::overflowError() {
    std::cerr << "\n🚨 [ERROR] 큐가 가득 찼습니다 (Overflow). 프로그램을 강제 종료합니다." << std::endl;
    exit(EXIT_FAILURE);
}

// 언더플로우 오류 처리 (강제 종료)
void CircularQueue::underflowError() {
    std::cerr << "\n🚨 [ERROR] 큐가 비어 있습니다 (Underflow). 더 이상 삭제할 수 없습니다. 프로그램을 강제 종료합니다." << std::endl;
    exit(EXIT_FAILURE);
}

// ----------------------------------------------------
// 3. 삽입 (Enqueue) 함수 정의
// ----------------------------------------------------
void CircularQueue::enqueue(int element) {
    if (isFull()) {
        overflowError(); // 가득 찼으면 강제 종료
    }

    // 큐가 완전히 비어 있을 때 (초기 상태) front를 0으로 설정 (포인터 오류 방지)
    if (isEmpty()) {
        front = 0;
    }

    // rear 포인터를 모듈러 연산으로 증가 (랩어라운드 처리)
    rear = (rear + 1) % MAX_SIZE;

    items[rear] = element;
    std::cout << "➕ 삽입: " << element << " (front: " << front << ", rear: " << rear << ")" << std::endl;
}

// ----------------------------------------------------
// 4. 삭제 (Dequeue) 함수 정의
// ----------------------------------------------------
int CircularQueue::dequeue() {
    if (isEmpty()) {
        underflowError(); // 비어 있으면 강제 종료
        return -1; // 이 라인은 실행되지 않음
    }

    int element = items[front];

    // 💡 두 포인터가 겹칠 때 (큐에 요소가 하나만 남았을 때)
    if (front == rear) {
        // 마지막 요소를 삭제했으므로 큐를 초기 상태로 리셋
        front = -1;
        rear = -1;
    }
    // 요소가 여러 개 남아있을 때
    else {
        // front 포인터를 모듈러 연산으로 증가 (랩어라운드 처리)
        front = (front + 1) % MAX_SIZE;
    }

    std::cout << "➖ 삭제: " << element << " (front: " << front << ", rear: " << rear << ")" << std::endl;
    return element;
}

// ----------------------------------------------------
// 5. 디버깅 및 확인 함수 정의
// ----------------------------------------------------
int CircularQueue::getFront() {
    return front;
}

int CircularQueue::getRear() {
    return rear;
}