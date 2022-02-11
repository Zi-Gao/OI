#include <cstdio>
#include <cmath>
/*cmath: ÊıÑ§¿â 
 *abs(int x)
 *fabs(float x)
 *sqrt(int x)
 */ 
using namespace std;
int main(){
	float f;
	
	f = 123.56;
	
	if(fabs(f - 123.56) < 1E-5)
		printf("yes")
	else
		printf("no")

	return 0;
}
