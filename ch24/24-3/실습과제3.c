// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 11월 24일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 파일을 바이너리 모드로 열어 파일 끝까지 바이트 수를 세어 반환하는 함수
// 바이너리 모드에서는 \r\n이 변환되지 않고 2바이트 그대로 읽히므로 실제 파일 크기와 같다.
// (텍스트 모드로 열면 \r\n이 \n 하나로 읽혀서 크기가 다르게 계산된다.)
long get_filesize(const char* filename)
{
    FILE* fp = fopen(filename, "rb");   // 텍스트 파일도 바이너리 모드로 개방
    long count = 0;

    if (fp == NULL) return -1;          // 파일오픈 실패

    while (fgetc(fp) != EOF)            // 1바이트씩 읽으면서 EOF가 나올 때까지
        count++;                        // 읽은 바이트 수를 센다.

    fclose(fp);
    return count;
}

int main(void)
{
    long size_a = get_filesize("a.txt");
    long size_b = get_filesize("b.bin");

    if (size_a < 0 || size_b < 0) { puts("파일오픈 실패!"); return -1; }

    printf("a.txt의 파일크기: %ld바이트\n", size_a);
    printf("b.bin의 파일크기 : %ld바이트\n", size_b);

    return 0;
}
