// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 11월 12일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 학생 정보를 하나로 묶는 구조체 정의 (typedef로 Student라는 새 자료형 이름 부여)
typedef struct student
{
    char name[20];    // 학생 이름
    int  stdnum;      // 학번
    int  kor;         // 국어 점수
    int  eng;         // 영어 점수
    int  math;        // 수학 점수
    double avg;       // 평균 점수 (국어, 영어, 수학으로 계산해서 저장)
} Student;

int main(void)
{
    Student st[3];    // 3명의 정보를 저장할 구조체 배열
    int i, best;      // best : 평균이 가장 높은 학생의 배열 첨자

    // 3명의 정보를 차례로 입력받는다.
    for (i = 0; i < 3; i++)
    {
        printf("이름: ");  scanf("%s", st[i].name);
        printf("학번: ");  scanf("%d", &st[i].stdnum);
        printf("국어 : "); scanf("%d", &st[i].kor);
        printf("영어 : "); scanf("%d", &st[i].eng);
        printf("수학 : "); scanf("%d", &st[i].math);

        // 평균점수 계산 후 구조체 멤버에 저장 (정수 나눗셈을 피하려고 3.0으로 나눈다)
        st[i].avg = (st[i].kor + st[i].eng + st[i].math) / 3.0;
    }

    // 평균이 가장 높은 학생을 찾는다. (첫 번째 학생을 일단 최우수로 가정)
    best = 0;
    for (i = 1; i < 3; i++)
    {
        if (st[i].avg > st[best].avg)   // 더 높은 평균이 나오면 best를 갱신
            best = i;
    }

    // 최우수 학생 정보 출력: 이름 학번 국어 영어 수학 평균(소수점 2자리)
    printf("<최우수 학생정보>\n");
    printf("%s %d %d %d %d %.2f\n", st[best].name, st[best].stdnum,
        st[best].kor, st[best].eng, st[best].math, st[best].avg);

    return 0;
}
