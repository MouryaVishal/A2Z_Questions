#include <bits/stdc++.h>
using namespace std;

#define fr(i, num) for (int i = 0; i < num; i++)

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    void findParent(TreeNode *r, unordered_map<TreeNode *, TreeNode *> &par)
    {
        queue<TreeNode *> q;
        q.push(r);
        while (!q.empty())
        {
            auto a = q.front();
            q.pop();
            if (a->left)
            {
                par[a->left] = a;
                q.push(a->left);
            }
            if (a->right)
            {
                par[a->right] = a;
                q.push(a->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        findParent(root, parent);

        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, bool> vis;
        vis[target] = true;
        int size = 0;
        while (!q.empty())
        {
            int s = q.size();
            if (size == k)
                break;
            while (s--)
            {
                TreeNode *t = q.front();
                q.pop();
                if (t->left && !vis[t->left])
                {
                    vis[t->left] = true;
                    q.push(t->left);
                }
                if (t->right && !vis[t->right])
                {
                    vis[t->right] = true;
                    q.push(t->right);
                }
                if (parent[t] && !vis[parent[t]])
                {
                    vis[parent[t]] = true;
                    q.push(parent[t]);
                }
            }
            size++;
        }

        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
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