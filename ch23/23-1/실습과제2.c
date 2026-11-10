// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 11월 10일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

#define N 3     // 학생 수

// 이름, 점수를 멤버로 가지는 구조체를 typedef로 정의
typedef struct {
    char name[30];  // 이름
    int  score;     // 점수
} Student;

// 함수 선언
void get_data(Student arr[], int n);        // 구조체 배열에 n명의 정보를 입력
Student get_best(const Student arr[], int n); // 최우수 학생의 데이터를 구조체로 리턴

int main(void)
{
    Student list[N];    // 3명의 정보를 저장할 구조체 배열
    Student best;       // 최우수 학생

    get_data(list, N);          // 배열 이름은 주소이므로 원본 배열에 바로 저장된다.
    best = get_best(list, N);   // 구조체는 대입(=)이 가능하므로 반환값을 그대로 저장

    // 출력은 main 함수에서 처리
    printf("최우수학생의 이름은 %s, 점수는 %d점\n", best.name, best.score);

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

// 최우수 학생 탐색 함수 정의
Student get_best(const Student arr[], int n)
{
    Student best = arr[0];  // 첫 번째 학생을 일단 최우수로 가정 (최댓값 알고리즘과 동일)
    int i;

    for (i = 1; i < n; i++) {
        if (arr[i].score > best.score)  // 더 높은 점수가 나오면 교체
            best = arr[i];              // 구조체 전체 대입
    }
    return best;    // 구조체 변수를 한 번에 반환 (이름 + 점수 2개 값을 한꺼번에 돌려줌)
}
