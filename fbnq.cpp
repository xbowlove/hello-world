#include <iostream>
#include <string.h>
#include "gaojingduchengfavector.h"
#include "gaojingdujiafavector.h"
#include <vector>
using namespace std;
int main()
{
    vector<int> A;
    vector<int> B;
    vector<int> C;
    vector<int> D;
    A.push_back(1);
    B.push_back(1);
    C.push_back(1);
    D.push_back(0);
    for (int i = 0; i < 20; i++)
    {
        vector<int> a;
        vector<int> b;
        vector<int> c;
        vector<int> d;
        a = jiafa(chengfa(A, A), chengfa(B, C));
        b = jiafa(chengfa(A, B), chengfa(B, D));
        c = jiafa(chengfa(A, C), chengfa(C, D));
        d = jiafa(chengfa(B, C), chengfa(D, D));
        A.clear();
        B.clear();
        C.clear();
        D.clear();
        A = a;
        B = b;
        C = c;
        D = d;
        a.clear();
        b.clear();
        c.clear();
        d.clear();
    }
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i];
    }
    return 0;
}