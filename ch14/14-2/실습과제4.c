// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 9월 29일
//   작성자 : 2600152 이준영
// **********************************************

#include <stdio.h>

// 실수를 정수부와 소수부로 분리하는 함수 선언
// C언어 함수는 반환값을 1개만 가질 수 있으므로,
// 정수부와 소수부는 포인터 매개변수(주소에 의한 호출)로 돌려준다.
void split_real(double num, int* int_part, double* frac_part);

int main(void)
{
    double num, frac;   // 입력받은 실수, 소수부
    int integer;        // 정수부

    // 화면 입출력은 main 함수에서만 처리한다.
    printf("실수를 입력하시오 : ");
    scanf("%lf", &num);

    // 호출: main의 지역변수 integer, frac의 주소를 전달
    split_real(num, &integer, &frac);

    printf("정수부 : %d\n", integer);
    printf("소수부 : %.5f\n", frac);

    return 0;
}

// 정수부와 소수부를 구하는 함수 정의 (1개의 함수로 두 값을 모두 처리)
void split_real(double num, int* int_part, double* frac_part)
{
    *int_part = (int)num;             // (int)로 형변환하면 소수점 아래가 버려져 정수부만 남는다.
    *frac_part = num - *int_part;     // 원래 값에서 정수부를 빼면 소수부가 된다.
}

/* 실행 결과
실수를 입력하시오 : 3.14159<엔터>
정수부 : 3
소수부 : 0.14159
*/
