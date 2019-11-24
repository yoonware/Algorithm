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

	merge_sort(p, mid);                          // ������ ����
	merge_sort(p + mid, len - mid);              // ������ ������

	while (l < mid && r < len) {                 // ����
		if (p[l] < p[r]) arr_buf[k++] = p[l++];  // ���� ��
		else             arr_buf[k++] = p[r++];  // ������ ��
	}
	while (l < mid) arr_buf[k++] = p[l++];       // ���� ���� ��
	while (r < len) arr_buf[k++] = p[r++];       // ������ ���� ��

	for (int i = 0; i < len; ++i)                // ������ �Է�
		p[i] = arr_buf[i];
}

int main()
{
	// ���̽� ����
	for (int i = 0; i < ARR_SIZE; ++i)
		arr_merge[i] = arr_stl[i] = rand();

	// merge ����
	int merge_begin = GetTickCount64();
	merge_sort(arr_merge, ARR_SIZE);
	int merge_end = GetTickCount64();

	// stl ����
	int stl_begin = GetTickCount64();
	sort(arr_stl, arr_stl + ARR_SIZE);
	int stl_end = GetTickCount64();

	// ��Ȯ�� üũ
	for (int i = 0; i < ARR_SIZE; ++i)
		if (arr_merge[i] != arr_stl[i])
			cout << "Error" << endl;

	// �ҿ�ð� ���
	cout << "merge : " << (merge_end - merge_begin) << endl;
	cout << "stl   : " << (stl_end - stl_begin) << endl;

	return 0;
}