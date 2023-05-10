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

class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    for(int k=0;k<m[0].size();k++){
                        if(m[i][k]!=0)
                            m[i][k]=1e8;
                    }
                    for(int k=0;k<m.size();k++){
                        if(m[k][j]!=0)
                            m[k][j]=1e8;
                    }
                }
            }
        }
        
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==1e8){
                    m[i][j]=0;
                }
            }
        }

    }
};

class Solution2 {
public:
    void setZeroes(vector<vector<int>>& m) {
        set<int> r;
        set<int> c;
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }

        for(auto &a:r){
            for(int i=0;i<m[0].size();i++){
                m[a][i]=0;
            }
        }
        for(auto &a:c){
            for(int i=0;i<m.size();i++){
                m[i][a]=0;
            }
        }
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