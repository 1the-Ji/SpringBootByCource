#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int map[21][21];
bool check[21][21];
int n, x;

int solve(int idx, int rowcol) {
    if(rowcol == 0) {
        int temp = map[idx][0];
        for(int i = 1;i<n;i++) {
            if(temp != map[idx][i]) {
                if(map[idx][i] == temp - 1) {
                    int temp2 = map[idx][i];
                    if(check[idx][i]) return 0;
                    
                    check[idx][i] = true;
                    for(int j = i + 1;j< i + x;j++) {
                        if(j >= n || map[idx][j] != temp2|| check[idx][j]) return 0;
                        check[idx][j] = true;
                    }
                    temp = map[idx][i];
                    i += x - 1;
                }
                else if(map[idx][i] == temp + 1){
                    int temp2 = map[idx][i - 1];
                    if(check[idx][i-1]) return 0;
                    check[idx][i-1] = true;
                    
                    for(int j = i - 2;j>= i - x;j--) {
                        if(j < 0 || map[idx][j] != temp2|| check[idx][j]) return 0;
                        check[idx][j] = true;
                    }
                    temp = map[idx][i];
                }
                else return 0;
            }
        }
    }
    else {
        int temp = map[0][idx];
        for(int i = 1;i<n;i++) {
            if(temp != map[i][idx]) {
                if(map[i][idx] == temp - 1) {
                    int temp2 = map[i][idx];
                    if(check[i][idx]) return 0;
                    check[i][idx] = true;
                    
                    for(int j = i + 1;j<i + x;j++) {
                        if(j>= n || map[j][idx] != temp2 || check[j][idx]) return 0;
                        check[j][idx] = true;
                    }
                    temp = map[i][idx];
                    i += x - 1;
                }
                
                else if(map[i][idx] == temp + 1) {
                    int temp2 = map[i - 1][idx];
                    if(check[i-1][idx]) return 0;
                    check[i-1][idx] = true;
                    
                    for(int j = i - 2;j>=i - x;j--) {
                        if(j < 0 || map[j][idx] != temp2 || check[j][idx]) return 0;
                        check[j][idx] = true;
                    }
                    temp = map[i][idx];
                }
                
                else return 0;
            }
        }
    }
    
    return 1;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for(int tt = 1;tt<=T;tt++) {
        memset(map, 0, sizeof(map));
        scanf("%d %d", &n, &x);
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++)
                scanf("%d", &map[i][j]);
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++) {
            memset(check, false, sizeof(check));
            ans += solve(i, 0);
            memset(check, false, sizeof(check));
            ans += solve(i, 1);
        }
        
        printf("#%d %d\n", tt, ans);
    }
    
    return 0;
}

