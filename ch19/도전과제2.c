// **********************************************
// 제 목 : 도전과제2
// 날 짜 : 2026년 10월 8일
// 작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

#define MAX 20   // 입력 가능한 n의 최댓값 (배열 크기)

int main(void)
{
    int arr[MAX][MAX] = { 0 };   // 0으로 초기화 (아직 채우지 않은 칸)
    int n;

    printf("숫자를 입력하시오 : ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("1부터 %d 사이의 숫자를 입력하세요.\n", MAX);
        return 0;
    }

    // 달팽이 배열: 바깥쪽에서 시작해 시계 방향으로 안쪽으로 돌면서 1부터 n*n까지 채움
    int top = 0, bottom = n - 1;   // 아직 채우지 않은 영역의 위/아래 행
    int left = 0, right = n - 1;   // 아직 채우지 않은 영역의 왼쪽/오른쪽 열
    int num = 1;                   // 채울 값

    while (top <= bottom && left <= right)
    {
        // 1) 위쪽 행: 왼쪽 -> 오른쪽
        for (int j = left; j <= right; j++)
            arr[top][j] = num++;
        top++;   // 위쪽 행을 다 채웠으므로 영역을 한 칸 줄임

        // 2) 오른쪽 열: 위 -> 아래
        for (int i = top; i <= bottom; i++)
            arr[i][right] = num++;
        right--;

        // 3) 아래쪽 행: 오른쪽 -> 왼쪽 (남은 행이 있을 때만)
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                arr[bottom][j] = num++;
            bottom--;
        }

        // 4) 왼쪽 열: 아래 -> 위 (남은 열이 있을 때만)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                arr[i][left] = num++;
            left++;
        }
    }

    // 완성된 달팽이 배열 출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }

    return 0;
}
