#include "CircularQueue.h"
#include "Visualizer.h"
#include <iostream>
#include <cstdlib>
#include <string>


int main() {
    // 1. 큐 크기 설정 (Overflow를 확인하기 위해 배열 크기보다 작게 설정)
    const int QUEUE_CAPACITY = 100;
    CircularQueue myQueue(QUEUE_CAPACITY);

    // 2. 0~1000까지 값을 가지는 배열 생성 및 초기화
    const int ARRAY_SIZE = 1001;
    int data_array[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        data_array[i] = i; // 인덱스만큼 값 배정
    }

    Visualizer::getInstance().print("\n--- 배열 순회 및 큐 작업 시작 (0 ~ 1000) ---");

    // 3. 배열 순회하며 삽입/삭제 결정
    int output;
    for (int i = 0; i < ARRAY_SIZE; ++i) {

        std::cout << "\n--- 인덱스: " << i << " (값: " << data_array[i] << ") 처리 ---" << std::endl;

        if (i % 2 == 0) { // 인덱스가 짝수일 때: 삽입 (enqueue)
            Visualizer::getInstance().print("조건: 인덱스 " + std::to_string(i) + "는 짝수 -> 삽입 시도");
            int element_to_enqueue = data_array[i];
            myQueue.enqueue(element_to_enqueue);
        }
        else { // 인덱스가 홀수일 때: 삭제 (dequeue)
            Visualizer::getInstance().print("조건: 인덱스 " + std::to_string(i) + "는 홀수 -> 삭제 시도");
            myQueue.dequeue(output);
        }

        // 큐의 상태를 간략하게 출력
        Visualizer::getInstance().print("현재 front: " + std::to_string(myQueue.getFront()) +
            ", rear: " + std::to_string(myQueue.getRear()) +
            ", Capacity: " + std::to_string(myQueue.getCapacity()));
    }

    Visualizer::getInstance().print("\n--- 모든 배열 요소 처리 완료 ---");

    // 프로그램 종료
    return 0;
}