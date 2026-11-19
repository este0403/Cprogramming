// **********************************************
//   제  목 : 실습과제1
//   날  짜 : 2026년 11월 19일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    char name[20];     // 이름 (문자열)
    int id;            // 학번 (정수)
    double grade;      // 학점 (실수)
    int i;

    // 출력용 텍스트 파일을 쓰기 모드("wt")로 연다.
    FILE* fp = fopen("result.txt", "wt");
    if (fp == NULL)    // 파일 열기에 실패하면 NULL이 반환된다.
    {
        puts("파일오픈 실패!");
        return -1;
    }

    for (i = 0; i < 3; i++)   // 3명의 정보를 차례로 입력받는다.
    {
        printf("이름,학번,학점입력: ");
        scanf("%s %d %lf", name, &id, &grade);   // 키보드에서 입력 (공백으로 구분)

        // fprintf는 printf와 사용법이 같고, 화면 대신 파일에 서식 있는 문자열을 출력한다.
        // 한 사람의 정보를 한 줄로 저장하기 위해 마지막에 \n을 넣는다.
        fprintf(fp, "%s %d %.1f\n", name, id, grade);
    }

    fclose(fp);   // 사용이 끝난 파일은 반드시 닫는다.
    return 0;
}
