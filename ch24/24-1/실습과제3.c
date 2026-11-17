// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 11월 17일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    char str[100];                       // 키보드로 입력받을 문자열
    FILE* fp;
    int i;

    printf("문자열을 입력하시오: ");
    fgets(str, sizeof(str), stdin);      // 공백이 포함된 한 줄을 입력받는다. (scanf는 공백에서 끊김)

    fp = fopen("result.txt", "wt");      // 쓰기용 텍스트 모드, 없으면 새로 생성
    if (fp == NULL) {
        puts("파일오픈 실패!");
        return -1;
    }

    for (i = 0; str[i] != '\0' && str[i] != '\n'; i++)   // 문자열 끝 또는 엔터 전까지 반복
    {
        if (str[i] == ' ')
            fputc('\n', fp);             // 공백문자는 줄바꿈문자로 바꾸어 출력
        else
            fputc(str[i], fp);           // 일반문자는 그대로 출력
    }
    fputc('\n', fp);                     // 마지막 단어 뒤에도 줄바꿈

    fclose(fp);

    return 0;
}
