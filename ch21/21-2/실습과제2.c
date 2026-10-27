// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 10월 27일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 문자열을 한 글자씩 putchar로 출력하는 함수
// (문자 입출력 전용함수만 사용해야 하므로 printf/puts 대신 사용한다.)
void PrintText(const char* s)
{
    while (*s != '\0')       // 널문자를 만날 때까지
    {
        putchar(*s);         // 문자 하나씩 출력
        s++;                 // 다음 문자로 이동
    }
}

int main(void)
{
    int ch;       // getchar의 반환값(EOF = -1 포함)을 받아야 하므로 int형으로 선언
    int dummy;    // 입력 버퍼에 남은 엔터키를 읽어서 버리기 위한 변수

    while (1)     // 'q' 또는 'Q'가 입력될 때까지 무한 반복
    {
        PrintText("문자입력: ");
        ch = getchar();                  // 키보드에서 문자 하나 입력

        if (ch == 'q' || ch == 'Q')      // 종료 조건: q 또는 Q
            break;
        if (ch == EOF)                   // Ctrl+Z(Ctrl+D) 등으로 입력이 끝난 경우도 종료
            break;

        // 입력을 완성하기 위해 누른 엔터키('\n')가 버퍼에 남아 있으므로 비워준다.
        // 이를 비우지 않으면 다음 getchar가 엔터키를 입력받아 버린다.
        dummy = ch;
        while (dummy != '\n' && dummy != EOF)
            dummy = getchar();

        PrintText("입력된 문자는 ");
        putchar(ch);                     // 입력된 문자 출력
        putchar('\n');                   // 줄바꿈
    }

    return 0;
}
