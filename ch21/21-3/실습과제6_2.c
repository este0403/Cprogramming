// **********************************************
//   제  목 : 실습과제6-2
//   날  짜 : 2026년 10월 29일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

// 교재 445쪽 문제 21-2의 문제 2
// str1, str2를 fgets로 입력받고, str1을 str3에 복사한 뒤 str2를 str3 뒤에 덧붙여 출력한다.
// fgets는 '\n'까지 함께 저장하므로 문자열이 이어질 때 방해되지 않도록 '\n'을 제거해야 한다.
void RemoveBSN(char str[]);

int main(void)
{
    char str1[20];
    char str2[20];
    char str3[40];

    printf("첫 번째 문자열 입력: ");
    fgets(str1, sizeof(str1), stdin);
    RemoveBSN(str1);                    // str1 끝의 '\n' 제거

    printf("두 번째 문자열 입력: ");
    fgets(str2, sizeof(str2), stdin);
    RemoveBSN(str2);                    // str2 끝의 '\n' 제거

    strcpy(str3, str1);                 // str1을 str3에 복사
    strcat(str3, str2);                 // str2를 str3 뒤에 덧붙임

    printf("%s\n", str3);
    return 0;
}

// RemoveBSN 정의
// 문자열 끝에 '\n'이 있을 때만 '\0'으로 바꾼다.
// (입력이 배열 크기를 꽉 채워 '\n'이 없는 경우에는 마지막 글자를 지우지 않도록 검사한다.)
void RemoveBSN(char str[])
{
    int len = strlen(str);

    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}
