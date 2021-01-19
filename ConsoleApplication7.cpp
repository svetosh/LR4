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

void bubble(vector<int>& vec, int size)
{
	for (int i = 1; i < size; ++i)
	{
		for (int j = 0; j < size - i; j++)
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

void selection(vector<int>& vec, int size)
{
	int naim = 0;
	for (int i = 0; i < size; i++)
	{
		naim = i;
		for (int j = i + 1; j < size; j++)
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
	long int i = begin,
		mid = begin + (end - begin) / 2,
		j = mid + 1,
		k = 0;
		vector<int> b = vec;

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
	int size;
	cout << "Введите длину массива: " << endl;
	cin >> size;
	cout << "Массив для сортировки: ";
	srand(time(nullptr));
	for (int i = 0; i < size; ++i) {
		mainvec.push_back(rand() % 201 - 100);
	}
	print_vec(mainvec);
	cout << endl
		<< "Массив отсортированный Bubble'ом: ";
	bubble(mainvec, mainvec.size());
	print_vec(mainvec);
	cout << endl
		<< "Массив отсортированный selection'ом: ";
	selection(mainvec, mainvec.size());
	print_vec(mainvec);
	cout << endl;

	vector<int> vec2;
	int size2;
	cout << "Введите длину массива, который будет сортироваться Mergе'ом: " << endl;
	cin >> size2;
	cout << "Массив для сортировки: ";
	srand(time(nullptr));
	for (int i = 0; i < size2; ++i) {
		vec2.push_back(rand() % 201 - 100);
	}
	print_vec(vec2);
	cout << endl
		<< "Массив отсортированный Mergе'ом: ";
	MergSort(vec2, 0, vec2.size() - 1);
	print_vec(vec2);
	return 0;
}
