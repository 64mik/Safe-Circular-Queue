#include "CircularQueue.h" // CircularQueue 클래스를 사용하기 위해 필요
#include "Bucket.h"        // 기존 코드의 Bucket 클래스를 사용하기 위해 필요
#include "QueueBucketConnector.h" // QueueBucketConnector 클래스를 사용하기 위해 필요
#include "Visualizer.h"
#include <iostream>
#include <windows.h>
#include <cstdlib>         // exit() 함수를 위해

int main() {
    int input, output;
    const int QUEUE_SIZE = 10;
    std::string msg="";
    CircularQueue q(QUEUE_SIZE);
    Visualizer v(QUEUE_SIZE, 0,1);
    //Bucket b;
    //QueueBucketConnector qb(QUEUE_SIZE);
    Sleep(2000);
    for (int i = 0; i < QUEUE_SIZE/2+1; i++) {
        input = i * 10;
        q.enqueue(input);
        v.update(q.getFront(), q.getRear());
        v.render();
        Sleep(500);
    }
    for (int i = 0; i < 3; i++) {
        input = i * 10;
        q.dequeue(output);
        v.update(q.getFront(), q.getRear());
        v.render();
        Sleep(500);
    }
    return 0;
}