#include<cstdio>
#include<vector>
#include<queue>
#include <algorithm>

using namespace std;
const int MAX = 2000;
int n,m;
int bfs_check[MAX],dfs_check[MAX];
queue<int> Queue;
vector<int> myGraph[MAX];

void DFS(int x){
    dfs_check[x] = true;
    printf("%d ",x);
    for(int i=0;i<myGraph[x].size();i++){
        int y = myGraph[x][i];
        if(dfs_check[y]==false){
            DFS(y);
        }
    }
}

void BFS(){
    bfs_check[0]=true;
    Queue.push(0);
    
    while(!Queue.empty()){
        int current = Queue.front();
        Queue.pop();
        printf("%d ",current);
        for(int i=0;i<myGraph[current].size();i++){
            int tmp = myGraph[current][i];
            if(bfs_check[tmp]==false){
                bfs_check[tmp] = true;
                Queue.push(tmp);
            }
        }
    }
    
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }
    for(int i = 0;i<n;i++)
        sort(myGraph[i].begin(), myGraph[i].end());
    
    DFS(0);
    printf("\n");
    BFS();
    return 0;
}
