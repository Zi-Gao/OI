//BIT: Binary Index Tree---树状数组

int a[MAXN];
int s[MAXN];
for(int i=1;i<=n;i++){
	s[i]=s[i-1]+a[i]; 
}

int sum(int i,int j){ //计算[i,j]和 
	return s[j]-s[i-1];
}

int lowbit(int x){
	return x&(-x);
}

void updata(int i,int x){ //a[i]+x
	for(int pos=i;i<=)
	
}

int sum(int n){ //计算[1,n]的和 
	int s=0; 
	for(int pos=n;pos>=1;pos=pos-lowbit(i)){
		s=s+c[pos];
	}
	return s;
}

int query(int i,int j){
	return sum(i)-sum(j);
}

