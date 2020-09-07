#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

struct pos{
    int x;
    int y;
    int direction;
    int energy;
};
int t,n;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int arr[4001][4001]= {0,};

vector<pos> atoms;

int solve(){
    int ans = 0;
    while(!atoms.empty()){
        for(int i=0;i<atoms.size();i++){
            arr[atoms[i].y][atoms[i].x] = 0;
            int nx = atoms[i].x + dx[atoms[i].direction];
            int ny = atoms[i].y + dy[atoms[i].direction];
            
            if(nx < 0 || nx > 4000 || ny < 0 || ny > 4000) {    // 범위를 넘어간다면 에너지 소멸!~
                atoms[i].energy = 0;
                continue;
            }
            atoms[i].x = nx;
            atoms[i].y = ny;
            arr[ny][nx] += atoms[i].energy;
        }
        
        for(int i=0;i<atoms.size();i++){
            if(atoms[i].energy == 0) continue;
            int checkX = atoms[i].x;
            int checkY = atoms[i].y;
            if(arr[checkY][checkX]!= atoms[i].energy){
                ans += arr[checkY][checkX];
                arr[checkY][checkX] = 0;
                atoms[i].energy = 0;
            }
        }
        
        for(int i=0;i<atoms.size();i++){
            if(atoms[i].energy ==0){
                atoms.erase(atoms.begin()+i);
            }
        }
    }
    return ans;
}

int main(){
    scanf("%d",&t);
    for(int tc = 1;tc<=t;tc++){
        
        scanf("%d",&n);
        //memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++){
            pos atom = {};
            int a,b,c,d;
            scanf("%d%d%d%d",&a,&b,&c,&d);
            atom.x = a; atom.y = b;atom.direction = c;atom.energy = d;
            atom.x += 1000;
            atom.y += 1000;
            atom.x *=2;
            atom.y *=2;
            atoms.push_back(atom);
        }
        
        int result = solve();
        printf("#%d %d\n",tc,result);
    }
    
    
    return 0;
}
