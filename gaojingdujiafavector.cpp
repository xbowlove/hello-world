#include <iostream>
#include <vector>
#include "gaojingdujiafavector.h"
using namespace std;
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
vector<int> jiafa(vector<int> a, vector<int> b)
{
    vector<int> c;
    int lengtha = a.size(), lengthb = b.size(), i = 1;
    c.reserve(max(lengtha, lengthb) + 1);
    int length = max(lengtha, lengthb) + 1;
    while (i <= lengtha && i <= lengthb)
    {
        c[length - i] = a[lengtha - i] + b[lengthb - i];
        i++;
    }
    if (lengtha < lengthb)
    {
        for (int j = lengtha + 1; j <= lengthb; j++)
        {
            c[length - j] = b[lengthb - j];
        }
    }
    if (lengtha > lengthb)
    {
        for (int j = lengthb + 1; j <= lengtha; j++)
        {
            c[length - j] = a[lengtha - j];
        }
    }
    for (int j = length - 1; j >= 0; j--)
    {
        int e = c[j];
        c[j] = e % 10;
        e = e / 10;
        c[j - 1] = c[j - 1] + e;
    }
    if (c[0] == 0)
    {
        for (int k = 0; k < length; k++)
        {
            c[k] = c[k + 1];
        }
        length--;
    }
    vector<int> d(length);
    for (int k = 0; k < length; k++)
    {
        d[k] = c[k];
        cout << d[k];
    }
    return d;
}