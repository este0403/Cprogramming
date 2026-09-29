// **********************************************
// 제 목 : 실습과제3
// 날 짜 : 2026년 9월 22일
// 작성자 : 2600152 이준영
// **********************************************
#include <stdio.h>

// 이번에는 주소를 넘기지 않고, 값에 의한 호출을 그대로 사용하되
// 함수 안에서 2 증가시킨 "결과값"을 return으로 돌려주고
// main함수에서 그 리턴값을 받아서 number에 다시 저장하는 방식
int add2(int value);   // 함수 선언 (원형)

int main(void)
{
    int number;

    printf("정수를 입력하세요:");
    scanf("%d", &number);

    number = add2(number);   // 함수 호출 + 리턴값을 number에 대입

    printf("2만큼 증가한 값:%d\n", number);

    return 0;
}

// 함수 정의 : 매개변수 value는 number의 값을 복사받은 지역변수
int add2(int value)
{
    value += 2;   // 이 지역변수 value만 증가함 (호출측 number는 안변함)
    return value; // 증가된 값을 호출한 쪽(main)으로 돌려줌
}

/* 실행결과
정수를 입력하세요:15
2만큼 증가한 값:17
*/
