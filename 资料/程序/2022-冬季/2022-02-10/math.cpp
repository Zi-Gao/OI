/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 16:49:31
 * @LastEditTime: 2022-02-11 14:11:53
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <ctime>
using namespace std;
int c(int a,int b){
    int out=a;
    b--;
    while(b){
        out+=a;
        b--;
    }
    return out;
}
int main(){
    // printf("%d",c(10000,10000));
    unsigned long long int iMAX=0xFFFFFFFFULL;
    // unsigned long long int iMAX=0xFFFFFFFFULL;
    double Times=0;
    int test;

    printf("test start\n");
    clock_t start_time, end_time;
    start_time = clock();

    for(unsigned long long int i=0;i<iMAX;i++){
        // test=9973<<13;
        test=9973*8192;
    }

    end_time = clock();
    Times+=((double)(end_time - start_time) / CLOCKS_PER_SEC);

    printf("时间:%f\n", Times);
	return 0;
}