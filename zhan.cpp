#include <iostream>
template <typename T>
class Zhan
{
public:
    T *array;
    int top, max = 16;
    Zhan()
    {
        array = new T[max];
    }
    ~Zhan()
    {
        delete[] array;
    }
    bool empty()
    {
        return top == -1;
    }
    bool push(T a)
    {
        if (top == max)
        {
        }
        top++;
        array[top] = a;
    }
    bool pop(T &e)
    {
        if (empty())
        {
            return false;
        }
        e = array[top];
        top--;
        return true;
    }
    bool gettop(T &e)
    {
        if (empty())
        {
            return false;
        }
        e = array[top];
        return true;
    }
};