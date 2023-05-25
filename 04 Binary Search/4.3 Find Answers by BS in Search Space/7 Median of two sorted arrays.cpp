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
    int binarySearch(int st,int end,int req,vector<int>&n1,vector<int>&n2){
        int i=st,j=end;
        while(i<=j){
            int mid=i+(j-i)/2;

            int t1=upper_bound(n1.begin(),n1.end(),mid)-n1.begin();
            int t2=upper_bound(n2.begin(),n2.end(),mid)-n2.begin();

            if(t1+t2<req){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }

        return i;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1==0){
            if(n2%2){
                return (double) nums2[n2/2];
            }else{
                return  ((nums2[n2/2-1]+nums2[n2/2])*1.0)/2;
            }
        }
        if(n2==0){
            if(n1%2){
                return (double) nums1[n1/2];
            }else{
                return  ((nums1[n1/2-1]+nums1[n1/2])*1.0)/2;
            }
        }
        int req=(n1+n2)/2;
        int st=*min_element(nums1.begin(),nums1.end());
        st=min(st,*min_element(nums2.begin(),nums2.end()));

        int end=*max_element(nums1.begin(),nums1.end());
        end=max(end,*max_element(nums2.begin(),nums2.end()));
        int val1=binarySearch(st,end,req,nums1,nums2);
        int val2=binarySearch(st,end,req+1,nums1,nums2);
        if((n1+n2)%2){
            return (double) val2;
        }
        return ((val1+val2)*1.0)/2;
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