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
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        int n=a.size();
        disJointSet obj(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<a[i].size();j++){
                // cout<<a[i][0]<<" "<<a[i][j]<<" ";
                if(mp.find(a[i][j])==mp.end()){
                    mp[a[i][j]]=i;
                }else{
                    // cout<<a[i][0]<<" "<<a[i][j]<<" ";
                    obj.unionByRank(i,mp[a[i][j]]);
                }
            }
            // cout<<endl;
        }

        unordered_map<int,set<string>> temp;
        for(auto&ng:mp){
            // cout<<ng.first<<" "<<ng.second<<endl;
            int ulp=obj.findultimateParent(ng.second);
            // cout<<ulp<<" "<<ng.second<<" "<<ng.first<<endl;
            temp[ulp].insert(ng.first);
        }

        vector<vector<string>> ans;
        for(auto&ng:temp){
            vector<string> flag;
            flag.push_back(a[ng.first][0]);
            for(auto&ele:ng.second){
                flag.push_back(ele);
            }
            ans.push_back(flag);
        }
        return ans;
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