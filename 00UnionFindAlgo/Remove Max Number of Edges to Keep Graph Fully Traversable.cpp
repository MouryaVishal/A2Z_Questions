#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class DsuClass{
    vector<int> parent,rank;
public:
    DsuClass(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
    }
    int findParent(int x){
        return parent[x]=parent[x]==x?x:findParent(parent[x]);
    }
    bool unionForNode(int x,int y){
        int xpar=findParent(x),ypar=findParent(y);
        if(xpar!=ypar){
            if(rank[xpar]<rank[ypar]){
                parent[xpar]=ypar;
            }else if(rank[xpar]>rank[ypar]){
                parent[ypar]=xpar;
            }else{
                parent[xpar]=ypar;
                rank[ypar]++;
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DsuClass alice(n+1),bob(n+1);
        int remove=0;
        int aliceEdge=0;
        int bobEdge=0;
        sort(begin(edges),end(edges),[&](auto const &a,auto const &b){
            return a[0]>b[0];
        });
        for(auto &a:edges){
            if(a[0]==3 && alice.unionForNode(a[1],a[2])){
                bob.unionForNode(a[1],a[2]);
                aliceEdge++;
                bobEdge++;
            }else if(a[0]==3){
                remove++;
            }

            if(a[0]==1 && alice.unionForNode(a[1],a[2])){
                aliceEdge++;
            }else if(a[0]==1){
                remove++;
            }

            if(a[0]==2 && bob.unionForNode(a[1],a[2])){
                bobEdge++;
            }else if(a[0]==2){
                remove++;
            }
        }


        if(aliceEdge==n-1 && aliceEdge==bobEdge) return remove;

        return -1;
    }
};



#define fr(i,num) for(int i=0;i<num;i++)
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
}