// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 10월 8일
// 작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

/* ---------------------------------------------------------
   [예제 A] 함수의 매개변수에 함수 포인터를 활용하는 예제
   - 배열의 모든 원소에 "어떤 함수"를 적용해 출력한다.
   - 어떤 함수를 적용할지는 호출하는 쪽에서 함수명(함수의 주소)으로 정한다.
   - 반복문 등 공통 코드는 apply_and_print 한 곳에만 있고,
     바뀌는 부분(제곱, 두 배)만 별도 함수로 분리했다.
   --------------------------------------------------------- */
int square(int x);   // 제곱을 반환하는 함수 (자료형: int(int))
int twice(int x);    // 두 배를 반환하는 함수 (자료형: int(int))

// 세 번째 매개변수 f는 "int를 받아 int를 반환하는 함수"의 주소를 저장하는 함수 포인터
void apply_and_print(const int* arr, int n, int (*f)(int))
{
    for (int i = 0; i < n; i++)
        printf("%d ", f(arr[i]));   // 함수 포인터로 함수 호출 (전달받은 함수가 실행됨)
    printf("\n");
}

int square(int x) { return x * x; }
int twice(int x) { return x * 2; }

/* ---------------------------------------------------------
   [예제 B] 함수의 매개변수에 void 포인터를 활용하는 예제
   - void*는 모든 자료형의 주소를 받을 수 있으므로
     int, double 등 자료형에 상관없이 동작하는 swap 함수를 하나만 만들 수 있다.
   - void*는 간접참조(*)가 불가능하므로, 값을 바이트 단위로 복사하는
     memcpy를 사용하고 자료형의 크기(size)를 함께 전달한다.
   --------------------------------------------------------- */
void swap_any(void* a, void* b, size_t size)
{
    char tmp[16];                  // 임시 저장 공간 (최대 16바이트 자료형까지 가능)
    memcpy(tmp, a, size);          // a가 가리키는 값을 tmp에 복사
    memcpy(a, b, size);            // b가 가리키는 값을 a 위치에 복사
    memcpy(b, tmp, size);          // tmp의 값을 b 위치에 복사
}

int main(void)
{
    // ----- 예제 A 실행 -----
    int arr[5] = { 1, 2, 3, 4, 5 };
    printf("[함수 포인터 매개변수]\n");
    printf("제곱 : ");
    apply_and_print(arr, 5, square);   // 함수명 square를 인자로 전달
    printf("두 배 : ");
    apply_and_print(arr, 5, twice);    // 함수명 twice를 인자로 전달

    // ----- 예제 B 실행 -----
    int x = 10, y = 20;
    double p = 1.5, q = 2.5;
    printf("\n[void 포인터 매개변수]\n");
    printf("교환 전 : x=%d, y=%d / p=%.1f, q=%.1f\n", x, y, p, q);
    swap_any(&x, &y, sizeof(int));        // int형 두 변수의 주소와 크기 전달
    swap_any(&p, &q, sizeof(double));     // double형 두 변수의 주소와 크기 전달
    printf("교환 후 : x=%d, y=%d / p=%.1f, q=%.1f\n", x, y, p, q);

    return 0;
}
