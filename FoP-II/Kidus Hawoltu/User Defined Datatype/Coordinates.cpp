#include <iostream>
using namespace std;

struct Coordinate{
    double x;
    double y;
};

Coordinate read();
void print(Coordinate);

int main(){
    Coordinate point1;
    point1 = read();
    print(point1);
    return 0;
}

Coordinate read(){
    Coordinate coordinate;
    cout<<"Enter the x coordinate: ";
    cin>>coordinate.x;
    cout<<"Enter the y coordinate: ";
    cin>>coordinate.y;
    return coordinate;
}

void print(Coordinate coordinate){
    cout<<"("<<coordinate.x<<", "<<coordinate.y<<")"<<endl;
}
