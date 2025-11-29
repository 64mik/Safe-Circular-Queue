#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>
#include <cstdlib>
#include <string>
// MAX_SIZE 상수를 제거합니다.

class CircularQueue {
private:
    int* items;      // 큐 요소를 저장할 동적 배열 포인터
    int capacity;    // 큐의 최대 크기 (MAX_SIZE 역할)
    int front;
    int rear;
	std::string status = "normal"; // 큐 상태 변수 추가
    // 내부 상태 확인 함수
    bool isFull();
    bool isEmpty();

    // 오류 처리 함수
    void overflowError();
    void underflowError();

public:

    CircularQueue(int max_size=5);
    ~CircularQueue();

    // 주요 큐 연산
    bool enqueue(int& element);
    bool dequeue(int& output);

    // 상태 확인 및 접근
    int getFront();
    int getRear();
    int getCapacity(); // 큐의 크기 반환
};

#endif // CIRCULAR_QUEUE_H