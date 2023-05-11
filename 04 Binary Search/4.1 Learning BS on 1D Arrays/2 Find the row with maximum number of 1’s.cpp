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
};

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int r = 0;
        int c = m - 1;
        int ans = -1;
        while (r < n && c >= 0)
        {
            if (arr[r][c] == 1)
            {
                c--;
                ans = r;
            }
            else
            {
                r++;
            }
        }
        // cout<<r<<" "<<c<<endl;
        return ans;
    }
};

#define fr(i, num) for (int i = 0; i < num; i++)
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