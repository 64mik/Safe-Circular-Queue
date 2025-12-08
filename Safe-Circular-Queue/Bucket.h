#ifndef BUCKET_H
#define BUCKET_H

#include <vector>

class Bucket {
public:
    Bucket();
    ~Bucket();

    void add(int& input);  
    void get(int& output); 

    void removeFront();    // pop 기능
    int size();            // 저장된 데이터 개수 반환
    bool isEmpty();        // 버킷이 비어있는지 확인

private:
    std::vector<int> data;
    int front = 0;
    int rear = 0;
    int current_size = 0;
};

#endif
