/***
 * @Author: Zi_Gao
 * @Date: 2022-01-17 15:06:24
 * @LastEditTime: 2022-01-17 16:41:43
 * @LastEditors: Zi_Gao
 * @Description:
 */
#include <cstdio>
using namespace std;
int main(){
    // freopen("*.in","r",stdin);
	// freopen("*.out","w",stdout);

	int a;
	scanf("%d",&a);
	while(a-- ){
		int n;
		scanf("%n",&n);
		if(n % 2 == 0){
			if(n % 4 != 0){
				printf("%d %d\n",n/4+1,n/2);
			}else{
				printf("%d %d\n",n/4,n/2);
			}
		}else{
			printf("0 0");
		}
	}

    fclose(stdin);
	fclose(stdout);
	return 0;
}