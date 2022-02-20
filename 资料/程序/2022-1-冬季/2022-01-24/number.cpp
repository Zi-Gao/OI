/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 16:10:47
 * @LastEditTime: 2022-01-25 08:20:59
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
void find_sum(int a[],int n,int m){//尺取法
    sort(a,a+n);
    int l=0,r=n-1;
    while(l<r){
        int sum=a[l]+a[r];
        if(sum>m){
            r--;
        }
        if(sum<m){
            l++;
        }
        if(sum==m){
            printf("%d %d\n",a[l],a[r]);
            l++;
        }
    }
}
int main(){
    // freopen("number.in","r",stdin);
    // freopen("number.out","w",stdout);
    int n,sum;
    scanf("%d",&n);
    scanf("%d",&sum);
    int a[100100]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    find_sum(a,n,sum);
    sort(a,a+n-1);
    for(int i=0;i<n;i++){
        int x=sum-a[i];
        int l=i,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(a[mid]>=x){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        if(a[l]==x){
            printf("%d %d\n",a[i],a[l]);
        }
    }
}