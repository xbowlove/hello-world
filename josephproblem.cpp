#include <iostream>
template <typename T>
struct stud
{
    T data;
    stud<T> *next;
    stud() : next(NULL){};
    stud(int a) : data(a), next(NULL){};
};
template <typename T>
class Joseph
{
public:
    stud<T> *head;
    Joseph()
    {
        head = new stud<T>;
        head->next = head;
    }
    ~Joseph()
    {
        stud<T> *pre, *p;
        pre = head;
        p = pre->next;
        while (pre != head)
        {
            pre = p;
            p = pre->next;
            delete pre;
        }
        delete head;
    }
    void build(T i)
    {
        stud<T> *r = head;
        stud<T> *p = new stud<T>;
        p->data = i;
        p->next = r->next;
        r->next = p;
        r = p;
    }
    void del(stud<T> *p)
    {
        stud<T> *pre = head;
        for (int i = 0;; i++)
        {
            if (pre->next == p)
            {
                pre->next = p->next;
                delete p;
                break;
            }
            pre = pre->next;
        }
        return;
    }
    void joseph()
    {
        int m = 1;
        stud<T> *p = head;
        while (p != NULL)
        {
            if (p == head)
            {
                if (p->next == head)
                {
                    return;
                }
                else
                {
                    p = p->next;
                }
            }
            else
            {
                if (m == 3)
                {
                    stud<T> *pre = p->next;
                    std::cout << p->data << " ";
                    del(p);
                    p = pre;
                    m = 1;
                }
                else
                {
                    p = p->next;
                    m++;
                }
            }
        }
    }
};
int main()
{
    Joseph<int> ac;
    for (int i = 0; i < 6; i++)
    {
        ac.build(i);
    }
    ac.joseph();
    return 0;
}