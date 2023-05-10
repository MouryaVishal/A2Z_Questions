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
class Codec {
public:
    string serialize(TreeNode* root) {
        string str="";
        if(!root)return str;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            if(a==NULL){
                str+="*";
                str+=",";
            }else{
                str+=to_string(a->val)+",";
            }
            if(a){
                q.push(a->left);
                q.push(a->right);
            }
        }
        cout<<str;
        return str;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="*"){
                a->left=NULL;
            }else{
                TreeNode* left=new TreeNode(stoi(str));
                a->left=left;
                q.push(left);
            }
            getline(s,str,',');
            if(str=="*"){
                a->right=NULL;
            }else{
                TreeNode* right=new TreeNode(stoi(str));
                a->right=right;
                q.push(right);
            }
        }

        return root;
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
    // Solution obj;
}