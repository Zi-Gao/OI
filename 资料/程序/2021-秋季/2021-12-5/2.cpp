#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime> 
//随机数 
using namespace std;
int main(){
	int a,x;
	srand((unsigned int)time(NULL));
	a=rand()%(100-1)+1;
	for(int i=5;i>=0;i--){
		
		cin >> x;
		if(i==0){
			break;
		}
		if(x==a){
			cout << "Yes" << endl;
			break;
		}
		if(x>a){
			cout << "大了 还有" <<i<<"次机会"<< endl; 
		}
		if(x<a){
			cout << "小了 还有" <<i<<"次机会"<< endl; 
		}
	}
	cout << "随机数为" << a; 
	return 0;
}
