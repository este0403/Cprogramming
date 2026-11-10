// **********************************************
//   제  목 : 실습과제1
//   날  짜 : 2026년 11월 10일
//   작성자 : 2600152 이준영
// **********************************************

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)
#include <stdio.h>

// typedef로 구조체를 새로운 자료형 Student로 정의한다.
// (구조체 이름은 생략 가능하므로 생략했다.)
typedef struct {
    int  id;            // 학번
    char name[30];      // 이름 (한글은 글자당 2~3바이트이므로 넉넉하게 잡는다.)
    char addr[60];      // 주소 (공백이 포함될 수 있다.)
} Student;

// 함수 선언
void get_data(Student* s);        // 키보드로 정보를 입력받아 구조체에 저장
void put_data(const Student* s);  // 구조체 정보를 화면에 출력 (값을 바꾸지 않으므로 const)

int main(void)
{
    Student st;     // 학생 정보를 저장할 구조체 변수

    get_data(&st);  // 호출: 주소를 전달해야 main의 st 값이 바뀐다. (주소에 의한 호출)
    put_data(&st);  // 호출: 구조체가 크면 복사 비용이 크므로 주소로 전달한다.

    return 0;
}

// 입력 함수 정의
void get_data(Student* s)
{
    printf("학번을 입력하시오: ");
    scanf("%d", &s->id);          // 포인터로 멤버 접근: s->id 는 (*s).id 와 같다.

    printf("이름을 입력하시오: ");
    scanf("%29s", s->name);       // 배열 이름은 그 자체가 주소이므로 & 불필요, 29자까지만 입력

    printf("주소를 입력하시오: ");
    scanf(" %59[^\n]", s->addr);  // 공백이 포함된 한 줄을 읽기 위해 %[^\n] 사용 (앞의 공백은 남은 엔터 제거)
}

// 출력 함수 정의
void put_data(const Student* s)
{
    printf("\n1.학번:%d\n", s->id);
    printf("2.이름:%s\n", s->name);
    printf("3.주소:%s\n", s->addr);
}
