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
struct Node{
   int data;
   Node* left, * right;
};
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)

class disJointSet{
    public:
    vector<int> rank,parent;
    disJointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findultimateParent(int x){
        if(parent[x]==x)return x;
        return parent[x]=findultimateParent(parent[x]);
    }

    bool unionByRank(int u,int v){
        int pu=findultimateParent(u);
        int pv=findultimateParent(v);
        if(pu==pv)return true;

        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }else{
            parent[pv]=pu;
            rank[pu]++;
        }
        return false;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0;
        int maxCol=0;
        for(auto&a:stones){
            maxRow=max(maxRow,a[0]);
            maxCol=max(maxCol,a[1]);
        }

        disJointSet obj(maxRow+maxCol+1);
        unordered_map<int,int> st;
        for(auto&a:stones){
            obj.unionByRank(a[0],a[1]+maxRow+1);
            st[a[0]]=1;
            st[a[1]+maxRow+1]=1;
        }
        int comp=0;
        for(auto&a:st){
            if(obj.findultimateParent(a.first)==a.first)comp++;
        }
        return stones.size()-comp;
    }
};



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