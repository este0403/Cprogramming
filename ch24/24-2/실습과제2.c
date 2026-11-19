// **********************************************
//   제  목 : 실습과제2
//   날  짜 : 2026년 11월 19일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

int main(void)
{
    char name[20];        // 이름
    int s1, s2, s3;       // 3과목 점수
    int total;            // 총점
    double avg;           // 평균
    int ret;

    FILE* in = fopen("input.txt", "rt");     // 입력 파일: 읽기 모드
    FILE* out = fopen("output.txt", "wt");   // 출력 파일: 쓰기 모드
    if (in == NULL || out == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    while (1)
    {
        // 한 줄("이름 점수1 점수2 점수3")을 읽는다.
        // 성공하면 읽은 항목 수(4)를, 파일 끝이면 EOF를 반환한다.
        ret = fscanf(in, "%s %d %d %d", name, &s1, &s2, &s3);
        if (ret == EOF) break;       // 파일 끝이므로 반복 종료

        total = s1 + s2 + s3;        // 총점 계산
        avg = total / 3.0;           // 평균 계산 (3.0으로 나누어 소수점 이하 유지)

        // 이름 총점 평균(소수점 첫째 자리까지)을 output.txt에 한 줄로 출력
        fprintf(out, "%s %d %.1f\n", name, total, avg);
    }

    fclose(in);
    fclose(out);
    return 0;
}
