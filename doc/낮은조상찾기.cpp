#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 1000;
int main(){
    vector<int> treeData[MAX];
    int cnt,findA,findB;
    int check[MAX] ={0,};
    check[0] = 1;
    scanf("%d%d%d",&cnt,&findA,&findB);
    for(int i=0;i<cnt-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        treeData[a].push_back(b);
        treeData[b].push_back(a);
    }
    
    int tmp = findA;
    while(tmp){
        check[tmp] = 1;
        tmp = treeData[tmp].front();
    };
    tmp = findB;
    while(tmp){
        if(check[tmp]==1){
            break;
        }
        tmp =treeData[tmp].front();
    }
    printf("%d",tmp);
    
    
    
    return 0;
}

