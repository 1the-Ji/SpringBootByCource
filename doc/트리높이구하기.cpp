#include <cstdio>
using namespace std;

const int MAX = 100;
int arr[MAX][MAX] = {0,};
int level=0;
int maxLevel = 0;
int n,root;
void getHeight(int level,int cur, int parent){
    for(int i=0;i<n;i++){
        if(parent==i)
            continue;
        
        if(arr[cur][i]==1){
            getHeight(level+1, i, cur);
        }
    }
    if(maxLevel<level)
        maxLevel = level;
}
int main(){
    
    scanf("%d %d",&n,&root);
    
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        
        arr[a][b] = 1;
        arr[b][a] = 1;
        
    }
    getHeight(level,root,-1);
    printf("%d",maxLevel);
    return 0;
}
