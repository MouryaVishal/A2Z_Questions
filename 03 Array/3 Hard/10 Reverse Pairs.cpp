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
    int merge(int st,int mid,int end,vector<int>&arr){
        int n=end-st+1;
        vector<int>temp(n);
        int i(st),j(mid+1),k(0);
        int ans=0;
        while(i<=mid && j<=end){
            if((long long)arr[i]>(long long)2*arr[j]){
                ans+=mid-i+1;
                j++;
            }else{
                i++;
            }
        }
        i=st,j=(mid+1);
        while(i<=mid && j<=end){
            if(arr[i]<=arr[j]){
                temp[k++]=arr[i++];
            }else{
                temp[k++]=arr[j++];
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
         while(j<=end){
            temp[k++]=arr[j++];
        }
        for(int i=0;i<n;i++){
            arr[st+i]=temp[i];
        }
        return ans;
    }
    int mergeSort(int i,int j,vector<int>&nums){
        if(i<j){
            int mid=i+(j-i)/2;
            int a1=mergeSort(i,mid,nums);
            int a2=mergeSort(mid+1,j,nums);
            int a3=merge(i,mid,j,nums);
            return a1+a2+a3;
        }
        return 0;
    }
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(0,nums.size()-1,nums);
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