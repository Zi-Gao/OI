/*
�����趴ͥ�����������۶������̫���ֱ��ñ���A��B��C��D��ʾ��ÿ��������ȡֵ��1��4��
��Ϊÿ��ֻ�����һ�������ԣ����ǵ��������Ա�ʾΪ��
	�ף�(A==1)+(B==4)+(C==3) == 1
	�ң�(B==1)+(A==4)+(C==2)+(D==3) == 1
	����(B==4)+(A==3) == 1
	����(C==1)+(D==4)+(B==2)+(A==3) == 1
	ֻ����������������ʱ�������ҵ���ȷ�𰸡�
*/
#include <cstdio>
#include <iostream> 
using namespace std;

int main(){		
	for(int a = 1; a <= 4; a++){
		for(int b = 1; b <= 4; b++){
			for(int c = 1; c <= 4; c++){
		      int d = 10 - a - b - c;
		      if(24 == a * b * c * d){
		      	int p1, p2, p3, p4;
				p1 = (1==a) + (4==b) + (3==c);
	            p2 = (1==b) + (4==a) + (2==c) + (3==d);
	            p3 = (4==b) + (3==a);
	            p4 = (1==c) + (4==d) + (2==b) + (3==a);
	            if(1==p1 && 1==p2 && 1==p3 && 1==p4){
					cout << "Dongting Lake:" << a << endl;
					cout << "Hongze Lake:" << b << endl;
					cout << "Panyang Lake:" << c << endl;
					cout << "Tai Lake:" << d << endl;				 
	            }
		      }
		    }	
		}		    
	}
	  
	return 0;
}
