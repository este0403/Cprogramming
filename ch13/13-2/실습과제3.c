// **********************************************
// 제 목 : 실습과제3
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

    // 라이브러리 함수를 사용하지 않고 아스키코드 차이를 이용해 직접 변환
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + ('a' - 'A'); // 대문자 -> 소문자
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - ('a' - 'A'); // 소문자 -> 대문자
    }

    printf("변환결과 : %s\n", str);

    return 0;
}

/*
[실행결과]
문자열을 입력하시오:HelloWorld
변환결과 : hELLOwORLD
*/
