#include "BinaryTree.hpp"
#include <stdio.h>
#include <stdlib.h>

BTreeNode* MakeBTreeNode(void){
    BTreeNode *bt;
    bt = (BTreeNode*)malloc(sizeof(BTreeNode));
    bt->left = NULL;
    bt->right = NULL;
    return bt;
}

BTData GetData(BTreeNode *bt){
    return bt->data;
}

void SetData(BTreeNode *bt, BTData data){
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode *bt){
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode *bt){
    return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub){
    if(main->left != NULL){
        free(main->left);
    }
    main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub){
    if(main->right != NULL){
        free(main->right);
    }
    main->right = sub;
}