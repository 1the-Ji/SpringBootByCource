#include<cstdio>
using namespace std;

const long long MAX = 100000;
int n;
long long a[MAX],b[MAX];

void mergeSort(long long start, long long end){
    
    if(start==end){
        return;
    }
    
    long long mid = (start+end)/2;
    
    mergeSort(start,mid);
    
    mergeSort(mid+1,end);
    
    long long i = start, j = mid + 1, k = 0;
    
    while(i<= mid && j <= end)  {
        if(a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];       // 새로운 배열에 sorting하면서 집어넣어
    }
    while(i<=mid) b[k++] = a[i++];
    while(j<=end) b[k++] = a[j++];
    
    for(long long e= start;e<=end;e++) {
        a[i] = b[e-start];
    }
	
}


int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    
    mergeSort(0,n-1);
    
    for(int i=0;i<n;i++){
        printf("%lld ",a[i]);
    }
    
    return 0;
}

