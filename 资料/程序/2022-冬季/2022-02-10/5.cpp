/***
 * @Author: Zi_Gao
 * @Date: 2022-02-10 14:30:42
 * @LastEditTime: 2022-02-10 15:20:25
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int abs(int x){
    return x>0?x:-x;
}
int main(){
    for(int a=1;a<=5;a++){
        for(int b=1;b<=5;b++){
            for(int c=1;c<=5;c++){
                for(int d=1;d<=5;d++){
                    for(int e=1;e<=5;e++){
                        if((a==b||a==c||a==d||a==e||b==c||b==d||b==e||c==d||c==e||d==e)||(a==1||b==2||c==3||d==4||e==5)||((a-b==-1)||(b-c==-1)||(c-d==-1)||(d-e==-1))||(((d==1)+(a==2)+(e==3)+(c==4)+(b==5))!=2)||((((d-a)==-1)+((a-e)==-1)+((e-c)==-1)+((c-b)==-1))!=2)){
                            continue;
                        }
                        char ch[6];
                        ch[a]='A';
                        ch[b]='B';
                        ch[c]='C';
                        ch[d]='D';
                        ch[e]='E';
                        printf("%c%c%c%c%c\n",ch[1],ch[2],ch[3],ch[4],ch[5]);
                        break;
                    }
                }
            }
        }
    }
}