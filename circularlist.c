#include<stdio.h>
#include<stdlib.h>

struct clist{
int data;
struct clist *link;
};
void append(struct clist **q,int num);
void attabeg(struct clist **q,int num);

void add(struct clist **q,int num,int loc);
void delete_first(struct clist **q);
void delete_last(struct clist **q);
void delete(struct clist **q,int loc);
void display(struct clist **q);
int main(){
    struct clist *head = NULL;
    int a,flag=1,num,loc;
    while(flag==1){
        printf("enter 1 if you want to add element at the end\nenter 2 if you want to add data at the begining\nenter 3 if you want to add data in other location\nenter 4 if you want to delete the first element\nenter 5 if you want to delete the last element\nenter 6 if you want to delete any other element\nenter 7 if you want to display all the element");
        scanf("%d",&a);
        switch(a){
            case 1:printf("enter the number you want to add");
                    scanf("%d",&num);
                    append(&head,num);
                    break;
            case 2:printf("enter the number you want to add");
                    scanf("%d",&num);
                    attabeg(&head,num);
                    break;
            case 3:printf("enter the number you want to add");
                    scanf("%d",&num);
                    printf("enter the location you want to add");
                    scanf("%d",&loc);
                    add(&head,num,loc);
                    break;
            case 4:delete_first(&head);
                    break;
            case 5:delete_last(&head);
                    break;
            case 6:printf("enter the location of the element you want to delete");
                    scanf("%d",&loc);
                    delete(&head,loc);
                    break;
            case 7:display(&head);
                    break;
        }
        printf("enter 1 if you want to do some more operation else enter 0 ");
        scanf("%d",&flag);
    }
    return 0;
}

void append(struct clist **q,int num){
    struct clist *temp,*r;
if((*q)==NULL){
    temp=(struct clist *)malloc(1*sizeof(struct clist));
    temp->data=num;
    temp->link=temp;
    (*q)=temp;

}
else{
    temp=*q;
 while(temp->link!=(*q)){
    temp=temp->link;
 }
    r=(struct clist *)malloc(1*sizeof(struct clist));
    r->data=num;
  temp->link=r;
  r->link=(*q);
}
}

void attabeg(struct clist **q,int num){
    struct clist *temp,*r;
    temp=*q;
    if((*q)==NULL){
        r=(struct clist *)malloc(1*sizeof(struct clist));
        r->data=num;
        *q=r;
        r->link=r;
        return ;
    }
    while(temp->link!=(*q)){
        temp=temp->link;
    }
    r=(struct clist *)malloc(1*sizeof(struct clist));
    r->data=num;
    temp->link=r;
    r->link=(*q);
    *q=r;
    return ;
}


void add(struct clist **q,int num,int loc){
    struct clist *temp,*r;
    if(loc==1){
        attabeg(q,num);
        return ;
    }
    if (*q == NULL) {
        printf("List is empty, cannot add at location %d\n", loc);
        return;
    }
    temp=(*q);
for(int i=0;i<loc;i++){
    if(temp->link==(*q)){
        printf("there are not this much elements");
        return ;
    }
    temp=temp->link;
}
r=(struct clist *)malloc(1*sizeof(struct clist));
r->data=num;
r->link=temp->link;
temp->link=r;
return ;
}

void delete_first(struct clist **q){
    struct clist *temp,*r;
    if((*q)==NULL){
        return ;
    }
    temp=(*q);
    r=(*q);
    if(r->link==(*q)){
        free(r);
        *q=NULL;
        return ;
    }
    while(temp->link!=(*q)){
        temp=temp->link;
    }
    temp->link=r->link;
    *q=temp->link;
    free(r);
return ;
}

void delete_last(struct clist **q){
    struct clist *temp,*r;
    if((*q)==NULL){
        return ;
    }
    if((*q)->link==(*q)){
        free(*q);
        (*q)=NULL;
        return ;
    }
    r=(*q);
    temp=r->link;
    while(temp->link!=(*q)){
        temp=temp->link;
        r=r->link;
    }
    r->link=temp->link;
    free(temp);
    return ;
}

void delete(struct clist **q,int loc){
    struct clist *temp,*r;
    temp=(*q);
    r=temp;
    if((*q)==NULL){
        return ;
    }
    if(loc==1){
        delete_first(q);
        return;
    }
    for(int i=1;i<loc-1;i++){
        if(temp->link==(*q)){
            printf("there are not that muvh element");
            return ;
        }
        r=temp;
        temp=temp->link;
    }
r->link=temp->link;
free(temp);
return ;
}

void display(struct clist **q){
    struct clist *temp,*r;
    temp=(*q);
    if(temp==NULL){
        printf("there are no elements to display");
        return;
    }
    while(temp->link!=(*q)){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("%d\n",temp->data);   //to print the last node
    return ;
}