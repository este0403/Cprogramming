// **********************************************
//   제  목 : 실습과제1
//   날  짜 : 2026년 11월 17일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    char src[100], dst[100];   // 복사할 파일명, 복사받을 파일명을 저장할 문자열
    FILE* ifp, * ofp;          // 입력용 / 출력용 파일 포인터
    int ch;                    // fgetc는 EOF(-1)를 반환하므로 char가 아닌 int로 받는다.

    printf("복사할 파일명 : ");
    scanf("%s", src);
    printf("복사받을 파일명 : ");
    scanf("%s", dst);

    // 복사할 파일은 읽기용 텍스트 모드("rt")로 연다.
    ifp = fopen(src, "rt");
    if (ifp == NULL) {                   // 파일이 없으면 fopen은 NULL을 반환
        puts("파일오픈 실패!");
        return -1;
    }

    // 복사받을 파일은 쓰기용 텍스트 모드("wt")로 연다. (없으면 새로 생성)
    ofp = fopen(dst, "wt");
    if (ofp == NULL) {
        puts("파일오픈 실패!");
        fclose(ifp);                     // 이미 열린 입력 파일은 닫고 종료
        return -1;
    }

    while (1)
    {
        ch = fgetc(ifp);                 // 입력 파일에서 문자 1개 읽기
        if (ch == EOF) break;            // 파일 끝(또는 오류)이면 반복 종료
        fputc(ch, ofp);                  // 읽은 문자를 출력 파일에 그대로 쓰기
    }

    fclose(ifp);                         // 사용이 끝난 스트림은 반드시 닫는다.
    fclose(ofp);                         // fclose 시 버퍼의 남은 데이터가 파일에 저장됨

    printf("%s파일을 %s파일로 복사했습니다.\n", src, dst);

    return 0;
}
