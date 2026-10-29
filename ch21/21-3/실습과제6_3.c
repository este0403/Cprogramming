// **********************************************
//   제  목 : 실습과제6-3
//   날  짜 : 2026년 10월 29일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

// 교재 445쪽 문제 21-2의 문제 3
// "이정선 29"처럼 이름과 나이를 하나의 문자열로 두 사람 입력받아
// 이름과 나이가 각각 같은지 다른지 판단하여 출력한다.
// 이름은 세 글자가 아닐 수도 있고 영문일 수도 있으며, 이름과 나이 사이에만 공백이 있다.
int main(void)
{
    char info1[50], info2[50];     // 입력받은 한 줄 전체("이름 나이")
    char name1[30], name2[30];     // 분리한 이름
    int age1, age2;                // 분리한 나이

    printf("첫 번째 사람(이름 나이): ");
    fgets(info1, sizeof(info1), stdin);
    printf("두 번째 사람(이름 나이): ");
    fgets(info2, sizeof(info2), stdin);

    // sscanf: 문자열에서 서식에 맞게 값을 읽어 온다.
    // %s는 공백 전까지를 이름으로, %d는 그 뒤의 숫자 문자열을 정수로 변환하여 저장한다.
    // 이름의 길이와 상관없이 공백을 기준으로 나누므로 한글/영문, 글자 수에 관계없이 동작한다.
    sscanf(info1, "%s %d", name1, &age1);
    sscanf(info2, "%s %d", name2, &age2);

    // 이름 비교: strcmp가 0이면 같은 문자열
    if (strcmp(name1, name2) == 0)
        printf("이름은 같습니다.\n");
    else
        printf("이름은 다릅니다.\n");

    // 나이 비교: 정수로 변환되어 있으므로 == 로 비교
    if (age1 == age2)
        printf("나이는 같습니다.\n");
    else
        printf("나이는 다릅니다.\n");

    return 0;
}
