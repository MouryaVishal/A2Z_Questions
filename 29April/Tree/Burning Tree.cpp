#include<bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    Node* reNode;
    void findParent(Node*r,unordered_map<Node*,Node*>&parent,int &tr){
        queue<Node*> q;
        q.push(r);
        while(!q.empty()){
            Node* a=q.front();
            q.pop();
            if(a->data==tr){
                reNode=a;
            }
            if(a->left){
                parent[a->left]=a;
                q.push(a->left);
            }
            if(a->right){
                parent[a->right]=a;
                q.push(a->right);
            }
        }
    }
  public:
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,Node*> parent;
        // Node* reNode;
        findParent(root,parent,target);
        unordered_map<Node*,bool> vis;
        int ans=0;
        queue<Node*> q;
        vis[reNode]=1;
        q.push(reNode);
        // cout<<reNode->data<<endl;
        
        while(!q.empty()){
            int s=q.size();
            while(s--){
                Node* a=q.front();
                q.pop();
                if(a->left && !vis[a->left]){
                    vis[a->left]=1;
                    q.push(a->left);
                }
                if(a->right && !vis[a->right]){
                    vis[a->right]=1;
                    q.push(a->right);
                }
                if(parent[a] && !vis[parent[a]]){
                    vis[parent[a]]=1;
                    q.push(parent[a]);
                }
            }
            ans++;
        }
        
        return ans-1;
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