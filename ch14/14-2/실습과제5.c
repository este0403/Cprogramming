// **********************************************
//   제  목 : 실습과제5
//   날  짜 : 2026년 9월 29일
//   작성자 : 2600152 이준영
// **********************************************
// 교재 324페이지 문제 14-2 중 문제 2번 선택 (const 선언에 대한 추가적인 이해)
//
// [문제점 분석]
// 교재의 원래 코드는 다음과 같다.
//
//     void ShowData(const int * ptr)
//     {
//         int * rptr = ptr;     // (1) const int*를 const 없는 int*에 대입
//         printf("%d \n", *rptr);
//         *rptr = 20;           // (2) rptr로 값을 바꿀 수 있다
//     }
//
// ptr을 const int*로 선언한 것은 "이 함수는 ptr이 가리키는 값을 바꾸지 않겠다"는 약속이다.
// 그런데 (1)에서 그 주소를 const가 없는 int* 변수 rptr에 넣으면 const 정보가 사라진다.
// 그러면 (2)처럼 rptr을 통해 main 함수의 num 값을 바꿀 수 있게 되어
// const로 값을 보호하려던 의도가 깨진다. (컴파일러는 보통 에러가 아닌 경고만 낸다.)
//
// [해결 방법]
// rptr도 const int*로 선언하면 const가 끝까지 유지되고,
// 값을 바꾸려는 코드(*rptr = 20;)는 컴파일 단계에서 에러가 되어 실수를 막을 수 있다.

#include <stdio.h>

void ShowData(const int* ptr);

int main(void)
{
    int num = 10;
    int* ptr = &num;

    ShowData(ptr);
    printf("호출 후 num: %d\n", num);   // 값이 바뀌지 않고 10 그대로여야 한다.

    return 0;
}

void ShowData(const int* ptr)
{
    const int* rptr = ptr;    // 수정: rptr도 const int*로 선언하여 const를 유지
    printf("%d \n", *rptr);   // 읽기는 가능
    // *rptr = 20;            // 이 줄의 주석을 풀면 컴파일 에러가 발생한다. (값 변경 불가)
}

/* 실행 결과
10
호출 후 num: 10
*/
