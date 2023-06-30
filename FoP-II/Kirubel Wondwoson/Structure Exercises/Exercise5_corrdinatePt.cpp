#include <iostream>
using namespace std;
struct coordinatePt
{
    float x, y;
};
coordinatePt point;
coordinatePt read();
void print(coordinatePt);
int main()
{     
    coordinatePt p1 , p2;
    p1 = read();
    print(p1);
    return 0;
}
coordinatePt read()
{
    cout << "Enter x value : ";
    cin >> point.x;
    cout << "Enter y value : ";
    cin >> point.y;
    return point;
}
void print(coordinatePt point)
{
    cout << "(x , y) = (" << point.x << "," << point.y << ")";
}