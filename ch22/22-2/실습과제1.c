// **********************************************
//   제  목 : 실습과제1
//   날  짜 : 2026년 11월 5일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 이름과 점수를 멤버로 가지는 구조체 정의
struct student {
    char name[20];   // 이름
    int score;       // 점수
};

int main(void)
{
    struct student list[3];   // 학생 3명을 저장할 구조체 배열
    int i, max_idx;

    // 3명의 이름과 성적을 입력받아 구조체 배열에 저장
    for (i = 0; i < 3; i++)
    {
        printf("이름을 입력하시오: ");
        scanf("%s", list[i].name);        // name은 배열이므로 & 없이 전달
        printf("성적을 입력하시오: ");
        scanf("%d", &list[i].score);      // score는 일반 변수이므로 & 필요
    }

    // 최대값 구하기 알고리즘: 첫 번째 학생을 최우수로 가정하고 나머지와 비교
    max_idx = 0;
    for (i = 1; i < 3; i++)
    {
        if (list[i].score > list[max_idx].score)   // 더 높은 점수가 나오면
            max_idx = i;                           // 최우수 학생의 위치를 갱신
    }

    printf("\n최우수학생의 이름은 %s, 점수는 %d점\n",
        list[max_idx].name, list[max_idx].score);

    return 0;
}
