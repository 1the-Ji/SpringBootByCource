//attack range문제랑 비슷
//비재귀함수 문제

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;


int t,n,m;
int arr[20][20];
int ans = 0;
int abs(int a){
    if(a>0){
        return a;
    }else{
        return -a;
    }
}
void getResult(int x,int y){
    int cnt =0;
    int k=0;
    int cost = 0;
    int profit = 0;
    while(k<2*n){
        cost = (k*k)+ (k-1)*(k-1);
        cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int dx = i;
                int dy = j;
                int distince = abs(x-dx) + abs(y-dy);
                
                if(dx<0||dx>=n||dy<0||dy>=n)continue;
                
                if(distince<k&&arr[dx][dy]==1){
                    cnt++;
                }
            }
        }
        profit = m*cnt - cost;
        if(profit>=0){
            ans = max(cnt,ans);
        }
        k++;
    }
}

int main(){
    
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                getResult(i,j);
            }
        }
        printf("#%d %d\n",tc,ans);
    }
    
    
    return 0;
}

