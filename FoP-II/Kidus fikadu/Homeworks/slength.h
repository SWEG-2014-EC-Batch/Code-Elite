#include <iostream>
using namespace std;
#ifndef slelgth
#define slength
int slen(string a) {
	int c=0, k = 0,l=0,v=0;
	
	do {
		
		k++;
		
	} while (a[k]>32 && a[k]<126);
	//cout <<"string length : "<<k<<endl ;
	return k;
}
#endif


