#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int check[10001];
vector<int> graph[10001];
bool ok = true;

void BFS() {
    // 1. 시작점을 큐에다가 삽입.
    // 2. 시작점 색칠
    // 3. 큐에서 하나를 뺀다. 얘가 우리의 현재 위치
    // 4. 인접한 모든 정점에게 방문했는지 물어보고
    //  방문을 하지 않았다면, 색칠하고 큐에 삽입.
    // 5. 모두 완료했다면 3으로 돌아간다.
    queue<int> q;
    q.push(0);
    check[0] = 1;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 0;i<graph[cur].size();i++) {
            int next = graph[cur][i];
            if(!check[next]) {
                check[next] = 3 - check[cur];
                q.push(next);
            }
            
            else if(check[next] > 0 && check[next] == check[cur]) {
                ok = false;
            }
        }
    }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    
    for(int i = 0;i<m;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    BFS();
    
    printf("%s\n", ok?"YES":"NO");
    
    return 0;
}
