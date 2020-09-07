#include <stdio.h>

const int MAX = 100;

struct PriotityQueue{
    int data[MAX];
    int len = 1;
    
    void push(int x){
        data[len++] = x;
        
        int inx = len-1;
        while(inx>1){
            if(data[inx]<data[inx/2]){
                int temp = data[inx];
                data[inx] = data[inx/2];
                data[inx/2] = temp;
            }else{
                break;
            }
            inx = inx / 2;
        }
        
    }
    
    void pop(){
        data[1] = data[len-1];
        data[len-1] = 0;
        len--;
        int inx = 1;
        
        //1. 자식들 중에서 우선순위가 높은 친구를 알아내야함.
        //2. 나와 그 우선순위가 높은 친구를 비교해서 자리를 바꾸어야 함.
        
        while(1){
            
            int pInx = -1;//우선순위가 높은 친구의 노드 번호
            
            // (a) 자식이 모두 없는 경우
            // (b) 왼쪽 자식만 존재하는 경우
            // (c) 왼쪽 오른쪽 자식이 모두 존재하는 경우
            if(len<= inx*2) break;
            else if((1<=inx*2 && inx*2< len) && len<=inx*2+1) {
                pInx = inx*2;
            }else{
                if(data[inx*2]<data[inx*2+1]){
                    pInx = inx*2;
                }else{
                    pInx = inx*2+1;
                }
            }
            if(data[inx]> data[pInx]){
                int temp = data[inx];
                data[inx] = data[pInx];
                data[pInx] = temp;
                
                inx = pInx;
            }else break;
        }
    }
    int top(){
        return data[1];
    }
};
int main() {
    PriotityQueue pq;
    pq.push(3);
    pq.push(1);
    pq.push(88);
    printf("1: %d\n",pq.top());
    pq.pop();
    
    printf("2: %d\n",pq.top());
    pq.pop();
    
    printf("3: %d\n",pq.top());
    pq.pop();
    
    
    return 0;
}
