#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int x,sum=0;
	cin >> x;
	while(x){
		sum += x%10;
		x /=10;
	}
	cout << sum;
	return 0;
}
