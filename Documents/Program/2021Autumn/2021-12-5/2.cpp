#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime> 
//����� 
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
			cout << "���� ����" <<i<<"�λ���"<< endl; 
		}
		if(x<a){
			cout << "С�� ����" <<i<<"�λ���"<< endl; 
		}
	}
	cout << "�����Ϊ" << a; 
	return 0;
}
