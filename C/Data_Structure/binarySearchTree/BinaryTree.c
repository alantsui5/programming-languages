//
// Created by Alan on 2019-03-14.
//

#include "BinaryTree.h"
#include "stdlib.h"
struct TreeNodeCDT {
    char* key;
    int nodeData;
};

struct BinaryTreeCDT {
    TreeNodeADT rt;
    BinaryTreeADT lst;
    BinaryTreeADT rst;
};

BinaryTreeADT EmptyBinaryTree() {
    return (BinaryTreeADT) NULL;
}

BinaryTreeADT NonemptyBinaryTree(TreeNodeADT N, BinaryTreeADT L, BinaryTreeADT R) {
    BinaryTreeADT t = (BinaryTreeADT) malloc(sizeof(*t));
    t->rt = N;
    t->lst = L;
    t->rst = R;
    return t;
}

TreeNodeADT Root(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rt;
}

BinaryTreeADT LeftSubtree(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->lst;
}

BinaryTreeADT RightSubtree(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    return t->rst;
}

bool TreeIsEmpty(BinaryTreeADT t) {
    return t == (BinaryTreeADT) NULL;
}


TreeNodeADT NewTreeNode(char* k, int d) {
    TreeNodeADT N = (TreeNodeADT) malloc(sizeof(TreeNodeADT));
    N->key = (char*) malloc(sizeof(char)*(strlen(k)+1)); strcpy(N->key, k);
    N->nodeData = d;
    return(N);
}

char *GetNodeKey(TreeNodeADT N) {
    char *k;
    if (N==(TreeNodeADT)NULL) exit(EXIT_FAILURE);
    k = (char*) malloc(sizeof(char)*(strlen(N->key)+1)); strcpy(k, N->key);
    return k;
}

int GetNodeData(TreeNodeADT N) {
    return N->nodeData;
}

TreeNodeADT FindNode(BinaryTreeADT t, char *key) {
    TreeNodeADT R; char *k; int sign;
    if (BinaryTreeIsEmpty(t)) return(SpecialErrNode);
    R = Root(t); k = GetNodeKey(R);
    sign = strcmp(key, k);
    if (sign == 0) return R;
    if (sign < 0) return FindNode(LeftSubtree(t), key);
    return FindNode(RightSubtree(t), key);
}

// ==============AVL Tree Section==============>
BinaryTreeADT LeftRotate(BinaryTreeADT t){
    return NonemptyBinaryTree(Root(RightSubtree(t)),
                              NonemptyBinaryTree(Root(t),
                                                 LeftSubtree(t),
                                                 LeftSubtree(RightSubtree(t))
                                                 ),
                              RightSubtree(RightSubtree(t))
                              );
}

BinaryTreeADT RightRotate(BinaryTreeADT t){
    return NonemptyBinaryTree(Root(LeftSubtree(t)),
                              LeftSubtree(LeftSubtree(t)),
                              NonemptyBinaryTree(Root(t),
                                                 LeftSubtree(RightSubtree(t)),
                                                 RightSubtree(t)
                                                )
                              );
}

BinaryTreeADT RightLeftRotate(BinaryTreeADT t){
    LeftRotate(NonemptyBinaryTree(Root(t),
                                  LeftSubtree(t),
                                  RightRotate(RightSubtree(t))
                                  )
               );
}

BinaryTreeADT LeftRightRotate(BinaryTreeADT t){
    RightRotate(NonemptyBinaryTree(Root(t),
                                   LeftRotate(LeftSubtree(t)),
                                   RightSubtree(t)
                                   )
                );
}

BinaryTreeADT AVLInsertNode(TreeNodeADT X, BinaryTreeADT T)
if (AVLTreeIsEmpty(T))return NonemptyAVLTree(X, EmptyAVLTree(), EmptyAVLTree()); int sign = strcmp(GetNodeKey(X), GetNodeKey(AVLRoot(T)));
if (sign == 0) return NonemptyAVLTree(X, LeftAVLSubtree(T), RightAVLSubtree(T));
if (sign < 0) {
    AVLTreeADT NewTree = NonemptyAVLTree(AVLRoot(T),
                                         AVLInsertNode(X,LeftAVLSubtree(T)),
                                         RightAVLSubtree(T)
                                         );
    if (AVLTreeHeight(LeftAVLSubtree(NewTree)) – AVLTreeHeight(RightAVLSubtree(NewTree)) == 2)
        return (strcmp(GetNodeKey(X), GetNodeKey(AVLRoot(LeftAVLSubtree(NewTree)))) < 0 ? RightRotate(NewTree) :
                LeftRightRotate(NewTree)); return NewTree;
};
if (sign > 0) {
    AVLTreeADT NewTree = NonemptyAVLTree(AVLRoot(T),
                                         LeftAVLSubtree(T),
                                         AVLInsertNode(X,RightAVLSubtree(T))
                                         );
    if (AVLTreeHeight(RightAVLSubtree(NewTree)) – AVLTreeHeight(LeftAVLSubtree(NewTree)) == 2)
        return (strcmp(GetNodeKey(X), GetNodeKey(AVLRoot(RightAVLSubtree(NewTree)))) > 0 ? LeftRotate(NewTree) :
                RightLeftRotate(NewTree)); return NewTree;
} }
