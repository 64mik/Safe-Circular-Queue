#ifndef BUCKET_H
#define BUCKET_H

#include <vector>

class Bucket {
public:
    Bucket();
    ~Bucket();

    bool add(int& input);  
    bool pop(int& output); 
    int getFront();
    int getRear();
    int getSize();
    bool isEmpty();        // 버킷이 비어있는지 확인

private:
    std::vector<int> data;
    int front = -1;
    int rear = -1;
};

#endif
