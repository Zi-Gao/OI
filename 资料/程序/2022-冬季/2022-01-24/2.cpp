/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 15:18:11
 * @LastEditTime: 2022-01-24 16:26:32
 * @LastEditors: Zi_Gao
 * @Description: 二分搜索
 */
#include <cstdio>

using namespace std;

int main(){
    int a[5]={1,2,2,4,5};
    int x=2;
    int l=0,r=4;
    while(l<r){
        int mid=l+(r-l)/2;
        if(a[mid]>=x){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    printf("%d\n",l);
    while(l<r){
        int mid=1+(r+1-l)/2;
        if(a[mid]<=x){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    printf("%d\n",r);
}
