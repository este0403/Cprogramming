// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 11월 24일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    FILE* fp = fopen("b.bin", "rb");   // 실습과제1에서 만든 바이너리 파일을 읽기 모드로 개방
    int buf[10];                       // 읽은 정수 10개를 저장할 배열
    int readCnt, i;

    if (fp == NULL) { puts("파일오픈 실패!"); return -1; }

    // sizeof(int) 크기의 데이터 10개를 읽어서 buf에 저장한다.
    // 반환값은 실제로 읽은 데이터의 개수이다.
    readCnt = fread((void*)buf, sizeof(int), 10, fp);
    fclose(fp);

    // 10개를 모두 읽지 못했다면 오류 또는 파일 끝이므로 알린다.
    if (readCnt != 10)
    {
        puts("파일 읽기 실패!");
        return -1;
    }

    // 읽은 정수를 한 줄에 하나씩 출력 -> a.txt의 내용과 같은지 확인
    for (i = 0; i < 10; i++)
        printf("%d\n", buf[i]);

    return 0;
}
