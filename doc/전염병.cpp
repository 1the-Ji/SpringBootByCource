#include <cstdio>
#include <queue>
using namespace std;
int main() {
    int a,b,cnt;
    queue<int> input;
    bool check[1000000];
    scanf("%d %d",&a,&b);
    
    input.push(b);
    check[a] = true;
    cnt++;
    
    while(!input.empty()){
        int x = input.front();
        int tmpA = x*2;
        int tmpB = x/3;
        input.pop();
        if(tmpA>0&&tmpA<a&&check[tmpA]!=true){
            check[tmpA] = true;
            cnt++;
            input.push(tmpA);
        }
        if(tmpB>0&&tmpB<a&&check[tmpB]!=true){
            check[tmpB] = true;
            cnt++;
            input.push(tmpB);
        }
    }
    printf("%d",cnt);
    return 0;
}
