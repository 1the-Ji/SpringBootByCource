#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct pos {
    int x;
    int y;
    int dist;
    int cut;
};

int arr[10][10];
bool check[10][10];

int ans = 0;
int n, k;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(pos node) {
    if(node.dist > ans) ans = node.dist;
    
    for(int i = 0;i<4;i++) {
        int nx = node.x + dx[i];
        int ny = node.y + dy[i];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        
        if(!check[nx][ny] && arr[nx][ny] < arr[node.x][node.y]) {
            check[nx][ny] = true;
            dfs({nx, ny, node.dist + 1, node.cut});
            check[nx][ny] = false;
        }
        else if(!check[nx][ny] && arr[nx][ny] >= arr[node.x][node.y] && node.cut == 0) {
            if(arr[nx][ny] - k < arr[node.x][node.y] && arr[node.x][node.y] >= 0) {
                check[nx][ny] = true;
                int temp = arr[nx][ny];
                arr[nx][ny] = arr[node.x][node.y] - 1;
                dfs({nx, ny, node.dist + 1, 1});
                arr[nx][ny] = temp;
                check[nx][ny] = false;
            }
        }
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for(int t = 1;t<=T;t++) {
       
        memset(check, false, sizeof(check));
        memset(arr, 0, sizeof(arr));
        ans = 0;
        
        scanf("%d %d", &n, &k);
        
        vector<pos> start;
        
        int maxDegree = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++){
                scanf("%d", &arr[i][j]);
                
                if(maxDegree < arr[i][j]) {
                    maxDegree = arr[i][j];
                }
            }
        }
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(arr[i][j] == maxDegree)
                    start.push_back({i, j, 0, 0});
            }
        }
        
        int result = 0;
        
        for(int i = 0;i<start.size();i++) {
            memset(check, false, sizeof(check));
            check[start[i].x][start[i].y] = true;
            dfs(start[i]);
            if(ans > result) result = ans;
        }

        printf("#%d %d\n",t, result + 1);
    }
    
    return 0;
}
