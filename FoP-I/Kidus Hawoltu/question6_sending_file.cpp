/*Question 6
A serial transmission line can transmit 960 characters a second. Write a program that will calculate how long it will take to 
send a file, given the file size. Try it on a 400MB (419,430,400 byte) file. Use appropriate units. (A 400MB file takes days.)
*/
#include <iostream>
using namespace std;
int main()
{
    int file_size;
    float time;
    cout<<"File size in bytes ";
    cin>>file_size;
    time = file_size/960;
    cout<<"To send this file it will take "<<int(time)<<" seconds";
    if (time>59)
        cout<<" = "<<time/60<<" minutes";
        if (time>3599)
            cout<<" = "<<time/3600<<" hours";
            if(time>86400)
                cout<<" = "<<time/86400<<" days";
    return 0;
}