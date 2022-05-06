#include <iostream>
using namespace std;
int a[8];
void change(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
    return;
}
void pai(int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int lower = start;
    for (int i = start; i <= end - 1; i++)
    {
        if (a[i] < a[end])
        {
            change(a[i], a[lower]);
            lower++;
        }
    }
    change(a[lower], a[end]);
    pai(start, lower - 1);
    pai(lower + 1, end);
    return;
}
int main()
{
    for (int i = 0; i < 8; i++)
    {
        cin >> a[i];
    }
    pai(0, 7);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}