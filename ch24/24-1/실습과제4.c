// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 11월 17일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    FILE* ifp, * ofp;
    int ch;
    int newline = 1;                     // 줄의 시작 위치인지 여부

    ifp = fopen("test.txt", "rt");       // 읽기용 (ANSI 인코딩으로 저장된 파일)
    if (ifp == NULL) {
        puts("파일오픈 실패!");
        return -1;
    }

    ofp = fopen("result.txt", "wt");     // 쓰기용
    if (ofp == NULL) {
        puts("파일오픈 실패!");
        fclose(ifp);
        return -1;
    }

    while (1)
    {
        ch = fgetc(ifp);
        if (ch == EOF) break;

        if (newline && ch == ' ')        // 줄 맨 앞의 공백은 출력하지 않는다.
            continue;
        if (ch == '\n')                  // 원본의 개행문자는 무시
            continue;

        fputc(ch, ofp);                  // 읽은 문자를 result.txt에 출력
        newline = 0;

        if (ch == '.') {                 // 마침표를 만나면 파일에 줄바꿈문자 출력
            fputc('\n', ofp);
            newline = 1;
        }
    }

    fclose(ifp);
    fclose(ofp);

    return 0;
}
