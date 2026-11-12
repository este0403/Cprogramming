// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 11월 12일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 방향을 나타내는 숫자(10, 20, 30, 40)를 열거형 상수로 묶어 의미를 드러낸다.
// 값을 명시했으므로 원래 코드의 숫자와 똑같이 동작한다.
typedef enum direction
{
    UP = 10,      // 위
    DOWN = 20,    // 아래
    LEFT = 30,    // 왼쪽
    RIGHT = 40    // 오른쪽
} Direction;

int main(void)
{
    Direction direction = UP;   // 숫자 10 대신 의미가 분명한 UP 사용

    switch (direction)
    {
    case UP:    printf("현재방향: 위");     break;
    case DOWN:  printf("현재방향: 아래");   break;
    case LEFT:  printf("현재방향: 왼쪽");   break;
    case RIGHT: printf("현재방향: 오른쪽"); break;
    }

    return 0;
}
