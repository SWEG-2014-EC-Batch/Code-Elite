#include<iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};

Point read()
{
    Point p;
    cout << "Enter x coordinate: ";
    cin >> p.x;
    cout << "Enter y coordinate: ";
    cin >> p.y;
    return p;
}

void print(Point p)
{
    cout << "The point is (" << p.x << ", " << p.y << ")" << endl;
}

int main()
{
    Point p = read();
    print(p);
    return 0;
}
