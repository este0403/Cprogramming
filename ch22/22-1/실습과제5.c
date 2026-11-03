// **********************************************
//   제  목 : 실습과제5
//   날  짜 : 2026년 11월 3일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

struct point {
    int x;
    int y;
};

int main(void)
{
    struct point p1 = { 10, 10 }, p2 = { 20, 20 };
    int temp;   // 교환(swap)에 사용할 임시 변수

    printf("교환전 P1의 좌표: (%d, %d)\n", p1.x, p1.y);
    printf("교환전 P2의 좌표: (%d, %d)\n", p2.x, p2.y);

    // 두 구조체 변수 p1, p2의 멤버변수의 값을 교환하는 코드 (swap 알고리즘)
    // 임시 변수에 한쪽 값을 대피시킨 뒤 덮어써야 값이 사라지지 않는다.
    // x 멤버 교환
    temp = p1.x;
    p1.x = p2.x;
    p2.x = temp;

    // y 멤버 교환
    temp = p1.y;
    p1.y = p2.y;
    p2.y = temp;

    // 참고: 같은 구조체 자료형끼리는 대입(=)이 가능하므로 아래처럼 한 번에 교환할 수도 있다.
    //   struct point t = p1;  p1 = p2;  p2 = t;

    printf("교환후 P1의 좌표: (%d, %d)\n", p1.x, p1.y);
    printf("교환후 P2의 좌표: (%d, %d)\n", p2.x, p2.y);

    return 0;
}
