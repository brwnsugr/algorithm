#include "BinaryTree2.hpp"
#include <stdio.h>
#include <stdlib.h>

BTreeNode* MakeBTreeNode(void){
    BTreeNode *bt = (BTreeNode*)malloc(sizeof(BTreeNode));
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

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action){
    if(bt == NULL){
        return;
    }
    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action){
    if(bt == NULL){
        return;
    }
    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action){
    if(bt == NULL){
        return;
    }
    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

void ShowIntData(int data){
    printf("%d ", data);
}

int main (){
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    BTreeNode *bt6 = MakeBTreeNode();
    
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    SetData(bt5, 5);
    SetData(bt6, 6);
    
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);
    
    PreorderTraverse(bt1, ShowIntData); printf("\n");
    PostorderTraverse(bt1, ShowIntData); printf("\n");
    InorderTraverse(bt1, ShowIntData); printf("\n");
    
    return 0;
}