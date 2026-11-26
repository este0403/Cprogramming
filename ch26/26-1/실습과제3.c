// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 11월 26일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 매크로 상수 정의: 선행처리기가 컴파일 전에 소스코드의 이름을 몸체로 치환한다.
// 끝에 세미콜론(;)을 붙이지 않는다. (붙이면 세미콜론까지 치환됨)
#define PI          3.14159            // 원주율
#define MAX_STUDENT 3                  // 학생 수 (배열 크기와 반복 횟수에 공통 사용)
#define SCHOOL      "한국대학교"        // 문자열 매크로 상수
#define LINE        puts("--------------------") // 문장도 매크로 상수로 정의 가능

int main(void)
{
    double radius;                // 반지름
    int score[MAX_STUDENT];       // 매크로 상수로 배열 크기 지정
    int i, sum = 0;

    printf("학교: %s\n", SCHOOL);
    LINE;                         // puts("--------------------"); 로 치환됨

    // 1) PI 사용: 원의 둘레와 면적 계산
    printf("원의 반지름을 입력하세요 : ");
    scanf("%lf", &radius);
    printf("원 둘레: %.2f\n", 2 * PI * radius);
    printf("원 면적: %.2f\n", PI * radius * radius);
    LINE;

    // 2) MAX_STUDENT 사용: 학생 수가 바뀌면 #define 한 줄만 고치면 된다.
    for (i = 0; i < MAX_STUDENT; i++)
    {
        printf("%d번 학생 점수 : ", i + 1);
        scanf("%d", &score[i]);
        sum += score[i];
    }
    printf("평균: %.2f\n", (double)sum / MAX_STUDENT);

    return 0;
}
