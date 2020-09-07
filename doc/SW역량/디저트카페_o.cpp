//1. 재귀함수가 아니다.!!!!
//2. 움직이는 방향은 2가지이다.
//3. 재귀함수의 특징은 n중 반복문, n가지 선택 등등일경우

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct pos {
    int x;
    int y;
    int dessert;
    int direction;
};

int n;

int arr[21][21];
bool check[21][21];
bool eat[101];

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, -1, 1};

int ans = -1;
int startx, starty;

void DFS(pos node) {     // DFS와 Backtracking 사용
    
    if(node.x == startx && node.y == starty && node.dessert >= 4) { // 리턴!
        ans = max(ans, node.dessert);
        return;
    }
    
    for(int i = 0;i<2;i++) {    // 방향은 두가지 방향만 고려하면 된다느점 유의할 것. (원래방향과 90도 회전한방향)
        int nx = node.x + dx[(node.direction + i < 4)?node.direction + i : 0];
        int ny = node.y + dy[(node.direction + i < 4)?node.direction + i : 0];
        
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(!check[nx][ny] && !eat[arr[nx][ny]]) {
            check[nx][ny] = true;
            eat[arr[nx][ny]] = true;
            DFS({nx, ny, node.dessert + 1, node.direction + i});
            check[nx][ny] = false;
            eat[arr[nx][ny]] = false;
        }
        else if(nx == startx && ny == starty) {  // 처음 시작점을 만나면?
            DFS({nx, ny, node.dessert + 1, node.direction + i});
        }
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for(int tc = 1;tc<=T;tc++) {
        memset(eat, false, sizeof(eat));
        scanf("%d", &n);
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                scanf("%d", &arr[i][j]);
                check[i][j] = false;
            }
        }
        
        int result = -1;
        for(int i = 0;i<n ;i++) {
            for(int j = 0 ;j<n ;j++) {
                ans = -1;
                pos start = {i, j, 0, 0};
                eat[arr[i][j]] = true;
                check[i][j] = true;
                startx = i; starty = j;
                DFS(start);
                check[i][j] = false;
                eat[arr[i][j]] = false;
                
                if(result < ans) result = ans;
            }
        }
        printf("#%d %d\n", tc, result);
    }
    
    return 0;
}
