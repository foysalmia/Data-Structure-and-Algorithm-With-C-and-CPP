#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int value;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int value){
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode * createTreeNode(){
    TreeNode * root = NULL;

    int a;
    cout<<"Enter Value : ";
    cin>>a;
    if(a == -1 ) return NULL;
    root = new TreeNode(a);
    cout<<"Enter left for "<<a<<endl;
    root->left = createTreeNode();

    cout<<"Enter right for "<<a<<endl;
    root->right = createTreeNode();

    return root;
}

int main(){
    TreeNode * head = NULL;
    head = createTreeNode();

    cout<<"Successfully created Binary Tree Node "<<endl;
    return 0;
}
