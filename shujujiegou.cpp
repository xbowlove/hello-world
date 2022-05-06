#include <iostream>
using namespace std;
template <typename T>
class array
{
    int *data;
    int length;

public:
    array(int n = 2)
    {
        data = new T[100];
        length = 0;
    }
    ~array()
    {
        delete[] data;
    }
    void add(T a)
    {
        data[length] = a;
        length++;
        return;
    }
    bool panduan(int i)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j] == data[i])
            {
                return 0;
            }
        }
        return 1;
    }
    int dif()
    {
        int n = 1;
        for (int i = 1; i < length; i++)
        {
            if (panduan(i))
            {
                n++;
            }
        }
        return n;
    }
};
int main()
{
    array<int> s1(5);
    s1.add(1);
    s1.add(3);
    s1.add(10);
    s1.add(20);
    s1.add(3);
    int m = s1.dif();
    printf("%d\n", m);
    return 0;
}