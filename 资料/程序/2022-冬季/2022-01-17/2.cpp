/***
 * @Author: Zi_Gao
 * @Date: 2022-01-17 16:02:25
 * @LastEditTime: 2022-01-17 16:08:40
 * @LastEditors: Zi_Gao
 * @Description: 
 */
/***
 * @Author: Zi_Gao
 * @Date: 2022-01-17 15:43:35
 * @LastEditTime: 2022-01-17 15:53:31
 * @LastEditors: Zi_Gao
 * @Description: 排序
 */
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int main(){
    //生成数据
    srand(time(NULL));
    int a[10];
    int ai=0;
    int b[10];
    int bi=0;
    for(int i = 0;i < 10;i++){//生成N个数
        int irand=rand()%(100-(0)+1)+(0);
        if(irand%2==0){
            a[ai]=irand;
            ai++;
        }else{
            b[bi]=irand;
            bi++;
        }
    }
    //选择排序
    for(int i = 0;i < ai;i++){
        int min = i;
        for(int j = i+1;j < ai;j++){
            if(a[j] < a[i]){
                swap(a[j],a[i]);
            }
        }
    }
    for(int i = 0;i < bi;i++){
        int min = i;
        for(int j = i+1;j < ai;j++){
            if(b[j] > b[i]){
                swap(b[j],b[i]);
            }
        }
    }
    //输出
    for(int i = 0;i < bi;i++){
        printf("%d ",b[i]);
    }
    printf("\n");
    for(int i = 0;i < ai;i++){
        printf("%d ",a[i]);
    }
	return 0;
}