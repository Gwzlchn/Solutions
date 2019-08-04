#include<vector>
#include<cstdio>
using namespace std;


void dfs(
    int depth,
    int& max_dep,
    int node_index,
    const vector<vector<int>>& tree, 
    vector<int>& each_level
){
    //printf("aaa%d",node_index);
    if(tree[node_index].size()==0){
        each_level[depth]++;
        max_dep = (max_dep > depth)?max_dep:depth;
        return;
    }
    for(auto iter = tree[node_index].begin();iter!=tree[node_index].end();iter++){
        dfs(depth+1,max_dep,*iter,tree,each_level);
        
    }
    return;
}


int main(){
    int level=0,non_leaf = 0;
    //存每个节点子节点
    vector<vector<int>> tree(101,vector<int>());
    //存每层叶子节点
    vector<int> each_level_leaves(101);
    //存最大深度
    int max_depth = -1;
    scanf("%d %d",&level,&non_leaf);
    for(int i=0;i<non_leaf;i++){
        int parent = 0,count=0;
        scanf("%d %d",&parent,&count);
        int child=0;
        for(int j=0;j<count;j++){
            scanf("%d",&child);
            tree[parent].push_back(child);
        }
    }
    dfs(0,max_depth,1,tree,each_level_leaves);

    printf("%d",each_level_leaves[0]);
    for(int i=1;i<=max_depth;i++){
        printf(" %d",each_level_leaves[i]);
    }
    return 0;

    //dfs 搜索

}