#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
using namespace std;
bool tried(int, int);
int migong[4][4];
int main()
{
    stack<int, vector<int>> pathx;
    stack<int, vector<int>> pathy;
    stack<int, vector<int>> number;
    memset(migong, 0, sizeof(int));
    migong[0][1] = 1;
    migong[1][2] = 1;
    migong[1][3] = 1;
    migong[2][1] = 1;
    pathx.push(0);
    pathy.push(0);
    number.push(0);
    while (pathx.top() != 3 || pathy.top() != 3)
    {
        int a = pathx.top(), b = pathy.top();
        if (number.top() == 0 && a + 1 < 4 && tried(a + 1, b))
        {
            pathx.push(a + 1);
            pathy.push(b);
            migong[a][b] = 1;
            a++;
            number.pop();
            number.push(1);
            number.push(0);
            continue;
        }
        if (number.top() == 1 && b + 1 < 4 && tried(a, b + 1))
        {
            pathx.push(a);
            pathy.push(b + 1);
            migong[a][b] = 1;
            b++;
            number.pop();
            number.push(2);
            number.push(0);
            continue;
        }
        if (number.top() == 2 && a - 1 > -1 && tried(a - 1, b))
        {
            pathx.push(a - 1);
            pathy.push(b);
            migong[a][b] = 1;
            a--;
            number.pop();
            number.push(3);
            number.push(0);
            continue;
        }
        if (number.top() == 3 && b - 1 > -1 && tried(a, b - 1))
        {
            pathx.push(a);
            pathy.push(b - 1);
            migong[a][b] = 1;
            b--;
            number.pop();
            number.push(4);
            number.push(0);
            continue;
        }
        else
        {
            if (number.top() < 3)
            {
                int e = number.top();
                number.pop();
                number.push(e + 1);
                continue;
            }
            else
            {
                migong[pathx.top()][pathy.top()] = 0;
                pathx.pop();
                pathy.pop();
                number.pop();
            }
        }
    }
    cout << "路径为:" << endl;
    while (pathx.empty() != true)
    {
        cout << pathx.top() << " " << pathy.top() << endl;
        pathx.pop();
        pathy.pop();
    }
    return 0;
}
bool tried(int a, int b)
{
    return migong[a][b] == 0;
}