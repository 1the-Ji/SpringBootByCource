#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
//#include <algorithm>
using namespace std;

int n, k;

bool cmp(int a, int b) {
    return a > b;
}

vector<string> split(string s) {
    vector<string> spl;
    
    while(s.length() != 0) {
        string sp = s.substr(0, n / 4);
        spl.push_back(sp);
        s = s.substr(n / 4);
    }
    
    return spl;
}

void rotation(string &s) {
    string newStr;
    
    newStr += s[s.length() - 1];
    newStr += s.substr(0, s.length() - 1);
    
    s = newStr;
}

int changeToDecimal(string s) {
    
    int decimal = 0;
    
    for(int i = (int)s.length() - 1;i>=0;i--) {
        int temp = pow(16, i);
        
        temp *= (s[s.length() - i - 1] >= 'A' && s[i] <= 'F')?(s[s.length() - i - 1] - 'A' + 10):s[s.length() - i - 1]-'0';
        decimal += temp;
    }
    
    return decimal;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    
    for(int tt = 1;tt<=T;tt++) {
        scanf("%d %d", &n, &k);
        string s;
        cin >> s;
        
        vector<string> result;
        for(int i = 0;i<n / 4;i++) {
            vector<string> candidate = split(s);
            
            for(int j = 0;j<candidate.size();j++) {
                bool isInclude = true;
                for(int k = 0;k<result.size();k++) {
                    if(result[k] == candidate[j]) {
                        isInclude = false;
                        break;
                    }
                }
                if(isInclude) result.push_back(candidate[j]);
            }
            rotation(s);
        }
        vector<int> toDecimal;
        for(int i = 0;i<result.size();i++) {
            int num = changeToDecimal(result[i]);
            
            toDecimal.push_back(num);
        }
        sort(toDecimal.begin(), toDecimal.end(), cmp);
        
        int ans = toDecimal[k - 1];
        
        printf("#%d %d\n", tt, ans);
    }
    
    return 0;
}
