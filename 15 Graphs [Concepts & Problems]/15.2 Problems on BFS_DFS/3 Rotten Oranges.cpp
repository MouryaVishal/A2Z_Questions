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
class Solution {
    bool isPossible(int &i,int &j,vector<vector<int>>& g){
        return i>=0 && j>=0 && i<g.size() && j<g[0].size() && g[i][j]==1;
    }
public:
    int orangesRotting(vector<vector<int>>& g) {
        int count=0;
        queue<pair<int,int>> q;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int fresh=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==2){
                    q.push({i,j});
                    g[i][j]=0;
                }else if(g[i][j]==1){
                    fresh++;
                }
            }
        }

        while(!q.empty()){
            int s=q.size();
            int flag=0;
            while(s--){
                auto a=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=a.first+dx[k];
                    int ny=a.second+dy[k];
                    if(isPossible(nx,ny,g)){
                        fresh--;
                        q.push({nx,ny});
                        g[nx][ny]=0;
                        flag=1;
                    }
                }
            }
            if(flag){
                count++;
            }
        }
        if(fresh>0)return -1;
        // for(int i=0;i<g.size();i++){
        //     for(int j=0;j<g[0].size();j++){
        //         if(g[i][j]==1)return -1;
        //     }
        // }
        return count;
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