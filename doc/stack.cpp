#include <stdio.h>

const int MAX = 100;
struct Stack{
    int arr[MAX];
    int len =0;
    int capacity = 0;
    
    void create(int x){
        capacity = x;
    }
    void push(int x){
        if(len>=capacity){
            printf("Overflow\n");
        }else{
            arr[len++] = x;
        }
    }
    void pop(){
        if(len<=0){
            printf("Underflow");
        }else{
            arr[len-1] = 0;
            len--;
        }
    }
    int top(){
        if(len<=0){
            return -1;
        }
        return arr[len-1];
    }
    int size(){
        return len;
    }
};

int main(){
    Stack stack;
    int n,m,input,data;
    printf("\n");
    scanf("%d %d",&n,&m);
    
    stack.create(n);
    
    for(int i=0;i<m;i++){
        scanf("%d",&input);
        switch(input){
            case 1:
                scanf("%d",&data);
                stack.push(data);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                if(stack.top()==-1){
                    printf("NULL\n");
                }else{
                    printf("%d\n",stack.top());
                }
                break;
        }
    }
    
    
    return 0;
}
