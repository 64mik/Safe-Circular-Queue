#ifndef BUCKET_H
#define BUCKET_H

#include <vector>

class Bucket {
public:
    Bucket();
    ~Bucket();

    void add(int& input);  // 데이터 추가
    void get(int& output); // front 데이터 조회(삭제X)

    // 🔽 추가 기능들
    void removeFront();    // pop 기능
    int size();            // 현재 크기 반환
    bool isEmpty();        // 비어있는가?

private:
    std::vector<int> data;
    int front = 0;
    int rear = 0;
    int current_size = 0;
};

#endif
