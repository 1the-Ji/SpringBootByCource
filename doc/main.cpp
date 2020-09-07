//예제 입력
//
//10
//1 3 1 2 4 2 1 3 2 1
//예제 출력
//
//4
#include<stdio.h>
#include <algorithm>
using namespace std;

int main(){
    printf("\n");
    int n,a,b,index=0;
    int input;
    int arr[100000]={0};
    scanf("%d",&n);
    
    for (int i=0; i<n; i++) {
        scanf("%d%d",&a,&b);
        for(int i=a;i<=b;i++){
            arr[index++] = i;
        }
        
    }
    sort(arr,arr+index);
    
    scanf("%d",&input);
   
    printf("%d",arr[input]);
    
    return 0;
}
