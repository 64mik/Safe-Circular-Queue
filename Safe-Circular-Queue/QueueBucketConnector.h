#ifndef QUEUE_BUCKET_CONNECTOR_H
#define QUEUE_BUCKET_CONNECTOR_H

#include "CircularQueue.h"
#include "Bucket.h"

class QueueBucketConnector {
public:
    QueueBucketConnector(int size);
    ~QueueBucketConnector();

    bool enqueue(int value);      // 큐에 값 삽입, 가득 차면 버킷에 저장
    bool dequeue(int& output);    // 큐에서 값 삭제,비어 있으면 버킷에서 값 가져와 복구

    void showStatus();            // 상태 출력

private:
    CircularQueue* q;     
    Bucket* b;             

    void recoverFromBucket();     // 버킷 → 큐 데이터 이동 함수
};

#endif

