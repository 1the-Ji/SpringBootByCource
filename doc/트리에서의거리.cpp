
#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 1000;

int main(){
    vector<int> arr[MAX];
    int check[MAX] = {0,};
    int distince = 0;
    int n,findA,findB;
    scanf("%d%d%d",&n,&findA,&findB);
    check[0] = 1;
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    int lowParent = findA;
    while(lowParent){
        check[lowParent] =1;
        lowParent = arr[lowParent].front();
    }
    lowParent = findB;
    while(lowParent){
        if(check[lowParent] ==1){
            break;
        }
        lowParent = arr[lowParent].front();
        distince++;
    }
    
    for(int i=lowParent;i<=findA;i++){
        if(check[i]==1){
            distince++;
        }
    }
    printf("%d",distince-1);
    
    
    return 0;
}

