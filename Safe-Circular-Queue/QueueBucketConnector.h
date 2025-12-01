#ifndef QUEUE_BUCKET_CONNECTOR_H
#define QUEUE_BUCKET_CONNECTOR_H

#include "CircularQueue.h"
#include "Bucket.h"

class QueueBucketConnector {
public:
    QueueBucketConnector(int size);
    ~QueueBucketConnector();

    bool enqueue(int value);      // 큐에 삽입
    bool dequeue(int& output);    // 큐에서 삭제 (필요 시 버킷에서 회수)

    void showStatus();            // 상태 출력

private:
    CircularQueue* q;   // 원형 큐
    Bucket* b;          // vector 기반 버킷
};

#endif
