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
};

void printSpace(int level){
    for(int i=0;i<level;i++){
        cout<<"   ";
    }
}

void printTreeNode(TreeNode * root,int level){
    if(root == NULL)return;
    if(root->left == NULL && root->right == NULL){
        cout<<root->value<<endl;
        return;
    }else{
        cout<<endl;
        printSpace(level);
        cout<<"Root : "<<root->value<<endl;
    }
    if(root->left!=NULL){
        printSpace(level);
        cout<<"Left : ";
        printTreeNode(root->left,level+1);
    };
    if(root->right!=NULL){
        printSpace(level);
        cout<<"Right : ";
        printTreeNode(root->right,level+1);
    }
}

int main(){
    TreeNode * head = NULL;
    head = createTreeNode();

    printTreeNode(head,0);
    return 0;
}
