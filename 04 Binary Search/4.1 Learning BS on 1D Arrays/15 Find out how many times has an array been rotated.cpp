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
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int st=0;
	    int end=n-1;
	    while(st<=end){
	        int mid=st+(end-st)/2;
	        if(arr[st]<=arr[end])return st;
	       // cout<<"fs"<<mid<<endl;
	        if((mid==0 || arr[mid-1]>arr[mid]) && (mid==n-1||arr[mid+1]>arr[mid])){
	            return mid;}
	        if(arr[st]<=arr[mid])st=mid+1;
	        else end=mid-1;
	    }
	    
	    return end;
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