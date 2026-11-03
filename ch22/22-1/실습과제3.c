// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 11월 3일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// 자동차 모델, 번호판, 주행거리를 하나로 묶은 구조체 정의
struct car {
    char model[20];     // 모델 (예: 소나타)
    char plate[20];     // 번호판 (예: 10A5577)
    int distance;       // 주행거리 (km)
};

int main(void)
{
    struct car c;       // 구조체 변수 선언 -> 메모리 할당

    // 예제3처럼 멤버마다 scanf로 값을 입력받아 구조체 멤버에 저장한다.
    // 모델과 번호판에는 공백이 없으므로 %s로 읽는다. (배열 이름이 곧 주소이므로 & 불필요)
    printf("모델을 입력하시오: ");
    scanf("%s", c.model);

    printf("번호판을 입력하시오: ");
    scanf("%s", c.plate);

    printf("주행거리를 입력하시오: ");
    scanf("%d", &c.distance);       // 정수 멤버는 & 필요

    // 입력받은 값을 멤버 연산자(.)로 접근하여 출력
    printf("\n");
    printf("1.모델 : %s\n", c.model);
    printf("2.번호판: %s\n", c.plate);
    printf("3.주행거리: %d km\n", c.distance);

    return 0;
}
