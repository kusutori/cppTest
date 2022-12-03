#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> vec = {1, 22, 3, 4, 51, 6, 72, 84, 9, 10};
    vec.push_back(11);
    vec.push_back(12);
    vec.push_back(13);

    std::sort(vec.rbegin(), vec.rend());
    for (auto &i : vec)
    {
        cout << i << " ";
    }
    return 0;
}