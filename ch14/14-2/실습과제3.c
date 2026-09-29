// **********************************************
//   제  목 : 실습과제3
//   날  짜 : 2026년 9월 29일
//   작성자 : 2600152 이준영
// **********************************************

#include <stdio.h>

// get_data 선언: 키보드로 n개의 정수를 입력받아 배열에 저장하는 함수
void get_data(int* data, int n);

int main(void)
{
    int i, data[5];

    // get_data 호출: 배열명(시작 주소)과 개수를 전달 -> 주소에 의한 호출
    get_data(data, 5);

    // main 함수의 배열 data에 값이 저장되어 있는지 출력으로 확인
    for (i = 0; i < 5; i++)
        printf("%d번째 data: %d\n", i + 1, data[i]);

    return 0;
}

// get_data 정의
// 매개변수 data는 main 함수 배열의 시작 주소를 받는 포인터이다.
// 따라서 여기서 값을 저장하면 main 함수의 배열 원소가 직접 바뀐다.
void get_data(int* data, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d번째 data를 입력하시오: ", i + 1);
        scanf("%d", &data[i]);   // data[i]는 *(data+i)와 같으므로 &data[i]는 data+i
    }
}

/* 실행 결과
1번째 data를 입력하시오: 50<엔터>
2번째 data를 입력하시오: 10<엔터>
3번째 data를 입력하시오: 30<엔터>
4번째 data를 입력하시오: 20<엔터>
5번째 data를 입력하시오: 60<엔터>
1번째 data: 50
2번째 data: 10
3번째 data: 30
4번째 data: 20
5번째 data: 60
*/
