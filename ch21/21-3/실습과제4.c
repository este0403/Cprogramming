// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 10월 29일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

// my_strcat 선언: src 문자열을 dest 문자열 뒤에 이어 붙이고 dest의 주소를 반환
char* my_strcat(char* dest, const char* src);

int main(void)
{
    char str1[20] = "First~";
    char str2[20] = "Second";

    my_strcat(str1, str2);
    puts(str1);
    return 0;
}

// my_strcat 정의
char* my_strcat(char* dest, const char* src)
{
    int i = 0;      // dest의 위치
    int j = 0;      // src의 위치

    // 1단계: dest의 널문자 위치(이어 붙일 시작 위치)를 찾는다.
    while (dest[i] != '\0')
        i++;

    // 2단계: src의 문자를 널문자를 만날 때까지 dest 뒤에 하나씩 복사한다.
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';   // 문자열의 마지막에 널문자를 추가로 저장

    return dest;
}
