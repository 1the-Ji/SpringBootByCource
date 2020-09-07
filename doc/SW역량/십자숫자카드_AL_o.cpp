//#include<cstdio>
//#include<cstring>
//using namespace std;
//int t,n;
//
//int arr[10][4];
//int max = -789789789;
//
//
//void getResult(){
//    for(int i=0;i<n;i++){
//        for(int j=0;j<4;j++){
//            printf("%d ",arr[i][j]);
//        }
//        //printf("\n");
//    }
//    int temp = 0;
//    for(int x=0;x<n-1;x++){
//        if((arr[x][3] + arr[x+1][1])%2 == 0){
//            temp += 0;
//        }else{
//            temp += (arr[x][3] * arr[x+1][1]);
//        }
//    }
//    if(temp>max){
//        max = temp;
//    }
//    printf("max : %d \n",max);
//}
//void lotation(int x){
//    if(x>n){
//        getResult();
//        return;
//    }else{
//        for(int i=0;i<4;i++){
//            lotation(x+1);
//            int temp = arr[x-1][0];
//            for(int j=0;j<3;j++){
//                arr[x-1][j] = arr[x-1][j+1];
//            }
//            arr[x-1][3] = temp;
//
//        }
//    }
//}
//int main(){
//    scanf("%d",&t);
//
//    for(int tc=1;tc<=t;tc++){
//
//        memset(arr,0,sizeof(int));
//        memset(arr,-789789789,sizeof(int));
//
//        scanf("%d",&n);
//
//        for(int i=0;i<n;i++){
//            for(int j=0;j<4;j++){
//                scanf("%d",&arr[i][j]);
//            }
//        }
//        lotation(0);
//
//        printf("%d %d\n",tc,max);
//
//    }
//
//    return 0;
//}
// hgshin@algorithmlabs.co.kr

int getValue(int a, int b){
    int val1 = data[a][2];
    int val2 = data[b][1];
    
    
    
    
}

void rotate(int x){
    int temp = data[x][10];
    data[x][0] = data[x][1];
    data[x][1] = data[x][3];
    data[x][3] = data[x][2];
    data[x][2] = temp;
}
void getResult(int x){
   //x번째 숫자 카드부터 시작해서 쭉 채워서 result를 구하는 함수
    
    if(x>=n){
        int temp = 0;
        for(int i=0;i<n;i++){
            temp += getValue(i-1,i);
        }
        
        result = max(temp,max);
    }else{
        for(int i=0;i<4;i++){
            getResult(x+1);
            rotate(x);
        }
    }
    
}
