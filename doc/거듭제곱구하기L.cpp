#include <cstdio>
using namespace std;
int n,m;
int main(){
    scanf("%d %d",&n,&m);
    int tmp = n;
    m--;
    while(m){
        n *= tmp;
        n %= 10007;
        m--;
    }
    
    printf("%d\n",n);
    return 0;
}
