/*
ö�ٷ�����i,j,k�ֱ���a,b,c�Ķ��֣�i,j,kȡֵ��ΧΪ 'x','y','z'��
��������ȡֵ����Ƿ�������Ҫ�󼴿���⡣
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
