#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
int main(){
	double a;
	double i=1;
	while(true){
		a+=1/(i*i);
		printf("%lf\n",sqrt(a*6));
		i++;
	}
	return 0;
}
