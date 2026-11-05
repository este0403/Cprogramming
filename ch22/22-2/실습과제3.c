// **********************************************
//   제  목 : 실습과제3
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
    struct student list[3];            // 학생 3명을 저장할 구조체 배열
    struct student* p = list;          // 배열명은 첫 원소의 주소이므로 p는 list[0]을 가리킨다.
    struct student* min;               // 사전순으로 가장 앞선 학생을 가리킬 포인터
    int i;

    // 입력: list[i] 대신 포인터 연산 (p + i)를 이용
    for (i = 0; i < 3; i++)
    {
        printf("이름을 입력하시오: ");
        scanf("%s", (p + i)->name);        // (p+i)->name 은 list[i].name 과 같다.
        printf("성적을 입력하시오: ");
        scanf("%d", &(p + i)->score);      // &list[i].score 와 같다.
    }

    // 최소값 구하기: list[min_idx] 대신 포인터 min 사용
    min = p;                               // 첫 번째 학생을 최소로 가정
    for (i = 1; i < 3; i++)
    {
        if (strcmp((p + i)->name, min->name) < 0)   // 사전순으로 더 앞선 이름이면
            min = p + i;                             // min이 그 학생을 가리키도록 변경
    }

    printf("\n이름은 %s, 점수는 %d점\n", min->name, min->score);

    return 0;
}
