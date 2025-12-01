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
    bool ok = q->enqueue(value);

    if (!ok) {
        cout << "[Overflow] 큐가 가득 찼습니다. 버킷에 저장합니다. (값: "
            << value << ")" << endl;
        b->add(value);
        return false;
    }

    cout << "[Enqueue] 값 삽입: " << value << endl;
    return true;
}

bool QueueBucketConnector::dequeue(int& output)
{
    bool ok = q->dequeue(output);

    if (!ok) {
        cout << "[Underflow] 큐가 비어 있습니다." << endl;

        if (b->size() > 0) {
            cout << "버킷에서 데이터를 큐로 복구합니다." << endl;

            int v = b->get(0);     // vector[0]
            b->removeFront();      // 삭제 (erase)

            q->enqueue(v);
            q->dequeue(output);

            cout << "[Dequeue] 복구된 값: " << output << endl;
            return true;
        }

        cout << "큐와 버킷 모두 비어 있습니다." << endl;
        return false;
    }

    cout << "[Dequeue] 값 삭제: " << output << endl;
    return true;
}

void QueueBucketConnector::showStatus()
{
    cout << "\n=== 현재 상태 ===" << endl;

    cout << "큐 front: " << q->getFront()
        << ", rear: " << q->getRear() << endl;

    cout << "버킷 크기: " << b->size() << endl;

    cout << "=================" << endl;
}

