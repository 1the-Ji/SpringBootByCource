
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 2000;

int n, m;
vector<int> myGraph[MAX];
bool color[MAX];
bool visited[MAX];
bool diffCol = false;
bool isGood = true;

bool DFS(int x) {
    //x부터 시작해서 DFS시작
    //단 visited에 방문기록이 있음.
    
    visited[x] = true;
    color[x] = diffCol;
    diffCol = !diffCol;
    
    for(int i = 0;i<myGraph[x].size();i++) {
        int y = myGraph[x][i];
        if(!visited[y]) {
            DFS(y);
            if(diffCol == color[x])
                diffCol = !diffCol;
        }
        if(visited[y] && color[x] == color[y])
            isGood = false;
    }
    return isGood;
}

int main(void)
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        myGraph[a].push_back(b);
        myGraph[b].push_back(a);
    }
    
    for(int i = 0;i<n;i++) // 노드번호가 작은순서대로
        sort(myGraph[i].begin(), myGraph[i].end());
    
    if(DFS(0))
        puts("YES");
    else
        puts("NO");
    
    return 0;
}
