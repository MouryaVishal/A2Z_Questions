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
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        if(color==image[sr][sc]) return ans;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int c=ans[sr][sc];
        ans[sr][sc]=color;
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            // ans[a.first][a.second]=color;
            for(int i=0;i<4;i++){
                int nx=dx[i]+a.first;
                int ny=dy[i]+a.second;
                if(nx>=0 && ny>=0 && nx<ans.size() && ny<ans[0].size() && ans[nx][ny]==c){
                    q.push({nx,ny});
                    ans[nx][ny]=color;
                }
            }
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