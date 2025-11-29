#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include <iostream>
#include <cstdlib> // exit() 함수를 위해

// 큐의 최대 크기 정의 (클래스 외부에 위치)
#define MAX_SIZE 5 

class CircularQueue {
private:
    int items[MAX_SIZE]; // 큐 요소를 저장할 배열
    int front;           // 큐의 첫 번째 요소 인덱스 (삭제될 요소)
    int rear;            // 큐의 마지막 요소 인덱스 (삽입될 위치)

    // 내부 상태 확인 함수
    bool isFull();
    bool isEmpty();

    // 오류 처리 함수
    void overflowError();   // 가득 찼을 때
    void underflowError();  // 비어 있을 때

public:
    // 생성자
    CircularQueue();

    // 주요 큐 연산 (삽입/삭제 - Enqueue/Dequeue, Push/Pop에 해당)
    void enqueue(int element); // 삽입 (Push)
    int dequeue();             // 삭제 (Pop)

    // 상태 확인 및 접근
    int getFront(); // front 값 반환
    int getRear();  // rear 값 반환
};

#endif // CIRCULAR_QUEUE_H