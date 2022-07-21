#include <bits/stdc++.h>
using namespace std;
int n,m;
int al[15][15];
void printAL();
void readData(){
	memset(al,0x7,sizeof(al));
	cin>>n>>m;
	for(int i=1;i<=n;i++) al[i][i]=0;
	for(int i=1;i<=m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		al[a][b]=w;
		al[b][a]=w;
	}	
	
}



int main(){
	freopen("shu_in.txt","r",stdin);
	readData();
	printAL();
	return 0;
} 





void printAL(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<setw(10)<<al[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
