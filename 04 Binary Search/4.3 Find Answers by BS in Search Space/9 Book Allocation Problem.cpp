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
    //Function to find minimum number of pages.
    int findPages(int a[], int N, int M) 
    {
        if(N<M)return -1;
        int st=*max_element(a,a+N);
        int end=0;
        for(int i=0;i<N;i++){
            end+=a[i];
        }
        
        while(st<=end){
            int mid=st+(end-st)/2;
            int count=0;
            int currSum=0;
            for(int i=0;i<N;i++){
                if(currSum+a[i]<=mid){
                    currSum+=a[i];
                }else{
                    count++;
                    currSum=a[i];
                }
            }
            count++;
            if(count<=M){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return st;
        //code here
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