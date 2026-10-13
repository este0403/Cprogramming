// **********************************************
//   제   목 : 실습과제3
//   날   짜 : 2026년 10월 13일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
	char name[10];
	char blood_type;

	printf("이름을 입력하시오 : ");
	// %s는 공백/탭/엔터 앞까지만 읽는다.
	// "홍길동<엔터>"를 입력하면 "홍길동"만 name에 저장되고
	// 입력완료문자인 엔터키('\n')는 입력 버퍼에 그대로 남는다.
	scanf("%s", name);

	printf("혈액형을 입력하시오 : ");
	// [원래 코드] scanf("%c", &blood_type);
	//   -> 버퍼에 남아있던 '\n'을 입력 대기 없이 바로 blood_type에 저장해 버림
	// [수정 코드] %c 앞에 공백을 추가
	//   -> 버퍼의 whitespace('\n')를 읽어서 버리고,
	//      whitespace가 아닌 문자('A')가 입력될 때까지 기다린다.
	scanf(" %c", &blood_type);

	printf("이름: %s\n", name);
	printf("혈액형: %c\n", blood_type);

	return 0;
}
