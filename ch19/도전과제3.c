// **********************************************
// 제 목 : 도전과제3
// 날 짜 : 2026년 10월 8일
// 작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>   // rand 함수, RAND_MAX 상수가 선언된 헤더

int main(void)
{
    int i;

    // rand 함수는 0 이상 RAND_MAX 이하의 난수를 반환한다.
    printf("rand 함수의 난수 범위: 0부터 %d까지\n", RAND_MAX);

    // % 연산자를 이용해 난수를 0 이상 99 이하로 제한한다.
    // (어떤 수를 100으로 나눈 나머지는 항상 0~99이므로)
    printf("0 이상 99 이하의 난수 5개\n");
    for (i = 0; i < 5; i++)
        printf("난수 출력: %d \n", rand() % 100);

    // 참고: srand 함수로 씨앗(seed)을 바꾸지 않으면 실행할 때마다 같은 난수가 나온다.

    return 0;
}
