// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 10월 6일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 함수선언
// 포인터 배열(int* ptrarr[3])의 배열명은 첫 번째 원소(int*)의 주소이므로 int** 형이다.
// 따라서 포인터 배열을 받는 매개변수는 이중 포인터(int**)로 선언한다.
int get_max(int** dptr, int n);

int main(void)
{
    int num1 = 50, num2 = 20, num3 = 30;
    int* ptrarr[3] = { &num1, &num2, &num3 };   // 각 정수 변수의 주소를 저장한 포인터 배열
    int max;

    max = get_max(ptrarr, 3);   // 함수호출: 포인터 배열명(int**)과 원소 개수 전달 (주소에 의한 호출)
    printf("최댓값:%d\n", max);

    return 0;
}

// 함수정의
// 포인터 배열이 가리키는 정수들 중 최댓값을 구해 반환하는 함수
int get_max(int** dptr, int n)
{
    int i;
    int max = *(dptr[0]);       // 첫 번째 포인터가 가리키는 값을 일단 최댓값으로 가정

    for (i = 1; i < n; i++)     // 두 번째 원소부터 끝까지 차례로 비교
    {
        if (*(dptr[i]) > max)   // dptr[i]는 int* 이므로 *를 한 번 더 붙여 실제 정수값을 얻는다.
            max = *(dptr[i]);   // 더 큰 값이 나오면 최댓값을 갱신
    }

    return max;                 // 최종 최댓값 반환
}
