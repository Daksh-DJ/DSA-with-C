#include<stdio.h>
#include<stdlib.h>

struct list{
int val;
int power;
struct list *next;
};

void append(struct list **q,int num,int power);
void add(struct list **p,struct list **q,struct list **r);
void display(struct list **q);

int main(){
    return 0;
}

void append(struct list **q,int num,int power){
    struct list *temp,*r;
    if((*q)!=NULL){
        temp=(*q);
        while(temp!=NULL){
            if(temp->power==power){
                temp->val=temp->val+num;
                 return ;
            }
            temp=temp->next;
        }
       
    }
    if((*q)==NULL){
        temp=(struct list *)malloc(sizeof(struct list));
        temp->val=num;
        temp->power=power;
        temp->next=NULL;
        (*q)=temp;
        return ;
    }
    else{
        temp=(*q);
        while(temp->next!=NULL){
            temp=temp->next;
        }
        r=(struct list *)malloc(sizeof(struct list));
        r->power=power;
        r->val=num;
        r->next=NULL;
        temp->next=r;
        return ;
    }
}

void add(struct list **p,struct list **q,struct list **r){
    struct list *a,*b;
    int sum;
    a=(*p);
    b=(*q);
    while(a!=NULL&&b!=NULL){
        if(a->power==b->power){
            sum=a->val+b->val;
            append(r,sum,a->power);
            a=a->next;
            b=b->next;
        }
        else if(a->power>b->power){
            append(r,a->val,a->power);
            a=a->next;
        }
        else if(a->power<b->power){
            append(r,b->val,b->power);
            b=b->next;
        }
    }
    while(a!=NULL){
        append(r,a->val,a->power);
        a=a->next;
    }
    while(b!=NULL){
        append(r,b->val,b->power);
        b=b->next;
    }
    return ;
}

void display(struct list **q){
    struct list *temp;
    temp=(*q);
    while(temp!=NULL){
        printf("%d^%d",temp->val,temp->power);
        if(temp->val>=0){
            printf(" + ");
        }
        temp=temp->next;
    }
    return ;
}