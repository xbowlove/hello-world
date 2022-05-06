#include <iostream>
template <typename T>
struct stud
{
    T data;
    stud *next;
    stud() : next(NULL){};
    stud(T a) : data(a), next(NULL){};
};

template <typename T>
class Jiandan
{
public:
    stud<T> *head;
    stud<T> *tail;
    Jiandan()
    {
        head = new stud<T>;
        tail = head;
    }
    ~Jiandan()
    {
        stud<T> *p = head->next, *pre = head;
        while (p != NULL)
        {
            delete pre;
            pre = p;
            p = p->next;
        }
        delete p;
    }
    void add(T a)
    {
        stud<T> *p = new stud<T>;
        p->data = a;
        tail->next = p;
        tail = tail->next;
        tail->next = NULL;
    }
    void display()
    {
        stud<T> *p = head->next;
        while (p != NULL)
        {
            std::cout << p->data << "\n";
            p = p->next;
        }
    }
};

int main()
{
    Jiandan<int> ac;
    ac.add(1);
    ac.add(2);
    ac.display();
    return 0;
}