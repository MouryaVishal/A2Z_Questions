#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct Node
{
    int data;
    Node *left, *right;
    Node *prev;
    int data;
    Node *next;
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#define fr(i, num) for (int i = 0; i < num; i++)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<k;i++){
            q.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(q.top()<nums[i]){
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};

int main()
{
    int num;
    cout << "Enter number of element in an array:- ";
    cin >> num;
    vector<int> vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
    Solution obj;
}