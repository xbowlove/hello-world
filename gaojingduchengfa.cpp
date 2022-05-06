#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int *chengfa(int *a, int *b)
{
    int lengtha = sizeof(a) / sizeof(int), lengthb = sizeof(b) / sizeof(int);
    int v1[lengtha + lengthb + 2];
    memset(v1, 0, sizeof(int) * (lengtha + lengthb + 2));
    int t = lengtha + lengthb + 1;
    for (int p = lengtha - 1; p >= 0; p--)
    {
        for (int q = lengthb - 1; q >= 0; q--)
        {
            v1[t] = v1[t] + a[p] * b[q];
            t--;
        }
        t = lengtha + lengthb + 1 - (lengtha - p);
    }
    t = lengtha + lengthb + 1;
    while (t >= 0)
    {
        int v2[20];
        memset(v2, 0, sizeof(int) * 20);
        int e = v1[t], s = t;
        for (int i = 0;; i++)
        {
            if (e == 0)
            {
                break;
            }
            else
            {
                v2[i] = e % 10;
                e = e / 10;
            }
        }
        int i = 0;
        while (v2[i] != 0)
        {
            v1[s] = v1[s] + v2[i];
            i++;
            s--;
        }
        t--;
    }
    return v1;
}