// **********************************************
// 제 목 : 실습과제5
// 날 짜 : 2026년 9월 22일
// 작성자 : 2600152 이준영
// **********************************************
//
// 교재 320페이지 문제1번 [Call-by-value & Call-by-reference]
// 원래 문제는 "변수 num에 저장된 값의 제곱"을 구하는 것이었으나,
// 실습과제5의 요구사항에 따라 "num 변수에 저장된 값을 100배" 하는
// 함수로 수정함. 원본 문제와 동일하게 두 가지 형태로 함수를 작성함.
// - Call-by-value 기반의 MultiplyByValue 함수
//   : 인자로 전달된 값의 100배를 계산하여 반환(return)함
// - Call-by-reference 기반의 MultiplyByReference 함수
//   : 정수가 저장된 변수의 주소 값을 인자로 받아서, 해당 변수에
//     저장된 값의 100배를 그 변수에 직접 다시 저장함
#include <stdio.h>

int  MultiplyByValue(int num);          // 함수 선언 (call-by-value)
void MultiplyByReference(int* pnum);    // 함수 선언 (call-by-reference)

int main(void)
{
    int num;

    printf("정수를 입력하시오:");
    scanf("%d", &num);

    // [1] call-by-value 방식
    // num의 "값"만 함수로 복사되어 전달되므로, 함수가 계산한 결과를
    // 사용하려면 반드시 리턴값을 받아서 별도의 변수에 저장해야 함
    printf("\n[Call-by-value] 함수 호출 전 num=%d\n", num);
    int result = MultiplyByValue(num);   // 함수 호출(리턴값을 result에 저장)
    printf("[Call-by-value] 함수 호출 후 num=%d (원본은 그대로임), 리턴값=%d\n",
           num, result);

    // [2] call-by-reference 방식
    // num의 "주소"를 함수로 전달하므로, 함수 안에서 포인터를 통해
    // num이 저장된 메모리 공간을 직접 수정할 수 있음
    printf("\n[Call-by-reference] 함수 호출 전 num=%d\n", num);
    MultiplyByReference(&num);           // num의 주소를 전달
    printf("[Call-by-reference] 함수 호출 후 num=%d (원본이 직접 바뀜)\n", num);

    return 0;
}

// call-by-value : num은 호출한 쪽 변수의 값을 복사받은 지역변수일 뿐
// -> 이 함수 안에서 계산한 결과는 반드시 return으로 돌려줘야 사용 가능
int MultiplyByValue(int num)
{
    return num * 100;
}

// call-by-reference : pnum은 호출한 쪽 변수의 "주소"를 받은 포인터
// -> *pnum을 통해 원본 변수가 저장된 메모리 공간을 직접 수정함
void MultiplyByReference(int* pnum)
{
    *pnum = (*pnum) * 100;
}

/* 실행결과 (예: 3을 입력한 경우)
정수를 입력하시오:3

[Call-by-value] 함수 호출 전 num=3
[Call-by-value] 함수 호출 후 num=3 (원본은 그대로임), 리턴값=300

[Call-by-reference] 함수 호출 전 num=3
[Call-by-reference] 함수 호출 후 num=300 (원본이 직접 바뀜)
*/

/* 두 방식의 차이 및 원하는 결과
- MultiplyByValue (call-by-value) : num의 "값"만 복사되어 전달되므로
  함수 내부에서 100배를 계산해도 main의 num 자체는 절대 바뀌지 않음.
  계산 결과를 쓰려면 반드시 리턴값을 받아서 별도의 변수(result)에
  저장해야 함 -> num을 "직접" 바꾸는 것은 불가능함.
- MultiplyByReference (call-by-reference) : num의 "주소"가 전달되므로
  포인터(*pnum)를 통해 main의 num이 저장된 메모리 공간을 직접
  수정할 수 있음 -> 함수 호출이 끝난 뒤에도 100배로 바뀐 값이
  num 안에 그대로 남아있음.
- "num 변수에 저장된 값을 100배로 만든다"는 문제의 취지(변수 자체를
  바꾸는 것)에 맞는 원하는 결과는 MultiplyByReference, 즉
  call-by-reference(주소에 의한 호출) 방식임.
*/
