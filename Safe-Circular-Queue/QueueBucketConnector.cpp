#include "QueueBucketConnector.h"
#include "Visualizer.h"
#include <stdlib.h>
#include <iostream>

QueueBucketConnector::QueueBucketConnector(CircularQueue* queue, Bucket* bucket, int x, int y) {
    q = queue;
    b = bucket;
    printX = x;
    printY = y;
    if (!q || !b) {
        Visualizer::getInstance().printErr("[Error] queue 혹은 bucket에 연결하는데 실패했습니다.");
        exit(EXIT_FAILURE);
    }
}

QueueBucketConnector::~QueueBucketConnector() {
}

bool QueueBucketConnector::enqueue(int& input)
{
    if (q->enqueue(input)) {
        Visualizer::getInstance().print("[Enqueue] " + std::to_string(input), printX, printY, Visualizer::getInstance().style.filledColor);
        return true;
    }
    else {
        Visualizer::getInstance().print("[Overflow] 큐 Full → 버킷에 저장 (값:" + std::to_string(input), printX, printY + 2);
        b->add(input);
        Visualizer::getInstance().print("[Enqueue] " + std::to_string(input), printX, printY, Visualizer::getInstance().style.filledColor);
        return false;

    }
}

bool QueueBucketConnector::dequeue(int& output)
{
    if (q->dequeue(output)) {
        Visualizer::getInstance().print("[Dequeue] " + std::to_string(output) + "     ", printX, printY + 1, Visualizer::getInstance().style.emptyColor);
        if (!(b->isEmpty()))
            bucketToQueue();
        return true;
    }
    else {
        return false;
    }
}
int QueueBucketConnector::getFront(){
    return q->getFront();
}
int QueueBucketConnector::getRear(){
    return q->getRear();
}
int QueueBucketConnector::getSize(){
    return q->getSize();
}
void QueueBucketConnector::bucketToQueue() {
        int value;
        if(b->pop(value))
            q->enqueue(value);
        else {
            Visualizer::getInstance().printErr("pop?");
        }
}
