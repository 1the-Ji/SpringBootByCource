#include <cstdio>

using namespace std;
const int MAX = 100;
int n,m,arr[MAX];
int main(){
    scanf("%d%d",&n,&m);
    arr[1] = 1;
    int sum = 0;
    for(int i=2;i<=m;i++){
        sum += arr[i-1];
        arr[i] = sum+1;
    }
    //i = 4   5
    //j = 123 234
    for(int i=m+1;i<=n;i++){
        for(int j=i-m;j<=i-1;j++){
            arr[i] += arr[j];
        }
    }
    printf("%d",arr[n]);
    return 0;
}
