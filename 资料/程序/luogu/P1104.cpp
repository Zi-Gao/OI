/***
 * @Author: Zi_Gao
 * @Date: 2022-02-20 14:55:46
 * @LastEditTime: 2022-02-20 15:12:06
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct bir{
    char name[25];
    int y,m,d,i;
};
inline int read();
inline bool cmp(bir a,bir b);

int main(){
    int n=read();
    bir arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i].name >> arr[i].y >> arr[i].m >> arr[i].d;
        arr[i].i=i;
    }
    sort(arr,arr+n,cmp);
    //output
    for(int i=0;i<n;i++){
        printf("%s\n",arr[i].name);
    }
    return 0;
}
inline bool cmp(bir a,bir b){
    if(a.y==b.y){
        if(a.m==b.m){
            if(a.d==b.d){
                return a.i>b.i;
            }else{
                return a.d<b.d;
            }
        }else{
            return a.m<b.m;
        }
    }else{
        return a.y<b.y;
    }
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}