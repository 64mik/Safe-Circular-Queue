#include "QueueBucketConnector.h"
#include <iostream>

using namespace std;

QueueBucketConnector::QueueBucketConnector(int size) {
    q = new CircularQueue(size);
    b = new Bucket();
}

QueueBucketConnector::~QueueBucketConnector() {
    delete q;
    delete b;
}

bool QueueBucketConnector::enqueue(int value)
{
    if (!q->enqueue(value)) {
        cout << "[Overflow] 큐 Full → 버킷에 저장 (값:" << value << ")\n";
        b->add(value);
        return false;
    }

    cout << "[Enqueue] " << value << endl;
    return true;
}

bool QueueBucketConnector::dequeue(int& output)
{
    if (q->dequeue(output)) {
        cout << "[Dequeue] " << output << endl;
        return true;
    }

    cout << "[Underflow] 큐 Empty" << endl;
    recoverFromBucket();

    if (q->dequeue(output)) {
        cout << "[Dequeue-Recovered] " << output << endl;
        return true;
    }

    cout << "큐 + 버킷 모두 비어있음\n";
    return false;
}

void QueueBucketConnector::recoverFromBucket()
{
    if (b->size() == 0) return;

    cout << "버킷 → 큐 데이터 이동" << endl;

    int value;
    b->get(value);       // 가장 앞 요소 얻기
    b->removeFront();    // vector pop-front 구현 필요
    q->enqueue(value);
}

void QueueBucketConnector::showStatus()
{
    cout << "\n==== STATUS ====\n";
    cout << "큐 front: " << q->getFront()
        << ", rear: " << q->getRear() << endl;
    cout << "버킷 크기: " << b->size() << endl;
    cout << "================\n";
}

