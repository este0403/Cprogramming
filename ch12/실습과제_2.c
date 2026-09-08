// ********************************************
//   제목 : 포인터를 이용한 변수값 출력 프로그램
//   날짜 : 2026년 9월 10일
//   작성자 : 2600152 이준영
// ********************************************

#include <stdio.h>

int main(void)
{
    int a = -100;
    char b = 'A';
    double c = 3.14;

    int* pa = &a;
    char* pb = &b;
    double* pc = &c;

    printf("int형 변수 a의 값은 : %d\n", *pa);
    printf("char형 변수 b의 값은 : %c\n", *pb);
    printf("double형 변수 c의 값은 : %lf\n", *pc);

    return 0;
}

/* 결과:
int형 변수 a의 값은 : -100
char형 변수 b의 값은 : A
double형 변수 c의 값은 : 3.140000
*/
