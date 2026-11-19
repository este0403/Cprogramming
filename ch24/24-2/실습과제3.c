// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 11월 19일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

#define MAX 10   // 처리할 수 있는 최대 학생 수

int main(void)
{
    char name[MAX][20];   // 학생별 이름
    int total[MAX];       // 학생별 총점
    double avg[MAX];      // 학생별 평균
    int s1, s2, s3;       // 한 학생의 3과목 점수
    int n = 0;            // 실제로 읽은 학생 수
    int i, j;

    FILE* in = fopen("input.txt", "rt");
    FILE* out = fopen("output.txt", "wt");
    if (in == NULL || out == NULL)
    {
        puts("파일오픈 실패!");
        return -1;
    }

    // 파일 끝(또는 MAX명)까지 한 줄씩 읽어 총점과 평균을 계산해 배열에 저장한다.
    while (n < MAX && fscanf(in, "%s %d %d %d", name[n], &s1, &s2, &s3) == 4)
    {
        total[n] = s1 + s2 + s3;
        avg[n] = total[n] / 3.0;
        n++;
    }

    // 총점이 높은 순서로 정렬 (선택 정렬, 내림차순)
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (total[j] > total[i])   // 뒤쪽의 총점이 더 크면 서로 교환
            {
                int t_total = total[i];
                double t_avg = avg[i];
                char t_name[20];

                total[i] = total[j]; total[j] = t_total;       // 총점 교환
                avg[i] = avg[j];     avg[j] = t_avg;           // 평균 교환
                strcpy(t_name, name[i]);                       // 이름 교환
                strcpy(name[i], name[j]);
                strcpy(name[j], t_name);
            }
        }
    }

    // 정렬된 순서대로 "N등: 이름 총점 평균" 형식으로 파일에 출력
    for (i = 0; i < n; i++)
        fprintf(out, "%d등: %s %d %.1f\n", i + 1, name[i], total[i], avg[i]);

    fclose(in);
    fclose(out);
    return 0;
}
