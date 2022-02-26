#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	for(int A = 1;A <= 9;A++){
		for(int B = 0;B <= 9;B++){
			for(int C = 0;C <= 9;C++){
				for(int D = 0;D <= 9;D++){
					for (int E = 1;E <= 9;E++){
						if(A != B && A != C && A !=D && A != E
								  && B != C && B !=D && B != E
											&& C !=D && C != E
													 && D != E){
							if((1000*A+100*B+10*C+D)*E == (1000*D+100*C+10*B+A)){
								cout << A << B << C << D << E; 
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
