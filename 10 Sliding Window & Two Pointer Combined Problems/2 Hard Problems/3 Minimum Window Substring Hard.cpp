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

// !Solution
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int ans = 1e9;
        int len = s.size();

        unordered_map<char, int> mp2;

        for (int k = 0; k < t.size(); k++)
        {
            mp2[t[k]]++;
        }

        int matchCount = 0;
        int reqMatchCount = t.size();

        unordered_map<char, int> mp1;
        int i = -1;
        int j = -1;
        int st = -1;

        while (true)
        {
            bool f1 = 0;
            bool f2 = 0;
            while (matchCount < reqMatchCount && i < len - 1)
            {
                i++;
                mp1[s[i]]++;

                if (mp2.find(s[i]) != mp2.end() && mp1[s[i]] <= mp2[s[i]])
                {
                    matchCount++;
                }
                f1 = 1;
            }

            // collecting ans and releasing
            while (j < i && matchCount == reqMatchCount)
            {
                j++;
                int currAns = i - j + 1;
                if (ans == 0 || currAns < ans)
                {
                    ans = currAns;
                    st = j;
                }

                if (mp1[s[j]] == 1)
                {
                    mp1.erase(s[j]);
                }
                else
                {
                    mp1[s[j]]--;
                }

                if (mp2.find(s[j]) != mp2.end() && mp1[s[j]] < mp2[s[j]])
                {
                    matchCount--;
                }

                f2 = 1;
            }

            if (f1 == 0 && f2 == 0)
                break;
        }
        if (ans == 1e9)
            return "";
        return s.substr(st, ans);
    }
};
// !Solution
int main()
{
    int num;
    cout << "Enter number of element in an array:- ";
    cin >> num;
    vector<int> vec;
    vector<string> svec;
    vector<vector<int>> dvec;
    vector<vector<string>> sdvec;
}