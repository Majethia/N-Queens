#include <iostream>
#include <vector>
#include <algorithm>

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
    friend bool operator== (const point& p1, const point& p2);
};

bool operator== (const point& p1, const point& p2)
{
    if (p1.x == p2.x && p1.y == p2.y)
    {
        return true;
    }
    return false;
}


class solution
{
    public:
    vector<point> sol;

    friend bool operator== (const solution& s1, const solution& s2);
};

bool operator== (const solution& s1, const solution& s2)
{
    bool contains = false;
    bool equal = true;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (s1.sol[i] == s2.sol[j])
            {
                contains = true;
                break;
            }
        }
        if (!contains)
        {
            equal = false;
            break;
        }
    }
    return equal;
}


vector<solution> res;

class Stack
{
public:
    point l[8], top;
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
        solution so;
        for (int k = 0; k < 8; k++)
        {
            so.sol.push_back(s.l[k]);  
        }
        bool push = false;
        
        for (auto& it : res)
        {
            if (it == so)
            {
                push = false;
                break;
            }
            else
                push = true;
        }
        if (res.size() == 0)
            push = true;

        if (push)
        {
            res.push_back(so);
            cout<<res.size();
            cout<<" Solution found: "<<"\n";
            for (int j = 0; j < 8; j++)
            {
                cout<<res[res.size()-1].sol[j].x<<","<<res[res.size()-1].sol[j].y<<"\n";
            }
            cout<<"\n\n";
            return 1;
        }
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
    // for (int i = 0; i < 8; i++)
    // {
    //     for (int j = 0; j < 8; j++)
    //     {   
    //         point p(i, j);
    //         Stack s;
    //         s.push(p);
    //         place(s);
    //     }
    // }
    Stack s;
    place(s);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout<<"Solution found: "<<"\n";
    //     for (int j = 0; j < 8; j++)
    //     {
    //         cout<<res[i].sol[j].x<<","<<res[i].sol[j].y<<"\n";
    //     }
    //     cout<<"\n\n";     
    // }
    cout<<res.size();
    
    
    return 0;
}
