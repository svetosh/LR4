#include <iostream>
#include <vector>

using namespace std;

void Print(vector<int>& v)
{
    for (auto el : v) {
        cout << el << " ";
    }
    cout << endl;
}

void Buble(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - 1; j++)
            if (v[j] < v[j + 1])
                swap(v[j], v[j + 1]);
}

void Selec(vector<int>& v) {
    int min;
    for (int i = 0; i < v.size() - 1; ++i) 
    {
        min = i;
        for (int j = i + 1;j < v.size();++j)
            if (v[j] < v[min])
                swap(v[j], v[min]);
    }
}

void Merge(vector<int>& v, int start, int end)
{
    if (end - start < 2)
        return;
    if (end - start == 2)
    {
        if (v[start] > v[start + 1])
            swap(v[start], v[start + 1]);
        return;
    }
    Merge(v, start, start + (end - start) / 2);
    Merge(v, start + (end - start) / 2, end);
    vector<int> merge;
    int mergeStart = start;
    int mid = start + (end - start) / 2;
    int midStrart = mid;
    while (merge.size() < end - start)
    {
        if (mergeStart >= mid || (midStrart < end && v[midStrart] <= v[mergeStart]))
        {
            merge.push_back(v[midStrart]);
            midStrart++;
        }
        else
        {
            merge.push_back(v[mergeStart]);
            mergeStart++;
        }
    }
    for (int i = start; i < end; i++)
        v[i] = merge[i - start];
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::cout << "Hello World!\n";
    vector<int> v;
    int size;
    cout << "Введите длину массива: ";
    cin >> size;
    for (int i = 0; i < size; i++)
        v.push_back(10 + rand() % 50);
    Print(v);

    cout << "-------------------Buble------------------" << endl;
    Buble(v);
    Print(v);
    cout << "-------------------Selec------------------" << endl;
    Selec(v);
    Print(v);
    cout << "-------------------Merge------------------" << endl;
    vector<int> v2;
    for (int i = 0; i < size; i++)
        v2.push_back(10 + rand() % 50);
    Print(v2);
    Merge(v2, 0, v2.size());
    Print(v2);
}
