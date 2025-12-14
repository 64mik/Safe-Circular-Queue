#include "CircularQueue.h"
#include "Visualizer.h"
#include "QueueBucketConnector.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>

static void tempPrintStatus(Visualizer& v, Visualizer& v_b, CircularQueue* q, Bucket* b, int printX, int printY) {
    v.print("(queue) 현재  front: " + std::to_string(q->getFront()) +
        ", rear: " + std::to_string(q->getRear()) +
        ", size(0 ~ n-1): " + std::to_string(q->getSize()) + "    ", printX, printY);
    v.print("(bucket) 현재 front: " + std::to_string(b->getFront()) +
        ", rear: " + std::to_string(b->getRear()) +
        ", size(0 ~ n-1): " + std::to_string(b->getSize()) + "    ", printX, printY + 1);
    v.update(q->getFront(), q->getRear());
    v.render();
    v_b.update(b->getFront(), b->getRear());
    v_b.render();
}

int main() {
    const int ARRAY_SIZE = 701;
    const int QUEUE_CAPACITY = 100;
    int data_array[ARRAY_SIZE];

    int printX = 0;
    int printY = 0;
    int queueX = 0;
    int queueY = 4;
    int input = 0;
    int output = 0;


    CircularQueue* q =new CircularQueue(QUEUE_CAPACITY);
    Bucket* b = new Bucket();
    QueueBucketConnector myQueue(q, b,0,7);
    Visualizer v(QUEUE_CAPACITY, queueX, queueY);       //큐 출력
    Visualizer v_b(QUEUE_CAPACITY, queueX, queueY+2);   //백터 출력
    
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        data_array[i] = i;
    }

    for (int i = 0; i < ARRAY_SIZE; ++i) {

        v.print("--- 인덱스: " + std::to_string(i) + " (값: " + std::to_string(data_array[i]) + ") 처리 ---", printX, printY+3);

		if (!(i % 8 == 0)) { //i값이 나누어 떨어지지 않으면 삽입
            input = data_array[i];
            myQueue.enqueue(input);   
        }
        else 
            myQueue.dequeue(output);
        tempPrintStatus(v, v_b, q, b, printX, printY);
    }

    Visualizer::getInstance().print("\n--- 모든 배열 요소 처리 완료 ---", printX, printY + 2);
    while (myQueue.dequeue(output)) {
        tempPrintStatus(v, v_b, q, b, printX, printY);
    }
}