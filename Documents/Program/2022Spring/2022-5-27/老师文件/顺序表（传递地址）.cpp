#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std; 
//˳���洢�ṹ
const int MAXSIZE = 80;  //Ԥ��Ĵ洢�ռ��������
typedef struct{
	int data[MAXSIZE];	//˳��洢�ռ�
	int last;			//��ǰ����Ϊlast�� last =-1Ϊ�ձ�
} SeqList;
//˳����ʼ����
SeqList *init_SeqList()
{ 
    SeqList *L;	
	L = new SeqList; //L = (SeqList *)malloc(sizeof(SeqList));
    L->last = -1;      
    cout << &L << endl;
    return L;    
}
//˳���������� 
void input(SeqList *L)
{
	L->last++;
	while(cin >> L->data[L->last])
		 L->last++;
	L->last--;
}

//˳������ 
void print(SeqList *L)
{
	for(int i = 0; i < L->last; i++)
		cout << L->data[i] << " ";	
	cout << endl << L->last + 1;
}

int main()
{
//	freopen("SeqList.in","r",stdin);
//	freopen("SeqList.out","w",stdout);
	
	SeqList *L;
	L = init_SeqList(); 
	cout << &L;
//	input(L);
//	print(L);
	
	delete L;  //free(L);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
