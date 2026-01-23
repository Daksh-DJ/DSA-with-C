#include<stdio.h>
#include<stdlib.h>
struct list{
    int data;
    struct list *link;
};
void append(struct list **q,int num);
void attabeg(struct list **q,int num);
void addafter(struct list **q,int num,int af);
void display(struct list **q);
int count (struct list **q);
void delete(struct list **q,int num);
int main(){
    struct list *p;
    p=NULL;
    int n,num,option,flag=1;
    printf("enter how many elements you want to insert in linked list");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("enter the %d element",i);
        scanf("%d",&num);
        append(&p,num);
    }
    
    while(flag!=0){
        printf(" enter 1 if you want to add element in the beginning \n enter 2 if you want to add element after a specific element \n enter 3 if you want to display all the elements\n enter 4 if you want to know the count");
        scanf("%d",&option);
    switch (option){
        case 1:printf("enter what you want element you want to add at the beginning of the list");
                scanf("%d",&num);
                attabeg(&p,num);
                break;
        case 2:printf("enter the element and after what you want to put the element");
                scanf("%d%d",&num,&n);
                addafter(&p,num,n);
                break;
        case 3:display(&p);
                break;
        case 4:printf("the number of element is:%d\n",count(&p));
                break;
    }
    printf("Do you want to do some more operation if yes enter 1 or else enter 0");
    scanf("%d",&flag);

}
    return 0;
}

void append (struct list **q,int num){
struct list *temp,*r;
if(*q==NULL){
    temp=(struct list *)malloc(1*sizeof(struct list));
    temp->data=num;
    temp->link=NULL;
    *q=temp;
}
else{
    temp=*q;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    r=(struct list *)malloc(1*sizeof(struct list));
    r->data=num;
    r->link=NULL;
    temp->link=r;

}
}

void attabeg(struct list **q,int num){
    struct list *temp;
    temp=(struct list *)malloc(1*sizeof(struct list));
    temp->data=num;
    temp->link=*q;
    *q=temp;
}
void addafter(struct list **q,int num,int af){
    struct list *temp,*r;
    temp=(struct list *)malloc(1*sizeof(struct list));
    temp=*q;
   for(int i=0;i<af;i++){
    temp=temp->link;
    if(temp->link==NULL){
        printf("there is not that many elements");
        return ;
    }
   }
r=(struct list *)malloc(1*sizeof(struct list));
r->data=num;
r->link=temp->link;
temp->link=r;
}


void display(struct list **q){
    struct list *temp;
    temp=(struct list *)malloc(1*sizeof(struct list));
    temp=*q;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
}

int count (struct list **q){
 struct list *temp;
    temp=(struct list *)malloc(1*sizeof(struct list));
    temp=*q;
    int i=0;
    while(temp!=NULL){
       i++;
        temp=temp->link;
    }
    return i;
}

void delete(struct list **q,int num){
    struct list *temp,*r;
    temp=(struct list *)malloc(1*sizeof(struct list));
    r=(struct list *)malloc(1*sizeof(struct list));
    temp=*q;
    while(temp!=NULL){
        if (temp->data==num){
            if(temp==*q){
                *q=temp->link;
            }
            else {
               r->link=temp->link;
               free(temp);
               return ;
            }
        }
        else{
        r=temp;
        temp=temp->link;
    }
    }
    
}