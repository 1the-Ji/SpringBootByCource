#include <stdio.h>

const int MAX = 5;
struct Queue {
    int arr[MAX];
    int f,r;
    int capacity;
    
    
    void create(int x){
        capacity = x;
        f=0;
        r=0;
    }
    
    void push(int x){
        if(r-f>=capacity){
            printf("overflow\n");
        }else{
            arr[r++] = x;
        }
    }
    
    void pop(){
        if(r-f<=0){
            printf("underflow\n");
        }else{
            arr[f] = 0;
            f++;
        }
    }
    
    int front(){
        if(r-f<=0){
            return -1;
        }else{
            return arr[f];
        }
    }
    
    int size(){
        return r-f;
    }
};

int main(){
    Queue q;
    q.create(4);
    q.push(1);
    q.push(2);
    q.push(3);
    printf("%d\n",q.front());
    q.pop();
    q.pop();
    printf("%d\n",q.front());
    q.push(4);
    q.push(5);
    printf("%d\n",q.front());
    q.pop();
    q.pop();
    q.push(6);
    q.pop();
    printf("%d\n",q.front());
    return 0;
}
