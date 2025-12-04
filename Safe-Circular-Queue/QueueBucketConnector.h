#ifndef QUEUE_BUCKET_CONNECTOR_H
#define QUEUE_BUCKET_CONNECTOR_H

#include "CircularQueue.h"
#include "Bucket.h"

class QueueBucketConnector {
public:
    QueueBucketConnector(int size);
    ~QueueBucketConnector();

    bool enqueue(int value);      // 큐 삽입
    bool dequeue(int& output);    // 큐 삭제 & 버킷 복구

    void showStatus();            // 상태 출력

private:
    CircularQueue* q;     // 원형 큐
    Bucket* b;            // 버킷 

    void recoverFromBucket();     // 버킷 → 큐 데이터 이동 함수
};

#endif

