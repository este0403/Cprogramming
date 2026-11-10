// **********************************************
//   제  목 : 실습과제5
//   날  짜 : 2026년 11월 10일
//   작성자 : 2600152 이준영
// **********************************************

// [교재 문제 22-2 변형 내용]
// 교재 원본 : employee(이름, 전화번호, 나이) 구조체 배열 3개를 입력받아 순서대로 출력
// 변형      : 도서(book) 구조체(제목, 저자, 가격) 배열 3개를 입력받아
//             1) 순서대로 출력하고
//             2) 가격의 총합과 가장 비싼 책의 정보까지 구한다.

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 도서 정보를 저장하는 구조체 정의
struct book {
    char title[30];    // 제목
    char author[20];   // 저자
    int price;         // 가격(원)
};

int main(void)
{
    struct book list[3];    // 길이가 3인 구조체 배열 선언
    int i, total = 0, max_idx = 0;

    // 3권의 정보를 사용자로부터 입력받아 배열에 저장
    for (i = 0; i < 3; i++)
    {
        printf("%d번째 책의 제목 저자 가격 입력: ", i + 1);
        // 문자열 멤버(배열)는 & 없이, 정수 멤버는 & 를 붙여 입력
        scanf("%s %s %d", list[i].title, list[i].author, &list[i].price);
    }

    // 배열에 저장된 데이터를 순서대로 출력
    printf("\n--- 도서 목록 ---\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s %s %d원\n", list[i].title, list[i].author, list[i].price);

        total += list[i].price;                    // 가격 누적 합계
        if (list[i].price > list[max_idx].price)   // 최대값 구하기 알고리즘
            max_idx = i;                           // 가장 비싼 책의 위치 갱신
    }

    printf("\n가격의 총합 : %d원\n", total);
    printf("가장 비싼 책 : %s (%s, %d원)\n",
        list[max_idx].title, list[max_idx].author, list[max_idx].price);

    return 0;
}
