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
        // ... (front/rear 출력) ...
    }
    cout << "큐의 동적 용량: " << q.getCapacity() << endl; // 💡 capacity 출력 추가
    cout << "---------------------\n" << endl;
}

int main() {
    // ----------------------------------------------------
    // A. 기존 Bucket 테스트 코드 (주석 처리됨)
    // ----------------------------------------------------
    // std::cout << "--- 기존 Bucket 테스트 시작 ---" << std::endl;
    // Bucket b;
    // for (int i = 0; i < 5; i++) {
    //     b.add(10);
    //     std::cout << "Bucket B.test: " << b.test << '\n';
    // }
    // std::cout << "--- 기존 Bucket 테스트 종료 ---\n" << std::endl;

    // ----------------------------------------------------
    // B. 원형 큐 테스트 코드 (모든 스텝 순차 실행)
    // ----------------------------------------------------
    // MAX_SIZE는 CircularQueue.h에 정의되어 있어야 합니다.
    const int QUEUE_SIZE = 5;
    cout << "=== 원형 큐 (MAX_SIZE: " << QUEUE_SIZE << ") 테스트 시작 ===" << endl;
    CircularQueue myQueue(QUEUE_SIZE); // 💡 생성자 매개변수로 크기 전달

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

    // 5. 오버플로우 테스트
    // 💡 CircularQueue.cpp에서 exit()를 제거했으므로 프로그램이 종료되지 않고 메시지만 출력
    cout << "\n[Step 5: 오버플로우 테스트]" << endl;
    myQueue.enqueue(70);
    printStatus(myQueue);

    // 6. 모두 삭제 테스트 (단일 요소 삭제 후 front=-1, rear=-1 리셋 확인)
    cout << "\n[Step 6: 큐 모두 삭제 및 리셋 확인]" << endl;
    myQueue.dequeue(); // 20
    myQueue.dequeue(); // 30
    myQueue.dequeue(); // 40
    myQueue.dequeue(); // 50
    myQueue.dequeue(); // 60 (리셋됨)
    myQueue.dequeue(); // 70 (이전 Step 5에서 추가된 경우, 여기서는 오류 메시지 출력 후 반환)
    printStatus(myQueue);

    // 7. 언더플로우 테스트
    // 💡 CircularQueue.cpp에서 exit()를 제거했으므로 프로그램이 종료되지 않고 메시지만 출력
    cout << "\n[Step 7: 언더플로우 테스트]" << endl;
    myQueue.dequeue();
    printStatus(myQueue);

    return 0;
}