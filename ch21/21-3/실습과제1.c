// **********************************************
//   제  목 : 실습과제1
//   날  짜 : 2026년 10월 29일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[100];      // 키보드로 입력받는 문자열
    char result[200] = "";   // 이전 문자열들을 이어 붙여 저장하는 배열 (빈 문자열로 초기화)

    // "quit"를 입력할 때까지 무한 반복
    while (1)
    {
        printf("문자열 입력 : ");
        scanf("%s", word);

        // strcmp는 두 문자열이 같으면 0을 반환 -> "quit"이면 반복 종료
        if (strcmp(word, "quit") == 0)
            break;

        // 이전 문자열이 이미 있으면(빈 문자열이 아니면) 공백 하나를 먼저 연결
        if (strlen(result) > 0)
            strcat(result, " ");

        // 새로 입력된 문자열을 이전 문자열 뒤에 연결
        strcat(result, word);

        printf("입력된 문자열: %s\n", result);
    }

    return 0;
}
