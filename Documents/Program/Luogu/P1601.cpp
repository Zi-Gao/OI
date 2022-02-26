/***
 * @Author: Zi_Gao
 * @Date: 2022-02-20 14:19:43
 * @LastEditTime: 2022-02-20 14:32:42
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
using namespace std;
inline int read();
void plus();
int a[1000],b[1000],c[1000];
int main(){
    char temp[1000];
    scanf("%s",&temp);
    int j=0;
    for(int i=strlen(temp)-1;i>=0;i--){
        a[j]=temp[i]-'0';
        j++;
    }

    scanf("%s",&temp);
    j=0;
    for(int i=strlen(temp)-1;i>=0;i--){
        b[j]=temp[i]-'0';
        j++;
    }
    plus();
    //output c
    bool flag=false;
    for(int i=999;i>=0;i--){
        if(flag){
            printf("%d",c[i]);
            continue;
        }else{
            if(i==0){
                printf("%d",c[i]);
                continue;
            }
            if(c[i]!=0){
                flag=true;
                printf("%d",c[i]);
            }
        }
    }


    return 0;
}
void plus(){
    for(int i=0;i<1000;i++){
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
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