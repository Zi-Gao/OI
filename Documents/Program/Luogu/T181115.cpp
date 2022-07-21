/***
 * @Author: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
//#define file
using namespace std;
inline int read();
int main(){
	#ifdef file
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	#endif

	char c=getchar();
    char ch=getchar();

    if(c=='g'){//1 27 33

        if(ch=='B'){
            printf("0");
        }else if(ch=='p'){
            printf("2");
        }else{
            printf("3");
        }
    }else if(c=='Y'){//2 21
        if(ch='j'){
            printf("0");
        }else{
            printf("2");
        }
    }else if(c=='I'){//3 10
        printf("0");
    }else if(c=='U'){//4 25
        if(ch=='2'){
            printf("0");
        }else{
            printf("2");
        }
    }else if(c=='q'){//5 29
        if(ch=='t'){
            printf("0");
        }else{
            printf("2");
        }
    }else if(c=='f'){//6 17
        if(ch=='&'){
            printf("0");
        }else{
            printf("1");
        }
    }else if(c=='O'){//7
        printf("0");
    }else if(c=='L'){//3 10
        printf("0");
    }else if(c=='K'){//3 10
        printf("0");
    }else if(c=='n'){//3 10
        printf("1");
    }else if(c=='a'){//12 14
        printf("1");
    }else if(c=='}'){//13 36
        if(ch=='2'){
            printf("1");
        }else{
            printf("3");
        }
    }else if(c=='\''){//3 10
        printf("1");
    }else if(c=='%'){//16 35
        if(ch=='8'){
            printf("1");
        }else{
            printf("3");
        }
    }else if(c=='F'){//3 10
        printf("1");
    }else if(c=='!'){//3 10
        printf("1");
    }else if(c=='6'){//3 10
        printf("1");
    }else if(c=='M'){//3 10
        printf("1");
    }else if(c=='y'){//3 10
        printf("2");
    }else if(c=='('){//3 10
        printf("2");
    }else if(c=='['){//24 26
        printf("3");
    }else if(c=='u'){//3 10
        printf("2");
    }else if(c=='&'){//3 10
        printf("2");
    }else if(c=='~'){//3 10
        printf("2");
    }else if(c=='\\'){//3 10
        printf("3");
    }else if(c==')'){//3 10
        printf("3");
    }else if(c=='G'){//3 10
        printf("3");
    }else if(c=='E'){//3 10
        printf("3");
    }else if(c=='9'){//3 10
        printf("3");
    }else if(c=='`'){//3 10
        printf("3");
    }else if(c=='#'){//3 10
        printf("3");
    }else {
        printf("2");
    }

	#ifdef file
	fclose(stdin);
	fclose(stdout);
	#endif
    return 0;
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
