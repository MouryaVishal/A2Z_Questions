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
	void shortest_distance(vector<vector<int>>&m){
	    // Code here
	    int n=m.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(m[i][j]==-1){
	                m[i][j]=1e9;
	            }
	        }
	    }
	    for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
    	        for(int j=0;j<n;j++){
    	            m[i][j]=min(m[i][j],m[i][via]+m[via][j]);
    	        }
    	    }
	    }
	    
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(m[i][j]==1e9){
	                m[i][j]=-1;
	            }
	        }
	    }
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