#include <bits/stdc++.h>
using namespace std;

#define fr(i, num) for (int i = 0; i < num; i++)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1, j = 1;
        while (j < nums.size())
        {
            if (nums[j] == nums[i - 1])
            {
                j++;
                while (j < nums.size() && nums[j] == nums[i - 1])
                {
                    j++;
                }
            }
            if (j < nums.size())
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
        }
        return i;
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
