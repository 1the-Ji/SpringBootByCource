#include <cstdio>
using namespace std;


struct Tree{
    int left;
    int right;
};

const int MAX = 100;

Tree tree[MAX];

void preorder(int x){
    if(tree[x].left == -1 && tree[x].right == -1){
        printf("%d ",x);
    }else{
        preorder(x);
        
        if(tree[x].left!=-1)
            preorder(tree[x].left);
        
        if(tree[x].right!=-1)
            preorder(tree[x].right);
    }
}
void inorder(int x){
    
}
void postorder(int x){
    
}

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        tree[a].left = b;
        tree[a].right = c;
    }
    preorder(1);
    //inorder(1);
    //postorder(1);
    
    return 0;
}
