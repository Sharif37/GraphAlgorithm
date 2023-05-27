#include<bits/stdc++.h>
using namespace std ;

struct node {
    int value=0 ;
    node *left=NULL  ;
    node *right=NULL ;
};

 node *create(node *current,int value)
{
    node *newnode=new node();
    newnode->value=value ;
    newnode->left=NULL ;
    newnode->right=NULL ;

    if(current==NULL)
        return newnode ;

    node *temp=current;
    node *next=current ;
    while(next!=NULL)
    {
        temp=next ;
        if(value > next->value )
        {
            next=next->right ;
        }else
        {
            next=next->left ;
        }
    }
    if(value > temp->value)
    {
        temp->right=newnode ;

    }
    else
    {
        temp->left=newnode ;
    }

    return current ;
}
void post_order(node *t)
{
    if(t==NULL)
        return ;
    post_order(t->left);
    post_order(t->right);
    printf("%d\n",t->value );
}

int main()
{
 node *current=NULL ;
 int a  ;
 while(scanf("%d",&a)!=EOF)
 {
    current= create(current,a);
 }
 node *t=current ;
 post_order(t);


}
