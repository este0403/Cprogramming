// **********************************************
//   제  목 : 실습과제5
//   날  짜 : 2026년 11월 10일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 교재 484쪽 문제 23-1 [구조체 변수의 연산]
// 두 구조체 변수에 저장된 값을 서로 바꿔주는 SwapPoint 함수를 정의하고 호출한다.

// typedef로 구조체를 Point 자료형으로 정의
typedef struct point
{
    int xpos;
    int ypos;
} Point;

// 두 구조체 변수의 주소를 받아 값을 서로 바꾸는 함수 선언
// 값에 의한 호출로는 복사본만 바뀌어 main의 변수가 바뀌지 않으므로
// 문제의 "두 구조체 변수의 주소 값을 대상으로" 방식(주소에 의한 호출)을 사용한다.
void SwapPoint(Point* p1, Point* p2);
void ShowPosition(Point pos);   // 좌표 출력 함수

int main(void)
{
    Point pos1 = { 2, 4 };
    Point pos2 = { 5, 7 };

    printf("교환 전\n");
    printf("pos1: ");
    ShowPosition(pos1);
    printf("pos2: ");
    ShowPosition(pos2);

    SwapPoint(&pos1, &pos2);    // 두 구조체 변수의 주소를 전달

    printf("교환 후\n");
    printf("pos1: ");
    ShowPosition(pos1);
    printf("pos2: ");
    ShowPosition(pos2);

    return 0;
}

// 두 구조체의 값을 교환하는 함수 정의
void SwapPoint(Point* p1, Point* p2)
{
    Point temp;     // 임시 저장용 구조체 변수

    temp = *p1;     // 구조체 변수는 대입(=)이 가능하므로 한 번에 복사된다.
    *p1 = *p2;
    *p2 = temp;
}

// 좌표 출력 함수 정의
void ShowPosition(Point pos)
{
    printf("[%d, %d] \n", pos.xpos, pos.ypos);
}
