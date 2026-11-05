// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 11월 5일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 2차원 평면의 점을 저장하는 구조체
struct point {
    int x;
    int y;
};

// 삼각형의 세 점을 저장하는 구조체 (구조체를 멤버로 가지는 구조체)
struct triangle {
    struct point p[3];
};

// 두 점 사이 거리의 제곱을 반환 (제곱근을 쓰면 오차가 생기므로 제곱값끼리 비교)
int dist2(struct point a, struct point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(void)
{
    struct triangle t;
    int i;
    int d1, d2, d3;   // 세 변의 길이의 제곱

    for (i = 0; i < 3; i++)
    {
        printf("%d번째 점 (x,y) 입력: ", i + 1);
        scanf("%d %d", &t.p[i].x, &t.p[i].y);
    }

    d1 = dist2(t.p[0], t.p[1]);   // 변 p0-p1
    d2 = dist2(t.p[1], t.p[2]);   // 변 p1-p2
    d3 = dist2(t.p[2], t.p[0]);   // 변 p2-p0

    // 피타고라스 정리: 두 변의 제곱의 합 = 나머지 한 변의 제곱이면 직각삼각형
    // (세 점이 한 직선 위에 있어 길이 0인 변이 생기는 경우는 제외)
    if (d1 > 0 && d2 > 0 && d3 > 0 &&
        (d1 + d2 == d3 || d2 + d3 == d1 || d3 + d1 == d2))
        printf("삼각형은 직각삼각형임\n");
    else
        printf("삼각형은 직각삼각형 아님\n");

    return 0;
}
