#include <cstdio>
#include <stack>
#include <cstring>
#include <vector>

using namespace std;

bool complete = false;

int main(void)
{
    char str[50];
    scanf("%s", str);
    
    stack<int> s;
    int result = 0;
    int temp = 1;
    //  (()[[]])([]) = 28
    for(int i = 0;i<strlen(str);i++) {
        if(str[i] == '(') {
            temp *= 2;
            s.push(2);
        }
        else if(str[i] == '[') {
            temp *= 3;
            s.push(3);
        }
        else if(str[i] == ')' && !s.empty() && s.top() == 2) {
            if(s.empty())
                break;
            if(s.top() == 2 && str[i-1] == '(') {
                result += temp;
            }
            s.pop();
            temp /= 2;
        }
        else if(str[i] == ']' && !s.empty() && s.top() == 3) {
            if(s.empty())
                break;
            if(s.top() == 3 && str[i-1] == '[') {
                result += temp;
            }
            s.pop();
            temp /= 3;
        }
        if(s.empty()) temp = 1;
        if(strlen(str)-1 == i) complete = true;
    }
    
    if(complete && temp == 1) printf("%d\n", result);
    else puts("0");
    
    return 0;
}
