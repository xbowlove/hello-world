#include <iostream>
using namespace std;
template <typename T>
struct node
{
    T data;
    node<T> *next;
    node<T> *prior;
    node() : next(NULL), prior(NULL){};
    node(T a) : data(a), next(NULL), prior(NULL){};
};
template <typename T>
class dlinklist
{
    head1, head2 = node();
    node<T> *head4;

public:
    dlinklist(T *a, int n)
    {
        head = new node *;
        node *s = head;
        for (int i = 0; i < n; i++)
        {
            node<T> *p = new node *;
            p->data = a[i];
            s->next = p;
            p->prior = s;
            s = p;
        }
        p->next = NULL;
    }
    ~dlinklist(node<T> *head, int n)
    {
        node *p = head, *pre = head;
        for (int i = 0; i < n; i++)
        {
            p = pre->next;
            delete pre;
            pre = p;
        }
    }
    void display(node<T> *head)
    {
        node *p = head->next;
        while (p != NULL)
        {
            cout << p->data << endl;
        }
        return;
    }
};
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    dlinklist<int> head(a, 10);
}