#ifndef QUEUE_BUCKET_CONNECTOR_H
#define QUEUE_BUCKET_CONNECTOR_H

#include "CircularQueue.h"
#include "Bucket.h"

class QueueBucketConnector{
public:
    QueueBucketConnector(CircularQueue* queue, Bucket* bucket, int x = 0, int y = 0);
    ~QueueBucketConnector();

    bool enqueue(int& input);      // 큐에 값 삽입, 가득 차면 버킷에 저장
    bool dequeue(int& output);    // 큐에서 값 삭제,비어 있으면 버킷에서 값 가져와 복구
    void showStatus();            // 상태 출력
    int getFront();
    int getRear(); 
    int getSize();
    void bucketToQueue();
private:
    CircularQueue* q;     
    Bucket* b;             
    int printX = 0;
    int printY = 0; 
};

#endif

