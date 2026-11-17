// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 11월 17일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    FILE* fp;
    int ch;                              // fgetc의 반환값(EOF 구분 위해 int)
    int newline = 1;                     // 방금 줄바꿈했는지 여부(1이면 줄 시작 위치)

    // test.txt는 메모장에서 ANSI 인코딩으로 저장해야 한글이 깨지지 않는다.
    fp = fopen("test.txt", "rt");
    if (fp == NULL) {
        puts("파일오픈 실패!");
        return -1;
    }

    while (1)
    {
        ch = fgetc(fp);                  // 파일에서 문자 1개 읽기
        if (ch == EOF) break;            // 파일 끝이면 종료

        // 줄 맨 앞의 공백은 출력하지 않는다. (마침표 뒤 공백 때문에 줄이 들여쓰기 되는 것 방지)
        if (newline && ch == ' ')
            continue;
        if (ch == '\n')                  // 파일 안의 개행문자는 무시하고 마침표로만 줄을 나눈다.
            continue;

        putchar(ch);                     // 읽은 문자를 화면에 출력
        newline = 0;

        if (ch == '.') {                 // 마침표를 만나면 줄바꿈
            putchar('\n');
            newline = 1;                 // 다음 문자는 새 줄의 시작
        }
    }

    fclose(fp);

    return 0;
}
