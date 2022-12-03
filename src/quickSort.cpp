#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &vec, int left, int right);

int main()
{
    vector<int> vec{1, 215, 3313, 42, 25, 16, 17, 518, 19, 210};
    quickSort(vec, 0, vec.size() - 1);
    for (auto i : vec)
        cout << i << " ";
    return 0;
}

void quickSort(vector<int> &vec, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = vec[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (vec[i] < pivot)
            i++;
        while (vec[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = vec[i];
            vec[i] = vec[j];
            vec[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(vec, left, j);
    if (i < right)
        quickSort(vec, i, right);
}
