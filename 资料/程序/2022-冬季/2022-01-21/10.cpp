/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 15:58:34
 * @LastEditTime: 2022-01-21 16:40:01
 * @LastEditors: Zi_Gao
 * @Description: 链表
 */
#include <cstdio>
struct node{
    int data;
    node *next;
};
node *create();
node *dele(node *head);
void print(node *head);
int main(){
    node *head=create();
    print(head);
    return 0;
}
node *create(){//创建链表
    node *head,*temp;
    int num,n=0;
    head=new node;
    temp=head;
    scanf("%d",&num);
    while(num!=-1){
        n++;
        temp->data=num;//temp->data = temp.data
        temp->next=new node;
        temp=temp->next;
        scanf("%d",&num);
    }
    if(n==0){
        head=NULL;
    }else{
        temp->next=NULL;
    }
    return head;
}
// node *dele(node *head){
//     node *temp,*follow;
//     temp=head;
//     if(head==NULL){
//         return head;
//     }
//     if(head->num==NULL){}
//     return head;
// }
void print(node *head){
    while(head->next!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}