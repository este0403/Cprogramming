// **********************************************
//   제  목 : 실습과제6-1
//   날  짜 : 2026년 10월 29일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>   // atoi 사용

// 교재 445쪽 문제 21-2의 문제 1
// 입력받은 문자열 안의 아라비아 숫자를 모두 찾아 그 합을 출력한다. (예: "A15#43" -> 1+5+4+3 = 13)
int main(void)
{
    char str[100];
    char tmp[2];      // 숫자 문자 한 개를 문자열("5" 등)로 만들어 담는 임시 배열
    int i, sum = 0;

    printf("문자열 입력: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++)
    {
        // 문자가 '0'~'9' 사이이면 아라비아 숫자
        if (str[i] >= '0' && str[i] <= '9')
        {
            tmp[0] = str[i];
            tmp[1] = '\0';          // 널문자를 넣어 한 글자짜리 문자열로 만든다.
            sum += atoi(tmp);       // 문자열 -> 정수 변환 함수 atoi 사용 ("5" -> 5)
        }
    }

    printf("숫자의 총 합: %d\n", sum);
    return 0;
}
