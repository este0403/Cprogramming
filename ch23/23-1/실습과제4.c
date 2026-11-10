// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 11월 10일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 구조체를 typedef로 정의
typedef struct point {
    int xpos;
    int ypos;
} Point;

// 두 구조체의 값을 서로 바꾸는 함수 선언
// 주의: 슬라이드의 호출 swap_struct(pos1, pos2)처럼 값에 의한 호출로 전달하면
//       함수에는 복사본이 전달되므로 main의 pos1, pos2는 바뀌지 않는다.
//       따라서 구조체의 주소를 전달하는 주소에 의한 호출(call by reference)로 구현하고,
//       호출도 swap_struct(&pos1, &pos2)로 한다.
void swap_struct(Point* p1, Point* p2);

int main(void)
{
    Point pos1 = { 1, 2 };
    Point pos2 = { 3, 4 };

    printf("pos1:[%d, %d], pos2:[%d, %d] \n", pos1.xpos, pos1.ypos,
                                              pos2.xpos, pos2.ypos);

    swap_struct(&pos1, &pos2);  // 두 구조체 변수의 주소를 전달

    printf("pos1:[%d, %d], pos2:[%d, %d] \n", pos1.xpos, pos1.ypos,
                                              pos2.xpos, pos2.ypos);
    return 0;
}

// 스왑 함수 정의
void swap_struct(Point* p1, Point* p2)
{
    Point temp;     // 임시 저장용 구조체 (함수 안의 지역변수)

    temp = *p1;     // 구조체는 대입(=) 연산이 가능하므로 멤버별로 따로 바꿀 필요가 없다.
    *p1 = *p2;
    *p2 = temp;
}
