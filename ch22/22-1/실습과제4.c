// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 11월 3일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 2차원 평면 위의 점의 좌표를 저장하는 구조체 정의
struct point {
    int x;      // x 좌표
    int y;      // y 좌표
};

int main(void)
{
    struct point p1, p2;    // p1: 좌측상단 점, p2: 우측하단 점
    int width, height;      // 사각형의 폭과 높이

    // 좌측상단, 우측하단의 좌표를 각각 입력받아 구조체 멤버에 저장
    printf("좌측상단의 좌표 입력: ");
    scanf("%d%d", &p1.x, &p1.y);

    printf("우측하단의 좌표 입력: ");
    scanf("%d%d", &p2.x, &p2.y);

    // 폭 = 우측하단 x - 좌측상단 x
    // 높이 = 우측하단 y - 좌측상단 y (y 좌표가 아래로 갈수록 커지는 화면 좌표계 기준)
    width = p2.x - p1.x;
    height = p2.y - p1.y;

    printf("사각형의 폭: %d\n", width);
    printf("사각형의 높이 : %d\n", height);

    return 0;
}
