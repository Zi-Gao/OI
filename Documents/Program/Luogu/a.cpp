#include"iostream"
#include"cstdio"
#include"algorithm"//为了用sort快排
using namespace std;

struct a  
{
 int b,num;//定义结构体a      
};
bool cmp(a x,a y)//定义“小于”运算符
{
 return x.b<y.b;    
}
int main()
{
		freopen("order.in","r",stdin);
 struct a a[1010];//定义结构体数组
 int n,i,j;
 double time=0;
 cin>>n;    
 for(i=1;i<=n;i++)   
  {
   cin>>a[i].b;
   a[i].num=i;//序号存起来              
  } 
 sort(a+1,a+n+1,cmp);//排序
  for(i=1;i<=n;i++)
  {
   cout<<a[i].num<<" "; //先把简单的做了，输入由小到大的编号
  }
  cout<<endl;//要换行
  for(j=n-1;j>=1;j--) //等待人数的计数器，由n-1开始
  {
   i=n-j;//这是个规律，当前最少时间的人序号和要等待的人数之和=n
   time+=a[i].b*j; //累加                  
  }
 printf("%.2lf",time/n);//算平均，保留两位小数
  return 0; 
}
