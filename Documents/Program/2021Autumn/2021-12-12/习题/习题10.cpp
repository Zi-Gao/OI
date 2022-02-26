/*
枚举法，设i,j,k分别是a,b,c的对手，i,j,k取值范围为 'x','y','z'，
尝试所有取值组合是否符合配对要求即可求解。
*/
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	for(char i = 'x'; i <= 'z'; i++){
		for(char j = 'x'; j <= 'z'; j++){
			if(i != j){
				for(char k = 'x'; k <= 'z'; k++){
					if(i != k && j != k){
						if(i != 'x' && k != 'x' && k != 'z'){
							cout << "order is: a---" << i << "\t";
							cout << "b---" << j << "\t";
							cout << "c---" << k << "\n";
						}							
					}
				}
			}
		}
	}
	
	return 0;
}
