#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int a,b;
	cin >> a >> b;
	if(a> b) swap(a,b);
	int o=a;
	int i=1;
	while (o%b!=0){
		o=a*i;
		i++;
	}
	cout << o;
	
	return 0;
}
