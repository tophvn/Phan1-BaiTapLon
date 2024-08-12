#include <iostream>

using namespace std;

int Binary_Search(int A[], int n, int key)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (A[mid] == key)
			return mid;
		if (key < A[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(A) / sizeof(A[0]);
	int key = 8;
	int result = Binary_Search(A, n, key);
	if (result != -1)
		cout << "Phan tu " << key << " duoc tim thay tai vi tri: " << result << endl;
	else
		cout << "Khong tim thay phan tu " << key << " trong mang." << endl;
	cin.get();
	return 0;
}