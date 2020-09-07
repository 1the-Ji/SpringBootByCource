#include<cstdio>

using namespace std;

int n;
int arr[81];
bool found = false;

bool check(int depth)
{
    if (arr[depth] == arr[depth - 1]) // 붙어있으면 안됨
        return false;
    if (depth == 0 || depth == 1 || depth == 2)
        return true;
    
    int max_size = (depth + 1) / 2;
    
    for (int i = 2; i <= max_size; i++)
    {
        bool ok = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[depth - j] != arr[depth - j - i])
            {
                ok = true;
                break;
            }
        }
        if (!ok)
            return false;
    }
    
    return true;
}


void dfs(int depth)
{
    if (depth == n)
    {
        found = true;
        return;
    }
    for (int i = 1; i < 4; i++)
    {
        arr[depth] = i;
        
        if (check(depth))
        {
            dfs(depth + 1);
            if (found)
                break;
        }
    }
}

int main()
{
    scanf("%d", &n);
    
    dfs(0);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
