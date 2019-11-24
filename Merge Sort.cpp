#include <iostream>
#include <algorithm>
#include "Windows.h"
using namespace std;

const int ARR_SIZE = 1000000;
int arr_merge[ARR_SIZE];
int arr_stl[ARR_SIZE];
int arr_buf[ARR_SIZE];

void merge_sort(int* p, int len) {
	if (len < 2) return;
	
	int l, r, k, mid;
	mid = len / 2;
	l = 0, r = mid, k = 0;

	merge_sort(p, mid);                             // 나누기 왼쪽
	merge_sort(p + mid, len - mid);                 // 나누기 오른쪽

	while (l < mid && r < len) {                    // 병합
		if (p[l] < p[r]) arr_buf[k++] = p[l++]; // 왼쪽 값
		else             arr_buf[k++] = p[r++]; // 오른쪽 값
	}
	while (l < mid) arr_buf[k++] = p[l++];          // 왼쪽 남은 값
	while (r < len) arr_buf[k++] = p[r++];          // 오른쪽 남은 값

	for (int i = 0; i < len; ++i)                   // 원본에 입력
		p[i] = arr_buf[i];
}

int main()
{
	// 케이스 생성
	for (int i = 0; i < ARR_SIZE; ++i)
		arr_merge[i] = arr_stl[i] = rand();

	// merge 정렬
	int merge_begin = GetTickCount64();
	merge_sort(arr_merge, ARR_SIZE);
	int merge_end = GetTickCount64();

	// stl 정렬
	int stl_begin = GetTickCount64();
	sort(arr_stl, arr_stl + ARR_SIZE);
	int stl_end = GetTickCount64();

	// 정확성 체크
	for (int i = 0; i < ARR_SIZE; ++i)
		if (arr_merge[i] != arr_stl[i])
			cout << "Error" << endl;

	// 소요시간 출력
	cout << "merge : " << (merge_end - merge_begin) << endl;
	cout << "stl   : " << (stl_end - stl_begin) << endl;

	return 0;
}
