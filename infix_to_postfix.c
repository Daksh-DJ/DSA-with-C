#include<stdio.h>
int top=-1;
int topi=-1;
char app[100];
char stack[100];
void push(char value);
void pushy(char value);
int pri(char value);
int pop();

int main(){
    char str[100];
    printf("enter the infix ");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='('){
            push(str[i]);
        }
        else if(str[i]>=48&&str[i]<=57){
            pushy(str[i]);
        }
        else if(str[i]==')'){
            char x;
            while((x=pop())!='('){
                pushy(x);
            }
        }
        else{
            char x;
            while(top!=-1&&pri(str[i])<=pri(stack[top])){
                pushy(pop());
            }
            push(str[i]);
        }
    }
    while(top!=-1){
        pushy(pop());
    }
    pushy('\0');
    puts(app);
    return 0;
}

void push(char value){
    if(top==99){
        printf("overflow");
        return ;
    }
    else{
        top++;
        stack[top]=value;
        return;
    }
}

int pop(){
    if(top==-1){
        printf("stack underflow");
        return '\0';

    }
    else{
        char x;
        x=stack[top];
        top--;
        return x;
    }
}

void pushy(char value){
     if(topi==99){
        printf("overflow");
        return ;
    }
    else{
        topi++;
        app[topi]=value;
        return;
    }
}

int pri(char value){
    if(value=='('){
        return 0;
    }
    else if(value=='+'||value=='-'){
        return 1;
    }
    else if(value=='/'||value=='*'){
        return 2;
    }
    return 0;
}