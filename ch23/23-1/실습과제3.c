// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 11월 10일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>     // strcmp 함수 사용

#define N 3     // 학생 수

// 이름, 점수를 멤버로 가지는 구조체를 typedef로 정의
typedef struct {
    char name[30];  // 이름
    int  score;     // 점수
} Student;

// 함수 선언
void get_data(Student arr[], int n);          // 구조체 배열에 n명의 정보를 입력
Student get_first(const Student arr[], int n); // 이름이 사전에서 제일 앞인 학생을 리턴

int main(void)
{
    Student list[N];    // 3명의 정보를 저장할 구조체 배열
    Student first;      // 이름이 가장 앞에 나오는 학생

    get_data(list, N);
    first = get_first(list, N);

    printf("제일 앞에 나오는 이름은 %s, 점수는 %d점\n", first.name, first.score);

    return 0;
}

// 입력 함수 정의
void get_data(Student arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        printf("이름을 입력하시오: ");
        scanf("%29s", arr[i].name);
        printf("성적을 입력하시오: ");
        scanf("%d", &arr[i].score);
    }
}

// 사전순으로 가장 앞에 오는 이름 탐색 함수 정의
Student get_first(const Student arr[], int n)
{
    Student first = arr[0];     // 첫 번째 학생을 일단 가장 앞이라고 가정
    int i;

    for (i = 1; i < n; i++) {
        // 문자열은 == 나 < 로 비교할 수 없으므로 strcmp를 사용한다.
        // strcmp(a, b) < 0 이면 a가 사전에서 b보다 앞에 있다는 뜻이다.
        if (strcmp(arr[i].name, first.name) < 0)
            first = arr[i];
    }
    return first;
}
