//1.시간복잡도에 위험한 문제..
//2.재귀함수 문제 : 약품을 투입을 한 개수가 k개를 넣어야하므로,.,,
//3.

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int films_temp[13][20],films[13][20];
int d,w,k,t;
int ans;

bool check(){
    for(int i=0;i<w;i++){
        bool isRowSame = false;
        for(int j=0;j<=d-k;j++){
            bool isDifferent = false;
            for(int a=j+1;a<j+k;a++){
                if(films[j][i] != films[a][i]){
                    isDifferent = true;
                    break;
                }
            }
            if(!isDifferent){
                isRowSame = true;
                break;
            }
        }
        //한줄이 다르면 false를 리턴
        if(!isRowSame){
            return false;
        }
    }
    
    return true;
}

void caseDFS(int index,int cnt){
    if(cnt >= ans) return;
    
    if(check() && index == d) {
        ans = min(ans, cnt);
        return;
    }
    
    if(index>=d){
        return ;
    }
    // recursive
    for(int i = 0;i<w;i++)
        films[index][i] = 0;
    caseDFS(index + 1, cnt + 1);
    
    
    for(int i = 0;i<w;i++)
        films[index][i] = 1;
    caseDFS(index + 1, cnt + 1);
    
    
    for(int i = 0;i<w;i++)
        films[index][i] = films_temp[index][i];
    caseDFS(index + 1, cnt);
}

int main(){
    
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d %d",&d,&w,&k);
        for(int i=0;i<d;i++){
            for(int j=0;j<w;j++){
                scanf("%d",&films[i][j]);
                films_temp[i][j] = films[i][j];
            }
        }
        if(check()){
            printf("#%d %d",tc,0);
            continue;
        }
        ans = d;
        caseDFS(0,0);
        
        printf("#%d %d",tc,ans);
    }
    
    return 0;
}
