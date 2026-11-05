// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 11월 5일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>   // strcmp 함수 사용

// 이름과 점수를 멤버로 가지는 구조체 정의
struct student {
    char name[20];   // 이름
    int score;       // 점수
};

int main(void)
{
    struct student list[3];   // 학생 3명을 저장할 구조체 배열
    int i, min_idx;

    // 3명의 이름과 성적을 입력받아 구조체 배열에 저장
    for (i = 0; i < 3; i++)
    {
        printf("이름을 입력하시오: ");
        scanf("%s", list[i].name);
        printf("성적을 입력하시오: ");
        scanf("%d", &list[i].score);
    }

    // 최소값 구하기 알고리즘: 첫 번째 학생의 이름을 최소로 가정
    min_idx = 0;
    for (i = 1; i < 3; i++)
    {
        // strcmp(a, b)가 음수이면 a가 b보다 사전순으로 앞선다.
        if (strcmp(list[i].name, list[min_idx].name) < 0)
            min_idx = i;      // 사전순으로 더 앞선 이름이 나오면 위치 갱신
    }

    printf("\n이름은 %s, 점수는 %d점\n",
        list[min_idx].name, list[min_idx].score);

    return 0;
}
