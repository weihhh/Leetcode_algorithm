#include<iostream>
#include<stdlib.h>
#include<malloc.h>

using namespace std;

typedef struct BinaryTreeNode{
    char value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

//根据先序生成

void createBtree(BinaryTreeNode * &T){
    char ch;
    cin>>ch;
    if (ch=='#') T=NULL;
    else{
        T=new BinaryTreeNode;
        T->value=ch;
        createBtree(T->left);
        createBtree(T->right);
    }
}