// **********************************************
// 제 목 : 도전과제1
// 날 짜 : 2026년 10월 8일
// 작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

#define N 4   // 배열의 가로/세로 길이

// 4x4 배열의 내용을 출력하는 함수
void print_array(int arr[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%3d ", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}

// 배열을 오른쪽(시계 방향)으로 90도 회전시키는 함수
// 회전 규칙: 회전 전 arr[i][j]의 값이 회전 후 arr[j][N-1-i] 위치로 이동한다.
//           (맨 아래 행이 왼쪽 첫 번째 열이 되고, 첫 번째 행은 오른쪽 마지막 열이 됨)
void rotate_right(int arr[N][N])
{
    int tmp[N][N];   // 회전 결과를 임시로 저장할 배열

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp[j][N - 1 - i] = arr[i][j];   // 90도 회전한 위치로 복사

    // 임시 배열의 내용을 원래 배열에 다시 복사
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = tmp[i][j];
}

int main(void)
{
    int arr[N][N];
    int num = 1;

    // 1부터 16까지 행 방향으로 차례대로 초기화
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[i][j] = num++;

    printf("[초기 배열]\n");
    print_array(arr);

    // 90도씩 세 번 회전시키며 매번 결과를 출력
    for (int k = 1; k <= 3; k++)
    {
        rotate_right(arr);
        printf("[오른쪽으로 %d도 회전]\n", 90 * k);
        print_array(arr);
    }

    return 0;
}
