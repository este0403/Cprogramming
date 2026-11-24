// **********************************************
//   제  목 : 실습과제1
//   날  짜 : 2026년 11월 24일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    FILE* fp;                  // 파일 포인터 (a.txt, b.bin에 번갈아 사용)
    int buf[10];               // 텍스트 파일에서 읽은 정수 10개를 저장할 배열
    unsigned char bytes[40];   // b.bin을 바이트 단위로 읽어 16진수로 확인하기 위한 배열
    int i;

    /*** 1. 텍스트 파일 a.txt에서 정수 10개 읽기 ***/
    fp = fopen("a.txt", "rt");           // 텍스트 읽기 모드
    if (fp == NULL) { puts("a.txt 파일오픈 실패!"); return -1; }

    for (i = 0; i < 10; i++)
    {
        // 한 줄에 하나씩 적힌 숫자를 문자열이 아니라 정수(int)로 변환해서 읽는다.
        if (fscanf(fp, "%d", &buf[i]) != 1)
        {
            puts("a.txt 읽기 실패!");
            fclose(fp);
            return -1;
        }
    }
    fclose(fp);

    /*** 2. 바이너리 파일 b.bin으로 출력 ***/
    fp = fopen("b.bin", "wb");           // 바이너리 쓰기 모드
    if (fp == NULL) { puts("b.bin 파일오픈 실패!"); return -1; }

    // int 10개(4바이트 x 10 = 40바이트)를 변환 없이 메모리 그대로 저장한다.
    fwrite((void*)buf, sizeof(int), 10, fp);
    fclose(fp);

    /*** 3. b.bin의 내용을 16진수로 확인 ***/
    fp = fopen("b.bin", "rb");           // 바이너리 읽기 모드
    if (fp == NULL) { puts("b.bin 파일오픈 실패!"); return -1; }

    fread((void*)bytes, 1, sizeof(bytes), fp);   // 1바이트씩 40개를 읽는다.
    fclose(fp);

    // 정수 1개(4바이트)씩 한 줄에 출력
    // 리틀 엔디안이므로 낮은 자리 바이트가 먼저 저장되어 있다.
    for (i = 0; i < 40; i++)
    {
        printf("%02X ", bytes[i]);
        if (i % 4 == 3) putchar('\n');
    }

    return 0;
}
