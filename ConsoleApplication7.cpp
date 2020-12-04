#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

void print_vec(vector<int>& vec)
{
	for (int i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

void bubble(vector<int>& vec)
{
	for (int i = 1; i < 30; ++i)
	{
		for (int j = 0; j < 30 - i; j++)
		{
			if (vec[j] < vec[j + 1])
			{
				int fist = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = fist;
			}
		}
	}
}

void selection(vector<int>& vec)
{
	int naim = 0;
	for (int i = 0; i < 30; i++)
	{
		naim = i;
		for (int j = i + 1; j < 30; j++)
			naim = (vec[j] < vec[naim]) ? j : naim;
		if (i != naim)
		{
			int first = vec[i];
			vec[i] = vec[naim];
			vec[naim] = first;
		}
	}
}

void Merg(vector<int>& vec, int begin, int end)
{
	int i = begin,
		mid = begin + (end - begin) / 2,
		j = mid + 1,
		k = 0,
		b[100];

	while (i <= mid && j <= end) {
		if (vec[i] <= vec[j]) {
			b[k] = vec[i]; i++;
		}
		else {
			b[k] = vec[j]; j++;
		}
		k++;
	}

	while (i <= mid)
	{
		b[k] = vec[i];
		i++;
		k++;
	}

	while (j <= end)
	{
		b[k] = vec[j];
		j++;
		k++;
	}

	for (i = 0; i < k; i++)
		vec[begin + i] = b[i];
}

void MergSort(vector<int>& vec, int left, int right)
{
	int first = 0;
	if (left < right)
		if (right - left == 1) {
			if (vec[left] > vec[right]) {
				first = vec[left]; 
				vec[left] = vec[right];
				vec[right] = first;
			}
		}
		else {
			MergSort(vec, left, left + (right - left) / 2);
			MergSort(vec, left + (right - left) / 2 + 1, right);
			Merg(vec, left, right);
		}

}



int main()
{
	setlocale(LC_ALL, "ru");
	vector<int> mainvec;
	vector<int> vecForMerge = mainvec;
	cout << "Массив для сортировки: ";
	srand(time(nullptr));
	for (int i = 0; i < 30; ++i) {
		mainvec.push_back(rand() % 201 - 100);
	}
	print_vec(mainvec);
	cout << endl
		<< "Массив отсортированный Bubble'ом: ";
	bubble(mainvec);
	print_vec(mainvec);
	cout << endl 
		 << "Массив отсортированный selection'ом: ";
	selection(mainvec);
	print_vec(mainvec);
	cout << endl 
		 << "Массив отсортированный Mergе'ом: ";
	MergSort(mainvec, 0, mainvec.size() - 1);
	print_vec(mainvec);
	return 0;
}