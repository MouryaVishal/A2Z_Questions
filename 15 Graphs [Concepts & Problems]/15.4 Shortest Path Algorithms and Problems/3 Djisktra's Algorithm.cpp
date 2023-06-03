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
#define fr(i,num) for(int i=0;i<num;i++)
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        vector<int>dis(v,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        q.push({0,s});
        dis[s]=0;
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            int node=a.second;
            int currDis=a.first;
            for(auto&ng:adj[node]){
                if(ng[1]+currDis<dis[ng[0]]){
                    dis[ng[0]]=ng[1]+currDis;
                    q.push({dis[ng[0]],ng[0]});
                }
            }
        }
        
        return dis;
        // Code here
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