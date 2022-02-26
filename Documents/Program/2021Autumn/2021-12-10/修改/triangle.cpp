#include <cstdio>
using namespace std;
int main(){
    freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	
	int p,out=0;
	scanf("%d",&p);
	for(int a = 1;a <= 9;a++){
		for(int b = 1;b <= 9;b++){
			for(int c = 1;c <= 9;c++){
				if((a<b)&&(b<c)){
				}else{
					continue;
				}
				for(int d = 1;d <= 9;d++){
					for (int e = 1;e <= 9;e++){
						if(d<e){
							
						}else{
							continue;
						}
						for (int f = 1;f <= 9;f++){
							for (int g = 1;g <= 9;g++){
								if(f<g){
							
						}else{
							continue;
						}
								for (int h = 1;h <= 9;h++){
									for (int i = 1;i <= 9;i++){
										if(h<i){
							
						}else{
							continue;
						}
										if(a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i
												  && b != c && b != d && b != e && b != f && b != g && b != h && b != i
												  		    && c != d && c != e && c != f && c != g && c != h && c != i
														              && d != e && d != f && d != g && d != h && d != i
															 		            && e != f && e != g && e != h && e != i
															 		            		  && f != g && f != h && f != i
															 		            		  			&& g != h && g != i
															 		            		  					  && h != i){
											if((a+d+e+b)==(b+h+i+c)&&(b+h+i+c)==(a+g+f+c)&&(a+g+f+c)==p&&(a<b)&&(b<c)&&(d<e)&&(f<g)&&(h<i)){
												out++;
											}
										}
									}
								}
							}

						}
					}
				}
			}
		}
	}
	printf("%d",out);
	
    fclose(stdin);
	fclose(stdout); 
	return 0;
}
