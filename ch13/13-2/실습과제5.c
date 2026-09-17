// **********************************************
// 제 목 : 실습과제5
// 날 짜 : 2026년 9월 17일
// 작성자 : 2600152 이준영
// **********************************************
#include <stdio.h>

int main(void)
{
    int i, n, minIdx;
    char* fruits[] = { "apple", "blueberry", "orange", "melon" };

    n = sizeof(fruits) / sizeof(fruits[0]); // 배열 원소 개수 계산
    minIdx = 0; // 일단 첫번째 문자열을 최소값으로 가정

    // 함수를 사용하지 않고 각 문자열의 첫번째 문자끼리만 비교
    for (i = 1; i < n; i++)
    {
        if (fruits[i][0] < fruits[minIdx][0])
            minIdx = i;
    }

    printf("사전에서 가장 앞에 나오는 문자열: %s\n", fruits[minIdx]);

    return 0;
}

/*
[실행결과]
사전에서 가장 앞에 나오는 문자열: apple
*/
