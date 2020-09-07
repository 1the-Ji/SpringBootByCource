#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;
struct pos{
    int x;
    int y;
    int remainTime;
    int time;
    int state;
};

int t,n,m,k;
int arr[600][600];
vector<pos> cells;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void solve(){
    while(k--){
        vector<pos> newCell;
        for(int i=0;i<cells.size();i++){
            if(cells[i].state != 2){
                cells[i].remainTime--;
                
                if(cells[i].state==1){
                    //증식시켜라
                    for(int j=0;j<4;j++){
                        int nx = cells[i].x + dx[j];
                        int ny = cells[i].y + dx[j];
                        
                        //if(nx<0||nx>n||ny<0||ny>m) continue;
                        
                        if(arr[nx][ny]==0){
                            arr[nx][ny] = cells[i].time;
                            newCell.push_back({nx,ny,cells[i].time,cells[i].time,0});
                        }
                    }
                    
                }
                
                if(cells[i].remainTime == 0){
                    if(cells[i].state ==0){
                        cells[i].state = 1;
                        cells[i].remainTime = cells[i].time;
                    }else if(cells[i].state ==1){
                        cells[i].state = 2;
                    }
                }
                
            }
        }
        
        for(int i=0;i<newCell.size();i++){
            cells.push_back(newCell[i]);
        }
    }
}
int getResult(){
    int result=0;
    
    for(int i=0;i<cells.size();i++){
        if(cells[i].state!=2){
            result++;
        }
    }
    return result;
}

int main(){
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        
        memset(arr,0,sizeof(arr));
        cells.clear();
        scanf("%d%d%d",&n,&m,&k);
        
        
        for(int i=300;i<300+n;i++){
            for(int j=300;j<300+m;j++){
                scanf("%d",&arr[i][j]);
                
                if(arr[i][j]>0){
                    cells.push_back({i,j,arr[i][j],arr[i][j],0});
                }
                
            }
        }
        solve();
        
        printf("#%d %d\n",tc,getResult());
    }
    
    return 0;
}
