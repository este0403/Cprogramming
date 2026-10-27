// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 10월 27일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// fgets로 입력받은 문자열 끝의 엔터키('\n')를 널문자('\0')로 바꾸는 함수
// fgets는 엔터키까지 배열에 저장하므로, 그대로 출력하면 줄바꿈이 한 번 더 발생한다.
void RemoveNewLine(char* s)
{
    while (*s != '\0')
    {
        if (*s == '\n')
        {
            *s = '\0';       // 엔터키를 문자열의 끝으로 변경
            break;
        }
        s++;
    }
}

int main(void)
{
    // 한글은 한 글자가 2바이트이므로 여유 있게 배열을 잡는다.
    // 이름: "홍길동" = 6바이트, 주소: "군산시 대학로 558" = 약 18바이트,
    // 자동차번호: "52어6746" = 약 9바이트 (모두 널문자와 엔터키 포함해서 넉넉하게)
    char name[20];
    char addr[50];
    char car[20];

    // 입력 (문자열 입출력 전용함수 fputs, fgets 사용)
    fputs("이름: ", stdout);
    fgets(name, sizeof(name), stdin);       // 공백 포함 입력 가능, 배열 크기까지만 저장
    RemoveNewLine(name);

    fputs("주소: ", stdout);
    fgets(addr, sizeof(addr), stdin);       // "군산시 대학로 558"처럼 공백이 있어도 입력 가능
    RemoveNewLine(addr);

    fputs("자동차번호: ", stdout);
    fgets(car, sizeof(car), stdin);
    RemoveNewLine(car);

    // 출력
    // fputs는 자동 줄바꿈을 하지 않으므로 줄바꿈이 필요한 곳에 직접 '\n'을 출력한다.
    puts("<결과출력>");                     // puts는 출력 후 자동 줄바꿈
    fputs("이름:", stdout);    puts(name);
    fputs("주소:", stdout);    puts(addr);
    fputs("자동차번호: ", stdout); puts(car);

    return 0;
}
