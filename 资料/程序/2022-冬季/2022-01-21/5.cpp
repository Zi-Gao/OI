/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 10:48:32
 * @LastEditTime: 2022-01-21 11:13:18
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define MAX 100
void swapstr(char *p,int len){
    for(int i=0;i<len/2;i++){
        char tmp=p[i];
        p[i]=p[len-i-1];
        p[len-i-1]=tmp;
    }
}
int main(){
    char in[MAX]={};
    char *p=in;
    int len=0;
    for(int i=0;i<MAX;i++){
        in[i]=getchar();
        if(in[i]=='\n'){
            break;
        }
        len++;
    }
    swapstr(p,len);
    for(;*p!='\0';p++){
        if(*p==' '){
            continue;
        }else{
            char* i=p;
            for(;*i!=' '&&*i!='\n';i++){
            }
            swapstr(p,(i-p));
            p=i;
        }
    }
    for(int i=0;i<len;i++){
        putchar(in[i]);
    }
    return 0;
}