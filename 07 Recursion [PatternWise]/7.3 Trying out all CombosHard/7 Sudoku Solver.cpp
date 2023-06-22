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
    Node* prev;
    int data;
    Node* next;
    Node()
    { 
    prev = NULL;
    data = 0;
    next = NULL;
    }
    
    Node(int value)
    {
    prev = NULL;
    data = value;
    next = NULL;
    }
  };
struct ListNode {
  int val;
  ListNode *next;
   ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i,num) for(int i=0;i<num;i++)


// !Solution 
class Solution {
    bool ispossible(int i,int j,vector<vector<char>>& b,char t){
        for(int k=0;k<9;k++){
            if(b[i][k]==t)return false;
            if(b[k][j]==t)return false;
        }
        
        for(int x=(i/3)*3;x<(i/3)*3+3;x++){
            for(int y=(j/3)*3;y<(j/3)*3+3;y++){
                
                if(b[x][y]==t)return false;
            }
        }

        return true;
    }
    bool solRec(vector<vector<char>>& b){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                // cout<<ispossible(i,j,b,'5')<<endl;
                if(b[i][j]=='.'){
                    // cout<<"dfd"<<endl;
                    for(char c='1';c<='9';c++){
                        if(ispossible(i,j,b,c)){
                            // cout<<"dewfd"<<endl;
                            b[i][j]=c;
                            if(solRec(b)){
                                return true;
                            }
                            b[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& b) {
        solRec(b);
    }
};
// !Solution 
int main(){
    int num;
    cout<<"Enter number of element in an array:- ";
    cin>>num;
    vector<int>  vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
}