#include <iostream>
#include <algorithm>
#include "Windows.h"
using namespace std;

const int ARR_SIZE = 1000000;
int arr_quick[ARR_SIZE];
int arr_stl[ARR_SIZE];

void quick_sort(int* p, int left, int right) {
	if (left >= right) return;

	int l = left - 1;
	int r = right + 1;
	int pivot = p[(l + r) / 2];

	while(1) {
		while (p[++l] < pivot);  // pivot ���� ū �� ã��
		while (p[--r] > pivot);  // pivot ���� ���� �� ã��
		if (l >= r) break;       // pivot ���� ������ ������ ��
		int temp = p[l];         // swap(p[l], p[r])
		p[l] = p[r];
		p[r] = temp;
	}

	quick_sort(p, left, l - 1);  // pivot ���� �迭
	quick_sort(p, r + 1, right); // pivot ������ �迭
}

int main()
{
	// ���̽� ����
	for (int i = 0; i < ARR_SIZE; ++i)
		arr_quick[i] = arr_stl[i] = rand();

	// quick ����
	int quick_begin = GetTickCount64();
	quick_sort(arr_quick, 0, ARR_SIZE - 1);
	int quick_end = GetTickCount64();

	// stl ����
	int stl_begin = GetTickCount64();
	sort(arr_stl, arr_stl + ARR_SIZE);
	int stl_end = GetTickCount64();

	// ��Ȯ�� üũ
	for (int i = 0; i < ARR_SIZE; ++i)
		if (arr_quick[i] != arr_stl[i])
			cout << "Error" << endl;

	// �ҿ�ð� ���
	cout << "quick : " << (quick_end - quick_begin) << endl;
	cout << "stl   : " << (stl_end - stl_begin) << endl;

	return 0;
}