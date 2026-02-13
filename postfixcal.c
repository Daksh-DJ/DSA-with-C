#include<stdio.h>
int num[100];
int top=-1;
void push(int value);
int pop();
int eval(char str[]);
int main(){
    char str[100];
    printf("enter the infix");
    scanf("%s",str);
    eval(str);
    printf("the evaluated number is %d",pop());
    return 0;
}

void push(int value){
if(top==99){
    printf("stack overflow");
    return ;
}
else{
    top++;
    num[top]=value;
    return;
}
}
int pop(){
    if(top==-1){
        printf("stack underflow\n");
        return 0;
    }
    else{
        int val;
        val=num[top];
        top--;
        return val;
    }
}

int eval(char str[]){
    int val;
    for(int i=0;str[i]!='\0';i++){
        if((int)str[i]>=48&&(int)str[i]<=57){
            push(str[i]-'0');
        }
        else{
            int val1=pop();
            int val2=pop();
            switch((int)str[i]){
                case '+':
                            val=val1+val2;
                            push(val);
                            break;
                case '-':
                            val=val2-val1;
                            push(val);
                            break;
                case '/':
                            val=val2/val1;
                            push(val);
                            break;
                case '*':
                            val=val1*val2;
                            push(val);
                            break;
            }
        }
    }
}