#include<stdio.h>
#include<stdlib.h>
 struct list{
    int val;
    struct list *next;
 }*new,*temp,*top;

void push(struct list **q,int value);
void pop(struct list **q);
void peek();
void update(struct list **q,int value,int i);
void display(struct list **q);


 int main(){
    int choice, value, pos, flag = 1;
    struct list *head = NULL; 

    while(flag == 1) {
        printf("\n--- STACK MENU (LINKED LIST) ---");
        printf("\n1. PUSH\n2. POP\n3. PEEK\n4. UPDATE\n5. DISPLAY\n6. EXIT");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&head, value);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Enter position from top (1, 2...): ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &value);
                update(&head, value, pos);
                break;
            case 5:
                display(&head);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!");
        }
        printf("\nPress 1 to continue or 0 to exit: ");
        scanf("%d", &flag);
    }
    return 0;
 }

void push(struct list **q,int value){
    new=(struct list *)malloc(sizeof(struct list));
    new->next=(*q);
    new->val=value;
    top=new;
    (*q)=new;
    return ;
}

void pop(struct list **q){
    if(top==NULL){
        printf("there are not that eleemts");
        return ;
    }
    printf("the popped element is %d",top->val);
    temp=top;
    top=top->next;
    (*q)=top;
    free(temp);
    return ;
}

void peek(){
    if(top==NULL){
        printf("there are no elements");
        return ;
    }
    printf("the top element of the stack is %d",top->val);
    return ;
}

void update(struct list **q,int value,int i){
    if(top==NULL){
        printf("no elements ");
        return ;
    }
    else{
        temp=(*q);
        for(int j=0;j<i-1;j++){
            if(temp==NULL){
                printf("enter a valid position");
                return ;
            }
            temp=temp->next;
        }
        temp->val=value;
        return ;
    }
}

void display(struct list **q){
    temp=(*q);
    while(temp!=NULL){
        printf("%d\n",temp->val);
        temp=temp->next;
    }
    return ;
}