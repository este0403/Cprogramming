// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 11월 26일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 방향을 나타내는 숫자(10, 20, 30, 40)를 의미 있는 이름의 매크로 상수로 정의
// -> case 문만 봐도 어떤 방향인지 바로 알 수 있어 가독성이 높아진다.
#define UP    10   // 위
#define DOWN  20   // 아래
#define LEFT  30   // 왼쪽
#define RIGHT 40   // 오른쪽

int main(void)
{
    int direction = UP;   // 숫자 10 대신 매크로 상수 UP 사용

    switch (direction)
    {
    case UP:    printf("현재방향: 위");     break;
    case DOWN:  printf("현재방향: 아래");   break;
    case LEFT:  printf("현재방향: 왼쪽");   break;
    case RIGHT: printf("현재방향: 오른쪽"); break;
    }

    return 0;
}
