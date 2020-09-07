#include <stdio.h>

const int MAX = 100;

struct CircleQueue{
    int data[MAX];
    int f,r;
    int capacity;
    int numElement;
    
    void create(int x){
        f=0;
        r=0;
        capacity = x;
        numElement = 0;
    }
    
    void push(int x){
        if(numElement>=capacity){
            printf("Overflow\n");
        }else{
            data[r++] = x;
            if(r>=MAX){
                r=0;
            }
            numElement++;
        }
    }
    
    void pop(){
        if(numElement<=0){
            printf("Underflow\n");
        }else{
            data[f] = 0;
            f++;
            if(f>=MAX){
                f = 0;
            }
            numElement--;
        }
    }
    
    int front(){
        if(numElement<=0){
            return -1;
        }else{
            return data[f];
        }
    };
    
    int size(){
        return numElement;
    }
};
int main(){
    CircleQueue q;
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
