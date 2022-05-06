#include <iostream>
#include <vector>
#include "gaojingduchengfavector.h"
using namespace std;
vector<int> chengfa(vector<int> a, vector<int> b)
{
    vector<int> c;
    int lengtha = a.size(), lengthb = b.size();
    if (a[0] == 0 || b[0] == 0)
    {
        c.push_back(0);
        return c;
    }
    c.resize(lengtha + lengthb + 1);
    int t = lengtha + lengthb;
    int length = lengtha + lengthb + 1;
    for (int i = 0; i < length; i++)
    {
        c[i] = 0;
    }
    while (t > 0)
    {
        for (int i = 0; i <= length - 1 - t; i++)
        {
            if (i < lengtha && length - t - i <= lengthb)
            {
                c[t] = a[lengtha - i - 1] * b[lengthb - length + t + i] + c[t];
            }
        }
        t--;
    }
    for (int i = length - 1; i >= 0; i--)
    {
        int e = c[i];
        c[i] = e % 10;
        e = e / 10;
        c[i - 1] = c[i - 1] + e;
    }
    int s = 0;
    while (c[s] == 0)
    {
        s++;
    }
    for (int i = 0; i < length - s; i++)
    {
        c[i] = c[i + s];
    }
    vector<int> d(length - s);
    for (int i = 0; i < length - s; i++)
    {
        d[i] = c[i];
        cout << d[i];
    }
    return d;
}