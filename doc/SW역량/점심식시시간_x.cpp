재귀함수문제 : 사람들이 어느 계단을 선택해서 가야할지 모르기 떄문임



#include<cstdio>
#include<math.h>
#include<algorithm>
using namespace std;

const int PERSON_MAX = 11;
const int STAIR_CNT = 2;
const int MAP_MAX = 10;

int P = 0,S = 0;
int testCase, mapCnt;
int matrix[MAP_MAX][MAP_MAX] = {0,};
int match[PERSON_MAX];

struct Map{
    int row; //열(가로)
    int col; //행(세로)
};
Map p_matrix[PERSON_MAX] = {0,},s_matrix[STAIR_CNT]={0,};


void caculrate(){
    
    //계단 1인경우 2인 경우
    for(int stair_index=0;stair_index<STAIR_CNT;stair_index++){
        //사람들이 계단에 도착하는 시간 모음
        int arrive_time[MAP_MAX*2] = {0,}; //특정한 시간에 계단에 도착한사람의 수
        int stair_time[MAP_MAX*2 + MAP_MAX*MAP_MAX] ={0,}; //특정한 시간에 계단에 내려가는 사람의 수
        
        for(int j=0;j<P;j++){
            if(match[j]==stair_index){
                arrive_time[abs(p_matrix[j].col - s_matrix[j].col)+abs(p_matrix[j].row - s_matrix[j].row)]++;
            }
        }
        
        for(int time=1;time<=20;time++){
            while(arrive_time[time]>0){
                arrive_time[time]--;
                int remin_stair = matrix[s_matrix[stair_index].col][s_matrix[stair_index].row];
                for(int walk_time=time;walk_time<MAP_MAX*2 + MAP_MAX*MAP_MAX;walk_time++){
                    if(stair_time[walk_time]<3){
                        stair_time[walk_time]++;
                        remin_stair--;
                        if(remin_stair<=0){
                            break;
                        }
                    }
                }
            }
        }
        
    }
}

//사람들이 계단 1과 2인경우 DFS
void DFS(int person_index){
    
    if(person_index >= P){
        caculrate();
        return;
    }
    for(int i=0;i<STAIR_CNT;i++){
        match[person_index] = i;
        DFS(person_index+1);
    }
        
}

int main(){
    
    scanf("%d",&testCase);
    
    for(int i=0;i<testCase;i++){
        
        scanf("%d",&mapCnt);
        for(int i=0;i<mapCnt;i++){
            for(int j=0;j<mapCnt;j++){
                scanf("%d",&matrix[i][j]);
                if(matrix[i][j]==1){
                    p_matrix[P].col = i;
                    p_matrix[P].row = j;
                    P++;
                }else if(matrix[i][j]>=2){
                    s_matrix[S].col = i;
                    s_matrix[S].row = j;
                    S++;
                }
            }
        }
        
        DFS(0);
        
    }
    
    return 0;
}
