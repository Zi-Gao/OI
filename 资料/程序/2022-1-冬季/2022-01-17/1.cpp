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
    int N = rand()%(100-10+1)+10;
    int a[105];
    for(int i = 0;i < N;i++){//生成N个数
        a[i] = rand()%(1000-(-1000)+1)+(-1000);
    }
    //选择排序
    for(int i = 0;i < N;i++){
        int min = i;
        for(int j = i+1;j < N;j++){
            if(a[j] < a[i]){
                swap(a[j],a[i]);
            }
        }
    }
    //输出
    for(int i = 0;i < N;i++){
        printf("%d ",a[i]);
    }
	return 0;
}