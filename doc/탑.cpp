#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main() {
    
    int n,input;
     arr;
    vector<int> result;
    stack<int> s;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        arr.push_back(scanf("%d",&input));
    }
    
    for(int i=n-1;i>=0;i--){
        if(!s.empty()&&arr[s.top()]<arr[i]&&i!=n-1){
            while(!s.empty()&&arr[s.top()]<arr[i]){
                result[s.top()] = i+1;
                s.pop();
            }
        }
        s.push(i);
    }
    
    for(int i=0;i<n;i++){
        printf("%d ",result[i]);
    }
    
    return 0;
}
