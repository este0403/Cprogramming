#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지
#include <stdio.h>

//학번:2600152

//이름:이준영

//총점:



//1번

/*
void get_data(double* x, int l);
double get_avg(double* x, int l);
void put_avg(double avg);

int main(void) {
	double data[5];
	double avg;

	get_data(data, 5);
	avg = get_avg(data, 5);
	put_avg(avg);

	return 0;
}

void get_data(double* x, int l) {
	printf("5개의 실수 입력: ");
	for (int i = 0; i < l; i++) {
		scanf(" %lf", &x[i]);
	}
}

double get_avg(double* x, int l) {
	int sum = 0;
	for (int i = 0; i < l; i++) {
		sum += x[i];
	}

	return (sum / l);
}

void put_avg(double avg) {
	printf("평균값은 %lf 입니다. \n", avg);
}
*/


//2번

/*
int get_digit(int x, int loc);

int main(void) {
	int x;
	int digit100, digit10, digit1;

	printf("세자리 정수를 입력하시오: ");
	scanf("%d", &x);

	digit100 = get_digit(x, 3);
	digit10 = get_digit(x, 2);
	digit1 = get_digit(x, 1);

	printf("100자리 숫자는 %d 입니다. \n", digit100);
	printf("10자리 숫자는 %d 입니다. \n", digit10);
	printf("1자리 숫자는 %d 입니다. \n", digit1);

	return 0;
}

int get_digit(int x, int loc) {
	int digit;
	if (loc == 3) {
		digit = (x / 100);
	}
	else if (loc == 2) {
		digit = (x * 0.1);
		digit %= 10;
	}

	else {
		digit = x % 10;
	}

	return digit;
}
*/



//3번

/*
void get_data(int* x, int l1, int l2);
void print_data(int* x, int l1, int l2);
void get_avg(int* x, int l1, int l2);

int main(void) {
	int score[3][4];

	get_data(&score[0][0], 3, 4);
	print_data(&score[0][0], 3, 4);
	get_avg(&score[0][0], 3, 4);

	return 0;
}
void get_data(int* x, int l1, int l2) {
	for (int i = 0; i < l1; i++) {
		printf("%d번째 학생의 4과목 점수입력: ", i + 1);
		for (int j = 0; j < l2; j++) {
			scanf(" %d", &(&x[i])[j]);
		}
	}
}

void print_data(int* x, int l1, int l2) {
	printf("%d명 학생점수출력 \n", l1);
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) {
			printf("%d ", (&x[i])[j]);
		}
		printf("\n");
	}
}
void get_avg(int* x, int l1, int l2) {
	int sum;
	double avg;
	for (int i = 0; i < l1; i++) {
		sum = 0;
		for (int j = 0; j < l2; j++) {
			sum += (&x[i])[j];
		}
		avg = sum / 4;
		printf("%d번째 학생의 총점 : %d, 평균 : %.2lf \n", i+1, sum, avg);
	}
}
*/

//4번

/*
void get_data(char* x, int l);
void print_data(char* x, int l);
int get_first(char* x, int l);

int main(void) {
	char str[4][10];
	char* ptr[4] = { &str[0][0], &str[1][0], &str[2][0], &str[3][0] };
	int first;

	get_data(ptr, 4);
	print_data(ptr, 4);
	first = get_first(ptr, 4);
	printf("제일 앞에 나오는 문자열: %s \n", &str[first][0]);

	return 0;
}

void get_data(char* x, int l) {
	for (int i = 0; i < l; i++) {
		printf("문자열 입력: ");
		scanf(" %s", &x[i]);
	}
}

void print_data(char* x, int l) {
	printf("문자열 출력 \n");
	for (int i = 0; i < l; i++) {
		printf("%s \n", &x[i]);
		
	}
}
int get_first(char* x, int l) {
	int min = (&x[0])[0];
	int ind;
	for (int i = 0; i < l; i++) {
		if ((&x[i])[0] < min) {
			ind = i;
		}
	}
	return ind;
}
*/


//5번

/*
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
void cal(int (*x)(int, int), char s[]);

int main(void) {
	cal(add, "정수합");
	cal(sub, "정수차");
	cal(mul, "정수곱");
	cal(div, "정수몫");

	return 0;
}

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int div(int a, int b) {
	return a / b;
}
void cal(int (*x)(int, int), char s[]) {
	int a, b;
	int y;
	printf("두 정수를 입력: ");
	scanf("%d %d", &a, &b);

	y = x(a, b);
	printf("%s : %d \n", s, y);
}
*/