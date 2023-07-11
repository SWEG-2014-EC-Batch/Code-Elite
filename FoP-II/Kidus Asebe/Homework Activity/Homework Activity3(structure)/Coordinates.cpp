#include <iostream>
using namespace std;

struct coordinate {
    int x;
    int y;
};
coordinate read(){
    coordinate point;
    cout<<"Enter the x coordinate: ";
    cin>>point.x;
    cout<<"Enter the y coordinate: ";
    cin>>point.y;
    return point;
}
void display(coordinate point){
    cout<<"The coordinates are: ("<<point.x<<","<<point.y<<")";
}

int main(){
    display(read());
}
