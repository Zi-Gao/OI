//BIT: Binary Index Tree---��״����

int a[MAXN];
int s[MAXN];
for(int i=1;i<=n;i++){
	s[i]=s[i-1]+a[i]; 
}

int sum(int i,int j){ //����[i,j]�� 
	return s[j]-s[i-1];
}

int lowbit(int x){
	return x&(-x);
}

void updata(int i,int x){ //a[i]+x
	for(int pos=i;i<=)
	
}

int sum(int n){ //����[1,n]�ĺ� 
	int s=0; 
	for(int pos=n;pos>=1;pos=pos-lowbit(i)){
		s=s+c[pos];
	}
	return s;
}

int query(int i,int j){
	return sum(i)-sum(j);
}

