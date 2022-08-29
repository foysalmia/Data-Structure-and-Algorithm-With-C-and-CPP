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

void preOrder(TreeNode * head,string  &check){
    if(head == NULL)return;
    check+= to_string(head->value);
    preOrder(head->left,check);
    preOrder(head->right,check);
}

void inOrder(TreeNode * head,string  &check){
    if(head == NULL)return;
    inOrder(head->left,check);
    check+= to_string(head->value);
    inOrder(head->right,check);
}

void postOrder(TreeNode * head,string  &check){
    if(head == NULL)return;
    postOrder(head->left,check);
    postOrder(head->right,check);
    check+= to_string(head->value);
}

int main(){
    int n;
    cin>>n;
    TreeNode * allNodes[n];

    for(int i=0;i<n;i++){
        allNodes[i] = new TreeNode(-1);
    }
    for(int i=0;i<n;i++){
        int value,left,right;
        cin>>value>>left>>right;
        allNodes[i]->value = value;

        if(left != -1) allNodes[i]->left = allNodes[left];
        if(right != -1) allNodes[i]->right = allNodes[right];
    }

    printTreeNode(allNodes[0],0);

    string inOderTraverse = "";
    string preOderTraverse = "";
    string postOderTraverse = "";

    inOrder(allNodes[0],inOderTraverse);
    preOrder(allNodes[0],preOderTraverse);
    postOrder(allNodes[0],postOderTraverse);

    cout<<"InOrder Traversal : "<<inOderTraverse<<endl;
    cout<<"PreOrder Traversal : "<<preOderTraverse<<endl;
    cout<<"PostOrder Traversal : "<<postOderTraverse<<endl;
    return 0;
}

/*
CHECK WITH THIS FIRST
9
0 1 2
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

inOrder : 314075826
preOrder: 013425786
postOrder: 341785620
*/
