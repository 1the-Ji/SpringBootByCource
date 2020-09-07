#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct battery{
    int x;
    int y;
    int coverage;
    int performance;
};
int T,M,A,ans=0;
int userA[100],userB[100];

int dx[] = {0,0,1,0,-1};
int dy[] = {0,-1,0,1,0};

int abs(int a){
    if(a>0){
        return a;
    }else{
        return -a;
    }
}
int getResult(battery charer[], int ax, int ay, int bx, int by){
    
    vector<battery> inBatteryA, inBatteryB;
    
    //기계 개수 만큼 aUser체크
    for(int i=0;i<A;i++){
        int distince = abs(charer[i].x -ax) + abs(charer[i].y - ay);
        if(distince<=charer[i].coverage) inBatteryA.push_back(charer[i]);
    }
    //기계 개수 만큼 bUser체크
    for(int i=0;i<A;i++){
        int distince = abs(charer[i].x -bx) + abs(charer[i].y - by);
        if(distince<=charer[i].coverage) inBatteryB.push_back(charer[i]);
    }
    
    if(inBatteryA.empty()||inBatteryB.empty()){
        int maxPerformance =0;
        if(!inBatteryA.empty()){
            for(int i=0;i<inBatteryA.size();i++){
                maxPerformance = max(maxPerformance , inBatteryA[i].performance );
            }
        }
        
        if(!inBatteryB.empty()){
            for(int i=0;i<inBatteryB.size();i++){
                maxPerformance = max(maxPerformance , inBatteryB[i].performance );
            }
        }
        
        return maxPerformance;
        
    }else{
        int maxPerformance = 0;
        for(int i=0;i<inBatteryA.size();i++){
            for(int j=0;j<inBatteryB.size();j++){
                battery a = inBatteryA[i];
                battery b = inBatteryB[j];
                if(a.x==b.x&& a.y==b.y){
                    maxPerformance = max(a.performance/2+b.performance/2,maxPerformance);
                }else{
                    maxPerformance = max(a.performance+b.performance,maxPerformance);
                }
            }
        }
        return maxPerformance;
    }
    
}

void solve(int time, battery charer[], int ax, int ay, int bx, int by){
    if(time>M){
        return;
    }else{
        ans += getResult(charer,ax,ay,bx,by);
    }
    
    int nax = ax + dx[userA[time]];
    int nay = ay + dy[userA[time]];
    int nbx = bx + dx[userB[time]];
    int nby = by + dy[userB[time]];
    
    solve(time+1,charer,nax,nay,nbx,nby);
}

int main(){
    scanf("%d",&T);
    for(int tc = 1;tc<=T;tc++){
        scanf("%d%d",&M,&A);
        memset(userA,0,sizeof(userA));
        memset(userB,0,sizeof(userB));
        
        for(int i=0;i<M;i++){
            scanf("%d",&userA[i]);
        }
        for(int i=0;i<M;i++){
            scanf("%d",&userB[i]);
        }
        
        battery charer[8];
        ans = 0;
        for(int i=0;i<A;i++){
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            charer[i].x = a-1;
            charer[i].y = b-1;
            charer[i].coverage = c;
            charer[i].performance = d;
        }
        
        int time = 0;
        solve(time,charer,0,0,9,9);
        printf("#%d %d\n",tc,ans);
    }
    
    return 0;
}
