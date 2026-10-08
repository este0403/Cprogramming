// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 10월 8일
// 작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 연산부분 함수 선언: 모두 int(int, int) 자료형이므로 같은 함수 포인터로 받을 수 있음
int add(int a, int b);   // 덧셈
int sub(int a, int b);   // 뺄셈
int mul(int a, int b);   // 곱셈
int divide(int a, int b); // 나눗셈 (정수 나눗셈의 몫)

// 공통부분 함수: 두 정수를 입력받고, 전달받은 연산 함수(fp)를 호출해 결과를 출력
void calculate(int (*fp)(int, int))
{
    int n1, n2;
    printf("두개의 정수를 입력하시오 : ");
    scanf("%d %d", &n1, &n2);
    printf("결과값: %d\n", fp(n1, n2));   // 함수 포인터로 연산 함수 호출
}

int main(void)
{
    int menu;

    printf("연산을 선택하시오(1:덧셈,2:뺄셈,3:곱셈,4:나눗셈) : ");
    scanf("%d", &menu);

    // 선택한 번호에 따라 연산 함수의 이름(주소)을 공통 함수에 전달
    switch (menu)
    {
    case 1: calculate(add); break;
    case 2: calculate(sub); break;
    case 3: calculate(mul); break;
    case 4: calculate(divide); break;
    default: printf("잘못된 선택입니다.\n"); break;
    }

    return 0;
}

// 연산부분 함수 정의
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divide(int a, int b)
{
    if (b == 0)   // 0으로 나누기 방지
    {
        printf("0으로 나눌 수 없습니다.\n");
        return 0;
    }
    return a / b;
}
