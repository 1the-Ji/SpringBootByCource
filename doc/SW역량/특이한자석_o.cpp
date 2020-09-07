#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int t,k,ans;
int arr[4][8];

void lotation(int index,int direction){
    int temp = arr[index][0];
    
    if(direction==1){
        arr[index][0] = arr[index][7];
        arr[index][7] = arr[index][6];
        arr[index][6] = arr[index][5];
        arr[index][5] = arr[index][4];
        arr[index][4] = arr[index][3];
        arr[index][3] = arr[index][2];
        arr[index][2] = arr[index][1];
        arr[index][1] = temp;
    }else{
        arr[index][0] = arr[index][1];
        arr[index][1] = arr[index][2];
        arr[index][2] = arr[index][3];
        arr[index][3] = arr[index][4];
        arr[index][4] = arr[index][5];
        arr[index][5] = arr[index][6];
        arr[index][6] = arr[index][7];
        arr[index][7] = temp;

    }
}

void rightSolve(int index, int direction){
    if(index>3){
        return;
    }
    bool rightAccess = false;
    
    if(index<3&&arr[index][2]!=arr[index+1][6]){
        rightAccess = true;
    }
    lotation(index,direction);
    if(rightAccess)rightSolve(index+1,(direction==1)?-1:1);
}

void leftSolve(int index, int direction){
    if(index<0){
        return;
    }
    bool leftAccess = false;
    
    if(index>0&&arr[index][6]!=arr[index-1][2]){
        leftAccess = true;
    }
    lotation(index,direction);
    if(leftAccess)leftSolve(index-1,(direction==1)?-1:1);
}
void solve(int index, int direction){
    bool leftAccess = false, rightAccess = false;
    if(index>0&&arr[index-1][2]!=arr[index][6]){
        leftAccess = true;
    }
    if(index<3&&arr[index][2]!=arr[index+1][6]){
        rightAccess = true;
    }
    lotation(index,direction);
    if(rightAccess)rightSolve(index+1,(direction==1)?-1:1);
    if(leftAccess)leftSolve(index-1,(direction==1)?-1:1);
    
}

int getResult(){
    int result =0;
    for(int i=0;i<4;i++){
        if(arr[i][0]==1){
            result += (int)pow(2,i);
        }
    }
    
    return result;
}

int main(){
    scanf("%d",&t);
    
    for(int tc=1;tc<t;tc++){
        memset(arr,0,sizeof(arr));
        ans = 0 ;
        scanf("%d",&k);
        for(int i=0;i<4;i++){
            for(int j=0;j<8;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        
        for(int i=0;i<k;i++){
            int index, direction;
            scanf("%d%d",&index,&direction);
            solve(index-1,direction);
        }
        ans = getResult();
        printf("#%d %d\n",tc,ans);
    }
    return 0;
}
