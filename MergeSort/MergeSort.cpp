#include <iostream>
#include <string.h>

using namespace std;

void merge(int A[], int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2]; 

	for (int i = 0; i < n1; i++)
		L[i] = A[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}

}

void mergeSort(int A[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}

int main()
{
	int A[] = { 2, 11, 1, 5, 6, 9, 20, 4 };
	int array_size = sizeof(A) / sizeof(A[0]);
	cout << "Mang da cho la: \n";
	for (int i = 0; i < array_size; i++)
		cout << A[i] << " ";
	cout << endl;
	mergeSort(A, 0, array_size - 1);
	cout << "\nMang duoc sap xep la:  \n";
	for (int i = 0; i < array_size; i++)
		cout << A[i] << " ";
	cout << endl;
	cin.get();
	return 0;
}