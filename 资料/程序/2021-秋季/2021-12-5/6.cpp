#include <cstdio>
#include <iostream>
using namespace std;
int main(){

	for(int A = 1;A <= 6;A++){
		for(int B = 1;B <= 6;B++){
			for(int C = 1;C <= 6;C++){
				for(int D = 1;D <= 6;D++){
					for (int E = 1;E <= 6;E++){
						for (int F = 1;F <= 6;F++){
							if(A != B && A != C && A !=D && A != E && A != F
									  && B != C && B !=D && B != E && B != F
												&& C !=D && C != E && C != F
														 && D != E && D != F
														 		   && E != F){
								if(( (A+B+C)==(C+D+E) )&&( (C+D+E)==(E+F+A) )&&(A < C && C <E)){
									cout << A << B << C << D << E << F << endl; 
									
								}
							}
						}

					}
				}
			}
		}
	}

	
	return 0;
}
