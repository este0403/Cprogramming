// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 10월 6일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 함수선언
// 문자열 포인터 배열(char* ptrarr[])의 배열명은 첫 번째 원소(char*)의 주소이므로 char** 형이다.
// 따라서 문자열 포인터 배열을 받는 매개변수는 이중 포인터(char**)로 선언한다.
void prn_str(char** dptr, int n);

int main(void)
{
    char* ptrarr[] = { "eagle", "tiger", "lion", "squirrel" };   // 문자열 리터럴의 시작 주소를 저장한 포인터 배열
    int count;

    count = sizeof(ptrarr) / sizeof(ptrarr[0]);   // 배열 전체 크기 / 원소 1개 크기 = 원소 개수(4)
    prn_str(ptrarr, count);                       // 포인터 배열명(char**)과 원소 개수 전달

    return 0;
}

// 함수정의
// 문자열 포인터 배열의 모든 문자열을 한 줄에 하나씩 출력하는 함수
void prn_str(char** dptr, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%s\n", dptr[i]);   // dptr[i]는 i번째 문자열의 시작 주소(char*)이므로 %s로 바로 출력
    }
}
