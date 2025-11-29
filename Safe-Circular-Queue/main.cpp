// main.cpp

#include "CircularQueue.h" // CircularQueue 클래스를 사용하기 위해 필요
#include "bucket.h"        // 기존 코드의 Bucket 클래스를 사용하기 위해 필요
#include <iostream>
#include <cstdlib>         // exit() 함수를 위해

using namespace std;

// 💡 큐의 현재 상태를 출력하는 함수
void printStatus(CircularQueue& q) {
    cout << "\n--- 현재 큐 상태 ---" << endl;
    if (q.getFront() == -1) {
        cout << "큐가 비어 있습니다." << endl;
    }
    else {
        // front와 rear 인덱스 출력
        cout << "Front Index: " << q.getFront() << endl;
        cout << "Rear Index: " << q.getRear() << endl;
    }
    cout << "---------------------\n" << endl;
}

int main() {
    // ----------------------------------------------------
    // A. 기존 Bucket 테스트 코드 (유지)
    // ----------------------------------------------------
    //std::cout << "--- 기존 Bucket 테스트 시작 ---" << std::endl;
    //// 💡 강조 시작: 이 부분이 기존 Bucket 테스트 코드입니다.
    //Bucket b;
    //for (int i = 0; i < 5; i++) {
    //    b.add(10);
    //    std::cout << "Bucket B.test: " << b.test << '\n';
    //}
    //// 💡 강조 끝
    //std::cout << "--- 기존 Bucket 테스트 종료 ---\n" << std::endl;

    // ----------------------------------------------------
    // B. 원형 큐 테스트 코드 
    // ----------------------------------------------------
    cout << "=== 원형 큐 (MAX_SIZE: " << MAX_SIZE << ") 테스트 시작 ===" << endl;
    CircularQueue myQueue;

    // 1. 삽입 테스트 (3개)
    cout << "\n[Step 1: 3개 삽입]" << endl;
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);
    printStatus(myQueue);

    // 2. 삭제 테스트 (1개)
    cout << "\n[Step 2: 1개 삭제 및 랩어라운드 공간 확보]" << endl;
    myQueue.dequeue();
    printStatus(myQueue);

    // 3. 재삽입 테스트 (2개) - Rear 랩어라운드 발생 가능
    cout << "\n[Step 3: 2개 재삽입]" << endl;
    myQueue.enqueue(40);
    myQueue.enqueue(50);
    printStatus(myQueue);

    // 4. 큐 가득 채우기 테스트 (1개 더 삽입)
    cout << "\n[Step 4: 큐 가득 채우기 (MAX_SIZE-1개)]" << endl;
    myQueue.enqueue(60);
    printStatus(myQueue);

    // 5. 오버플로우 테스트 (강제 종료 확인)
    cout << "\n[Step 5: 오버플로우 테스트 (강제 종료 예상)]" << endl;
     myQueue.enqueue(70); // 이 코드를 실행하면 오버플로우 오류로 프로그램이 종료됩니다.

    // 6. 모두 삭제 테스트 (단일 요소 삭제 후 front=-1, rear=-1 리셋 확인)
    cout << "\n[Step 6: 큐 모두 삭제 및 리셋 확인]" << endl;
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue(); // 💡 여기서 front == rear가 되며 큐가 리셋됩니다.
    printStatus(myQueue);

    // 7. 언더플로우 테스트 (강제 종료 확인)
    cout << "\n[Step 7: 언더플로우 테스트 (강제 종료 예상)]" << endl;
     myQueue.dequeue(); // 이 코드를 실행하면 언더플로우 오류로 프로그램이 종료됩니다.

    return 0;
}