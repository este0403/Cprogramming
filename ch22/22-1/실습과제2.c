// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 11월 3일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 학번, 이름, 주소를 하나로 묶은 구조체 정의
// (구조체 정의는 자료형만 만드는 것이므로 이 시점에는 메모리가 할당되지 않는다)
struct student {
    int number;         // 학번
    char name[20];      // 이름 (한글은 UTF-8에서 글자당 3바이트이므로 넉넉하게 잡음)
    char address[50];   // 주소 (공백이 포함될 수 있음)
};

int main(void)
{
    struct student s;   // 구조체 변수 선언 -> 이때 멤버 변수들이 메모리에 할당됨

    printf("학번을 입력하시오: ");
    scanf("%d", &s.number);         // 정수 멤버는 & 연산자로 주소를 전달

    printf("이름을 입력하시오: ");
    scanf("%s", s.name);            // 배열 이름 자체가 주소이므로 & 불필요

    // 앞선 scanf가 입력 버퍼에 '\n'을 남겨 두므로 getchar()로 제거한다.
    // 제거하지 않으면 아래 주소 입력이 '\n'을 먼저 읽어 버려 입력이 건너뛰어진다.
    getchar();

    printf("주소를 입력하시오: ");
    scanf("%[^\n]", s.address);     // '\n'이 나오기 전까지(공백 포함) 한 줄 전체를 읽음

    // 구조체 멤버 연산자(.)로 각 멤버 출력
    printf("\n");
    printf("1.학번:%d\n", s.number);
    printf("2.이름:%s\n", s.name);
    printf("3.주소:%s\n", s.address);

    return 0;
}
