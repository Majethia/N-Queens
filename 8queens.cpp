#include <iostream>

using namespace std;

class point
{
public:
    int x;
    int y;

    point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }

    point()
    {
        x = -1;
        y = -1;
    }
};

class Stack
{
public:
    point l[80], top;
    int len;

    Stack()
    {
        len = 0;
    }

    void push(point c)
    {
        l[len] = c;
        len += 1;
        top = c;
    }

    void pop()
    {
        len -= 2;
        top = l[len];
        len += 1;
    }
};

int check_valid(point q, point t)
{
    if (q.x == t.x)
        return 1;

    if (q.y == t.y)
        return 1;

    if (q.x - q.y == t.x - t.y)
        return 1;

    if (q.x + q.y == t.x + t.y)
        return 1;

    return 0;
}

int place(Stack s)
{
    if (s.len == 8)
    {
        cout<<"Solution found: "<<"\n";
        for (int k = 0; k < 8; k++)
        {
            cout <<s.l[k].x << "," << s.l[k].y << "\n"; 
        }
        cout<<"\n\n";
        return 0;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            bool choice;
            choice = true;
            point t(i, j);
            for (int k = 0; k < s.len; k++)
            {
                int valid;
                valid = check_valid(s.l[k], t);
                if (valid == 1)
                {
                    choice = false;
                    break;
                }
            }
            if (choice)
            {
                s.push(t);
                int a = place(s);
                if (a == 1)
                    s.pop();
                else
                    return 0;
            }
        }
    }
    return 1;
}

int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {   
            point p(i, j);
            Stack s;
            s.push(p);
            place(s);
        }
    }
    
    return 0;
}
