//1. 문제의 핵심은 파이프
//2. BFS
//3. 주어진 파이프의 연결 상관관계를 나타내는 배열 및 함수를 작성한다. connection array, connection function 주어진 출발점을 기준으로
//BFS를 활용하여 완전탐색한다. BFS를 활용하여 완전 탐색시, 방문하였던 곳을 방문하지 않도록 중복을 방지하며, 현재 기준점으로부터 거리가 얼마나 떨어졌는지를 체크하고 임계값을 넘지 않도록하며, 이동 할 수 있는곳인지 1번의 배열과 함수를 활용하여 체크한 후 enqueue 시킨다.
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;


const int tunnel[8][4] = {
//  상  하. 좌. 우
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {1, 0, 1, 0}
};

struct pos{
    int x;
    int y;
    int time;
};

int n, m, r, c, l;
int arr[51][51][4];
bool check[51][51];

int dx[] = {-1, 1, 0, 0}; //세로
int dy[] = {0, 0, -1, 1}; //가로

int main(){
    
    int t;
    scanf("%d",&t);
    for(int tc =1;tc<=t;tc++){
        memset(check, false, sizeof(check));
        memset(arr, 0, sizeof(arr));
        
        int ans = 0;
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                int type;
                scanf("%d", &type);
                for(int k = 0;k<4;k++){
                    arr[i][j][k] = tunnel[type][k];
                }
            }
        }
        
        check[r][c] = true;
        queue<pos> q;
        q.push({r, c, 0});
        
        while(!q.empty()){
            pos cur = q.front();
            int x = cur.x;
            int y = cur.y;
            int time = cur.time;
            q.pop();
            if(time >= l) break;
            ans++;
            
            for(int i=0;i<4;i++){
                if(arr[x][y][i]) {
                    int nx = x + dx[i]; //세로
                    int ny = y + dy[i]; //가로
                    
                    if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
                    
                    if(!check[nx][ny]) {
                        if((i == 0 && arr[nx][ny][1]) || (i == 1 && arr[nx][ny][0]) || (i == 2 && arr[nx][ny][3]) || (i == 3 && arr[nx][ny][2])) {
                            check[nx][ny] = true;
                            q.push({nx, ny, time + 1});
                        }
                    }
                }
            }
            printf("#%d %d\n",t,ans);
            
        }
    }
    
    return 0;
}
