// **********************************************
// 제 목 : 실습과제2
// 날 짜 : 2026년 9월 17일
// 작성자 : 2600152 이준영
// **********************************************
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    char str[100];
    int i;

    printf("문자열을 입력하시오:");
    scanf("%s", str);

    // 문자열의 끝은 널문자('\0')를 만날 때까지 순회
    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%d번째문자 %c\n", i + 1, str[i]);
    }

    return 0;
}

/*
[실행결과]
문자열을 입력하시오:HelloWorld
1번째문자 H
2번째문자 e
3번째문자 l
4번째문자 l
5번째문자 o
6번째문자 W
7번째문자 o
8번째문자 r
9번째문자 l
10번째문자 d
*/
