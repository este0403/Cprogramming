// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 10월 29일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

// my_strcpy 선언: src의 문자열을 널문자까지 포함하여 dest에 복사하고 dest의 주소를 반환
char* my_strcpy(char* dest, const char* src);

int main(void)
{
    char str1[20] = "1234567890";
    char str2[20];

    my_strcpy(str2, str1);
    puts(str2);
    return 0;
}

// my_strcpy 정의
char* my_strcpy(char* dest, const char* src)
{
    int i = 0;

    // 널문자를 만날 때까지 문자를 하나씩 복사
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';   // 문자열의 마지막에 널문자를 추가로 저장 (이것이 없으면 쓰레기 값이 출력됨)

    return dest;      // strcpy처럼 복사된 문자열(dest)의 주소를 반환
}
