#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int val){
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

void PrintBST(TreeNode *root,string & s){
    if(root==NULL)return;
    PrintBST(root->left,s);
    s+=(to_string(root->val)+" ");
    PrintBST(root->right,s);
};

TreeNode * insertBST(TreeNode * root,int val){
    TreeNode * newNode = new TreeNode(val);
    if(root==NULL){
        root = newNode;
        return root;
    };
    if(val < root->val) root->left = insertBST(root->left,val);
    else if(val > root->val) root->right = insertBST(root->right,val);

    return root;
}

TreeNode * searchBST(TreeNode * root, int val){
    if(root==NULL) return NULL;
    if(root->val == val){
        cout<<root->val;
        return root;
    }
    else if(val > root->val){
        cout<<root->val<<"->";
        searchBST(root->right,val);
    }else{
        cout<<root->val<<"->";
        searchBST(root->left,val);
    }
}

TreeNode * inOrderSuccessor(TreeNode* root){
    while(root->left !=NULL){
        root = root->left;
    }
    return root;
}

TreeNode * deletionBST(TreeNode * root,int val){
    if(val > root->val){
        root->right = deletionBST(root->right,val);
    }else if(val < root->val){
        root->left = deletionBST(root->left,val);
    }else{
        if(root->left==NULL){
            TreeNode * tmp = root->right;
            free(root);
            return tmp;
        }else if(root->right==NULL){
            TreeNode * tmp = root->left;
            free(root);
            return tmp;
        }else{
            TreeNode * tmp = inOrderSuccessor(root->right);
            root->val = tmp->val;
            root->right = deletionBST(root->right,tmp->val);
        }
        return root;
    }
}

int main(){
    int n;
    cin>>n;
    TreeNode * root = NULL;
    while(n--){
        int val;
        cin>>val;
        root = insertBST(root,val);
    };
    string s;
    PrintBST(root,s);
    cout<<s<<endl;

    cout<<"Enter the value which you want to search : ";
    int x;
    cin>>x;
    if(searchBST(root,x)==NULL)cout<<endl<<"This value does not exits in this Binary Search Tree"<<endl;

    cout<<endl<<"Enter value which you want to delete"<<endl;
    int y;
    cin>>y;
    root = deletionBST(root,y);

    string str;
    PrintBST(root,str);
    cout<<str<<endl;

    return 0;
}

