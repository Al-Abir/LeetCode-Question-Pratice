#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
class Stack
{
    int arr[4];
    int id = -1;

public:
    void push(int num)
    {
        if (id < 3)
        {
            arr[++id] = num;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
        }
    }

    void pop()
    {
        if (id >= 0)
        {
            id--;
        }
        else
        {
            cout << "Stack OverFlow" << endl;
        }
    }

    int top()
    {
        if (id >= 0)
        {
            return arr[id];
        }
        else
        {

            cout << "Stack OverFlow";
            return -1;
        }
    }

    bool isEmpty()
    {
        return id == -1;
    }

    void print()
    {
        for (int i = id; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.top() << endl;
    cout << (s.isEmpty() ? "YES" : "NO") << endl;
    s.print();

    return 0;
}