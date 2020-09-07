#include <cstdio>
using namespace std;

int arr[1001][1001];
int sum[1001][1001];
int main(void)
{
    int n, m, q;
    
    scanf("%d %d %d", &n, &m, &q);
    
    
    for(int i = 0;i<n;i++) {
        for(int j = 0;j<m;j++) {
            scanf("%d", &arr[i][j]);
            if(i==0 && j==0) sum[i][j] = arr[i][j];
            
            if(i-1 < 0 && j-1>=0) sum[i][j] = sum[i][j-1] + arr[i][j];
            else if(j-1 < 0 && i-1>=0) sum[i][j] = sum[i-1][j] + arr[i][j];
            else if(i-1>=0 && j-1 >=0) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }
    
    while(q--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        int result;
        
        if(x1-1 < 0)
            result = sum[x2][y2] - sum[x2][y1-1];
        else if(y1-1 < 0)
            result = sum[x2][y2] - sum[x1-1][y2];
        else
            result = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
        
        printf("%d\n", result);
    }
    
    return 0;
}
