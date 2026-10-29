// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 10월 29일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

// my_strlen 선언: 널문자를 만날 때까지 문자의 개수를 세어 반환하는 함수
int my_strlen(const char* str);
// RemoveBSN 선언: 문자열 끝의 '\n'을 '\0'으로 바꾸는 함수 (예제1과 동일)
void RemoveBSN(char str[]);

int main(void)
{
    char str[100];

    printf("문자열 입력: ");
    fgets(str, sizeof(str), stdin);
    printf("길이: %d, 내용: %s \n", my_strlen(str), str);   // '\n'이 포함되어 길이 13

    RemoveBSN(str);
    printf("길이: %d, 내용: %s \n", my_strlen(str), str);   // '\n' 제거 후 길이 12
    return 0;
}

// my_strlen 정의
// 포인터를 한 칸씩 이동하며 '\0'이 나올 때까지 개수를 센다. 널문자는 길이에 포함하지 않는다.
int my_strlen(const char* str)
{
    int count = 0;

    while (str[count] != '\0')   // 널문자를 만나면 반복 종료
        count++;

    return count;
}

// RemoveBSN 정의
// 마지막 문자('\n')를 '\0'으로 덮어써서 문자열을 한 글자 줄인다.
void RemoveBSN(char str[])
{
    int len = my_strlen(str);
    str[len - 1] = '\0';
}
