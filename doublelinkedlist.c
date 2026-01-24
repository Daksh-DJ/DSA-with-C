#include<stdio.h>
#include<stdlib.h>
struct dlist{
int data;
struct dlist *prev;
struct dlist *next;
};

void append(struct dlist **q,int num);
void attabeg(struct dlist **q,int num);
void addafter(struct dlist **q,int num,int addf);
int count (struct dlist **q);
void display(struct dlist **q);
void delete(struct dlist **q,int n);
int main(){
struct dlist *p;
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
        printf(" enter 1 if you want to add element in the beginning \n enter 2 if you want to add element after a specific element \n enter 3 if you want to display all the elements\n enter 4 if you want to know the count\n enter 5 if you want to delete a element");
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
        case 5:printf("enter the element you want to delete");
                scanf("%d",&num);
                delete(&p,num);        
                break;
    }
    printf("Do you want to do some more operation if yes enter 1 or else enter 0");
    scanf("%d",&flag);

}
    return 0;
}

void append(struct dlist **q,int num){
    struct dlist *temp,*r; 
    temp=*q;
    if(*q==NULL){
        *q=(struct dlist *)malloc(1*sizeof(struct dlist));
        (*q)->data=num;
        (*q) ->next=NULL;
         (*q)->prev=NULL;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        r=(struct dlist *)malloc(1*sizeof(struct dlist));
        r->prev=temp;
        r->next=NULL;
        r->data=num;
        temp->next=r;
    }
}

void attabeg(struct dlist **q,int num){
    struct dlist *temp,*r;
    r=(struct dlist *)malloc(1*sizeof(struct dlist));
    temp=*q;
    temp->prev=r;
    r->data=num;
    r->next=temp;
    r->prev=NULL;
    *q=r;
}


void addafter(struct dlist **q,int num,int addf){
    struct dlist *temp;
    struct dlist *r;
    r=(struct dlist *)malloc(1*sizeof(struct dlist));

    temp=*q;
    for(int i=0;i<addf-1;i++){
        temp=temp->next;
        if(temp==NULL){
        printf("dont have this much data");
        return ;
    }
    }
   
   r->data=num;
   r->prev=temp;
   r->next=temp->next;
   if(temp->next!=NULL){
    temp->next->prev=r;
   }
    temp->next=r;
}

int count (struct dlist **q){
    struct dlist *temp;
    temp=*q;
    int i=0;
while(temp!=NULL){
    i++;
    temp=temp->next;
}
return i;
}

void display(struct dlist **q){
    struct dlist *temp;
    temp=*q;
while(temp!=NULL){
    printf("%d\n",temp->data);
    temp=temp->next;
}
}

void delete(struct dlist **q,int n){
    struct dlist *temp;
    temp=*q;

    while(temp!=NULL){
        if(temp->data==n){
            if(temp==*q){
                 *q=(*q)->next;
                  (*q)->prev=NULL;
                 
            }
            else{
                if(temp->next==NULL){
                    temp->prev->next=NULL;
                }
                else{
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                 }
                
            }
            free(temp);
            return;
        }
        temp=temp->next;
    }
    printf("There is no such element in the linked list");
}

