#include<stdio.h>
 int top=-1;
 int stack[5];
 int max=5;
  
void push(int val);
void pop();
void peek();
void update(int position,int value);
void display();

 int main(){
    int choice, val, pos,flag=1;

    while(flag==1) {
        printf("\n--- STACK MENU ---");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. UPDATE");
        printf("\n5. DISPLAY");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Enter position from top (1, 2...): ");
                scanf("%d", &pos);
                printf("Enter new value: ");
                scanf("%d", &val);
                update(pos, val);
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid choice!");
        }
        printf("enter 1 to continue or else enter 0");
        scanf("%d",&flag);
    }
    return 0;
 }

 void push(int val){
    if(top==max-1){
        printf("stack overflow");
    }
    else{
        top++;
        stack[top]=val;
        return ;
    }
 }

 void pop(){
    if(top==-1){
        printf("the stack is underflow");
    }
    else{
        printf("the popped element is %d",stack[top]);
        top--;
    }
 }

 void peek(){
    if(top==-1){
        printf("the stack is empty");
        return ;
    }
    else{
        printf("the top element is %d",stack[top]);
        return ;
    }
 }

 void update(int position,int value){
    int index;
    index=top-position+1;
    if(index<0||position<0){
        printf("not a valid position");
        return ;
    }
    else{
        stack[index]=value;
        return ;
    }
 }

 void display(){
    if(top==-1){
        printf("no elements in the stack");
        return ;
    }
    else{
        for(int i=0;i<=top;i++){
            printf("%d\n",stack[i]);
        }
        return ;
    }
 }