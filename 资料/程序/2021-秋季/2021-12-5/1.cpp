#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
//����� 
using namespace std;
int main(){
	int a;
	srand((unsigned int)time(NULL));
	for(;;){
		
		a=rand();
		cout << a << endl;
	}
	

	return 0;
}
