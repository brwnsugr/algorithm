#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode *left;
    struct _bTreeNode *right;
} BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode *bt);
void SetData(BTreeNode *bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode *bt);
BTreeNode* GetRightSubTree(BTreeNode *bt);

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);

#endif /* BinaryTree_hpp */