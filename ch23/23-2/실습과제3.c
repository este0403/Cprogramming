// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 11월 12일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 공용체: 하나의 메모리(4바이트)를 정수 전체(iBuf)로도, 바이트 단위(bBuf)로도 접근한다.
typedef union rdbuf
{
    unsigned int  iBuf;      // 4바이트 정수 전체
    unsigned char bBuf[4];   // 같은 4바이트를 1바이트씩 접근 (부호 확장을 피하려고 unsigned)
} RDBuf;

int main(void)
{
    RDBuf buf;

    printf("정수를 입력하시오(16진수): ");
    scanf("%x", &buf.iBuf);   // 16진수로 입력받아 iBuf에 저장

    // 인텔 CPU는 리틀엔디안이므로 낮은 주소(bBuf[0])에 최하위 바이트가 저장된다.
    // 예) 0x11223344 -> bBuf[0]=44, bBuf[1]=33, bBuf[2]=22, bBuf[3]=11
    printf("최상위(4번째) 바이트(16진수) : %x\n", buf.bBuf[3]);
    printf("3번째 바이트(16진수) : %x\n", buf.bBuf[2]);
    printf("2번째 바이트(16진수) : %x\n", buf.bBuf[1]);
    printf("최하위(1번째) 바이트(16진수) : %x\n", buf.bBuf[0]);

    return 0;
}
