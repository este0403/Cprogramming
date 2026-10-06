// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 10월 1일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    int score[3][3];        // 3명 학생의 국어, 영어, 수학 성적 (행: 학생, 열: 과목)
    double avg[3];          // 각 학생의 평균
    int tot;                // 한 학생의 총점
    int best = 0;           // 최우수 학생의 인덱스 (첫 번째 학생으로 가정)
    int i, j;

    // 학생 수만큼 반복하면서 3과목 성적을 입력받는다.
    for (i = 0; i < 3; i++)
    {
        printf("%d번째 학생의 국어,영어,수학 성적을 입력: ", i + 1);
        for (j = 0; j < 3; j++)
            scanf("%d", &score[i][j]);
    }

    // 각 학생의 총점과 평균을 구한다.
    for (i = 0; i < 3; i++)
    {
        tot = 0;                        // 학생마다 총점을 0으로 초기화
        for (j = 0; j < 3; j++)
            tot += score[i][j];
        avg[i] = tot / 3.0;             // 정수 나눗셈이 되지 않도록 3.0으로 나눈다.
    }

    // 평균이 가장 높은 학생을 찾는다.
    for (i = 1; i < 3; i++)
    {
        if (avg[i] > avg[best])
            best = i;
    }

    printf("최우수 학생은 %d번째 학생이고 평균점수는 %g점이다.\n", best + 1, avg[best]);

    return 0;
}
