#define _CRT_SECURE_NO_WARNINGS // 보안오류방지
#pragma warning(disable:6031)  // 리턴값관련 경고 방지
#include <stdio.h>

//학번:2600152

//이름: 이준영

//총점:



//1번

/*
void get_data(double* data, int len);
void get_stat(double* data, int len, double* stat);
void put_stat(double* stat);

int main(void) {
	double data[5];
	double stat[3];

	get_data(data, 5);
	get_stat(data, 5, stat);
	put_stat(stat);

	return 0;
}

void get_data(double* data, int len) {
	printf("%d개의 실수를 입력하시오. \n", len);
	scanf("%lf", &data[0]);
	for (int i = 1; i < len; i++) {
		scanf("%lf", &data[i]);
	}
}

void get_stat(double* data, int len, double* stat) {
	double max = data[0], min = data[0], mean = 0;
	for (int i = 1; i < len; i++) {
		if (data[i] > max) {
			max = data[i];
		}
	}
	stat[1] = max;

	for (int j = 1; j < len; j++) {
		if (data[j] < min) {
			min = data[j];
		}
	}
	stat[0] = min;

	for (int i = 0; i < len; i++) {
		mean += data[i];
	}
	stat[2] = mean / len;
}

void put_stat(double* stat) {
	printf("최소값: %f \n", stat[0]);
	printf("최대값: %f \n", stat[1]);
	printf("평균값: %lf \n", stat[2]);
}
*/


//2번

/*소스코드작성 테스트후 주석처리*/



//3번

/*
int get_value(int* arr, int* fun(int, int));
int big(int a, int b);
int small(int a, int b);

int main(void) {
	int arr[5] = { -1, 2, 10, 5, 7 };
	int res;

	res = get_value(arr, big);
	printf("최대값은: %d \n", res);

	res = get_value(arr, small);
	printf("최소값은: %d \n", res);

	return 0;
}

int big(int a, int b) {
	if (a >= b)
		return a;
	else
		return b;
}

int small(int a, int b) {
	if (a >= b)
		return b;
	else
		return a;
}

int get_value(int* arr, int* fun(int, int)) {
	int x = arr[0];
	for (int i = 0; i < 5; i++) {
		x = fun(x, arr[i]);
	}
	return x;
}
*/


//4번

/*
void print_str(char* arr[], int count);
char* get_first(char* arr[], int count);

int main(void) {
	char* ptrarr[4] = { "eagle", "tiger", "lion", "squirrel" };
	char* ptr;
	int count = sizeof(ptrarr) / sizeof(ptrarr[0]);
	
	print_str(ptrarr, count);
	ptr = get_first(ptrarr, count);
	printf("사전에서 가장 앞에 오는 단어: %s \n", ptr);

	return 0;
}

void print_str(char* arr[], int count) {
	for (int i = 0; i < count; i++) {
		printf("%s \n", arr[i]);
	}
}
char* get_first(char* arr[], int count) {
	char first = arr[0][0];
	int x = 0;
	for (int i = 1; i < count; i++) {
		if (first > arr[i][0]) {
			first = arr[i][0];
			x = i;
		}
	}
	return arr[x];
}
*/


//5번

/*소스코드작성 테스트후 주석처리*/
