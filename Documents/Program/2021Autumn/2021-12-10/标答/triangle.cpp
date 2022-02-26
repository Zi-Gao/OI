#include <cstdio>
using namespace std;

int main()
{
	int a,b,c,d,e,f,g,h,i,p,x1,x2,x3,total;
	int t[10]={0};
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	
	scanf("%d",&p);
	total=0;
	for(a=1;a<=9;a++)
	{
		for(f=a+1;f<=9;f++)
		{
			t[a]=1;
			t[f]=1;
			i=3*p-45-a-f;
			if(i>f && i<10)
			{
				t[i]=1;
				for(b=1;b<=9;b++)
				{
					if(0==t[b])
					{
						t[b]=1;
						d=p-a-f-b;
						if( b<d && d<10 && 0==t[d])
						{
							t[d]=1;
							for(g=1;g<=9;g++)
							{
								if(0==t[g])
								{
									t[g]=1;
									h=p-f-i-g;
									if( g<h && h<10 && 0==t[h])
									{
										t[h]=1;
										for(c=1;c<=9;c++)
										{
											if(0==t[c])
											{
												t[c]=1;
												e=p-a-i-c;
												if( c<e && e<10 && 0==t[e])
													total++;
											    t[c]=0;
											}
										}
										t[h]=0;
									}
								    t[g]=0;	
								}
							}
							t[d]=0;  
						}
						t[b]=0;
					}
				t[i]=0;	
				}
			}
			t[a]=0;
			t[f]=0;
		}
	}
	
	printf("%d",total);
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
