#include <stdio.h>

int map[110][110];

int ans;
int T, n;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

//** change direction //
int changeDirection[6][4] = {   // 도형에 따라 방향 바뀜
    {0, 1, 2, 3},
    {1, 3, 0, 2},
    {1, 2, 3, 0},
    {2, 0, 3, 1},
    {3, 0, 1, 2},
    {1, 0, 3, 2}
};

void setWall() {
    // 구현을 손쉽게 하기위해 맵 가장자리에 벽을 만들어준다.
    for(int i = 0;i<=n + 1;i++) {
        map[i][0] = map[i][n+1] = map[0][i] = map[n+1][i] = 5;
    }
}

void wormhole(int &nx, int &ny, int wormholeNum) {
    
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=n;j++) {
            if((nx != i || ny != j) && map[i][j] == wormholeNum) {
                nx = i;
                ny = j;
                return;
            }
        }
    }
}

void solve(int sx, int sy, int d) {
    int x = sx;
    int y = sy;
    int cnt = 0;
    
    while(true) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if((nx == sx && ny == sy) || map[nx][ny] == -1) {
            ans = ans < cnt?cnt:ans;
            return;
        }
        if(map[nx][ny]) {
            if(map[nx][ny] < 6) {
                //블록인 경우
                d = changeDirection[map[nx][ny]][d];
                cnt++;
            }
            else wormhole(nx, ny, map[nx][ny]);
        }
        x = nx;
        y = ny;
    }
}

int main(void)
{
    scanf("%d", &T);
    
    for(int tt = 1;tt<=T;tt++) {
        scanf("%d", &n);
        
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=n;j++)
                scanf("%d", &map[i][j]);
        }
        setWall();
        ans = 0;
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=n;j++) {
                if(map[i][j]) continue;
                for(int d = 0;d<4;d++) {
                    solve(i, j, d);
                }
            }
        }
        printf("#%d %d\n", tt, ans);
    }
    
    return 0;
}

