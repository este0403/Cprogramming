// **********************************************
//   제  목 : 실습과제5
//   날  짜 : 2026년 10월 29일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[20];       // 입력받는 단어
    char first[20];      // 사전에서 제일 앞에 나오는 단어 (최소값)
    char last[20];       // 사전에서 제일 뒤에 나오는 단어 (최대값)
    int i;

    for (i = 0; i < 5; i++)
    {
        printf("문자열 입력 : ");
        scanf("%s", word);

        if (i == 0)
        {
            // 첫 번째 단어는 최소값이자 최대값으로 초기화
            strcpy(first, word);
            strcpy(last, word);
        }
        else
        {
            // strcmp가 0보다 작으면 word가 first보다 사전에서 앞 -> 최소값 갱신
            if (strcmp(word, first) < 0)
                strcpy(first, word);

            // strcmp가 0보다 크면 word가 last보다 사전에서 뒤 -> 최대값 갱신
            if (strcmp(word, last) > 0)
                strcpy(last, word);
        }
    }

    printf("제일앞 : %s\n", first);
    printf("제일뒤 : %s\n", last);
    return 0;
}
