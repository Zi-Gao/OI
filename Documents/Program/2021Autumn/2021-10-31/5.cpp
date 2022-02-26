#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int a;
	cin >> a;
	if(a%100!=0 && a%4==0 ){
		cout << "yes";
		return 0;
	}
	if(a%400==0){
		cout << "yes";
		return 0;
	}	
	cout << "no";
	return 0;
}
