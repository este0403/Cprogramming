// **********************************************
//   제   목 : 실습과제5
//   날   짜 : 2026년 10월 13일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
	char str[20];
	char ch;
	int i = 0;

	printf("문자열을 입력하시오 : ");

	// scanf("%s", str)은 공백 앞까지만 읽으므로 "Hello world"를 다 받지 못한다.
	// 대신 scanf("%c", ...)로 문자를 하나씩 읽어
	// 엔터키('\n')가 나올 때까지 배열에 복사한다.
	scanf("%c", &ch);
	// i < 19 : 마지막 칸(str[19])은 널문자를 위해 남겨둔다 (배열 오버플로 방지)
	while (ch != '\n' && i < 19)
	{
		str[i] = ch;	// 읽은 문자를 배열에 저장
		i++;			// 다음 저장 위치로 이동
		scanf("%c", &ch);
	}

	// 마지막에 널문자를 대입하여 문자열로 완성
	str[i] = '\0';

	printf("문자열: %s\n", str);

	return 0;
}
