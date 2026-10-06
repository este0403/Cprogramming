// **********************************************
//   제  목 : 실습과제4
//   날  짜 : 2026년 10월 6일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 함수선언 (교재 문제 17-1)
// 배열에서 최댓값과 최솟값을 찾아, 그 "원소의 주소"를 main의 포인터 변수에 저장해 주는 함수
//  - arr   : 배열의 시작 주소 (배열은 주소에 의한 호출로 전달된다)
//  - size  : 배열의 원소 개수
//  - mxPtr : main의 포인터 변수 maxPtr의 주소 (int**) -> 최댓값 원소의 주소를 저장할 곳
//  - mnPtr : main의 포인터 변수 minPtr의 주소 (int**) -> 최솟값 원소의 주소를 저장할 곳
// 함수 밖의 "포인터 변수"의 값을 바꿔야 하므로 포인터의 주소(이중 포인터)를 받아야 한다.
void MaxAndMin(int* arr, int size, int** mxPtr, int** mnPtr);

int main(void)
{
    int* maxPtr;     // 최댓값이 저장된 원소를 가리킬 포인터 (함수가 값을 채워 준다)
    int* minPtr;     // 최솟값이 저장된 원소를 가리킬 포인터 (함수가 값을 채워 준다)
    int arr[5];      // 입력받은 정수 5개를 저장할 배열
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("정수 입력 %d: ", i + 1);
        scanf("%d", &arr[i]);        // 각 배열 원소의 주소에 입력값 저장
    }

    // arr          : 배열의 시작 주소 (int*)
    // sizeof(arr)/sizeof(int) : 전체 크기(20바이트) / 원소 1개 크기(4바이트) = 원소 개수 5
    // &maxPtr, &minPtr : 포인터 변수 자체의 주소 (int**) -> 함수가 main의 포인터 변수를 바꿀 수 있다.
    MaxAndMin(arr, sizeof(arr) / sizeof(int), &maxPtr, &minPtr);

    // maxPtr, minPtr은 각각 최댓값, 최솟값 원소를 가리키므로 *를 붙여 값을 출력
    printf("최대: %d, 최소: %d \n", *maxPtr, *minPtr);

    return 0;
}

// 함수정의
void MaxAndMin(int* arr, int size, int** mxPtr, int** mnPtr)
{
    int* max, * min;   // 현재까지 찾은 최댓값, 최솟값 원소의 주소를 저장할 지역 포인터
    int i;

    max = min = &arr[0];   // 처음에는 첫 번째 원소를 최댓값이자 최솟값으로 가정

    // 교재 답안은 i = 0부터 시작하지만, arr[0]과 자기 자신을 비교하는 것은 의미가 없으므로
    // 여기서는 두 번째 원소(i = 1)부터 비교한다. (결과는 같다)
    for (i = 1; i < size; i++)
    {
        if (*max < arr[i])     // 지금까지의 최댓값보다 더 큰 원소를 발견하면
            max = &arr[i];     // max가 그 원소를 가리키도록 주소를 바꾼다.
        if (*min > arr[i])     // 지금까지의 최솟값보다 더 작은 원소를 발견하면
            min = &arr[i];     // min이 그 원소를 가리키도록 주소를 바꾼다.
    }

    *mxPtr = max;   // *mxPtr은 main의 maxPtr이므로, maxPtr에 최댓값 원소의 주소를 저장
    *mnPtr = min;   // *mnPtr은 main의 minPtr이므로, minPtr에 최솟값 원소의 주소를 저장
}
