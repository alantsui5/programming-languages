//
// Created by Alan on 2019-03-14.
//

/* File: BinaryTreeADT.h */
#include <stdbool.h>
#include <stdio.h>
#include "string.h"
#include "stdlib.h"
typedef struct BinaryTreeCDT *BinaryTreeADT;
typedef struct TreeNodeCDT *TreeNodeADT;
const TreeNodeADT SpecialErrNode = (TreeNodeADT) NULL;
BinaryTreeADT NonemptyBinaryTree(TreeNodeADT,BinaryTreeADT, BinaryTreeADT);
BinaryTreeADT EmptyBinaryTree(void);
BinaryTreeADT LeftSubtree(BinaryTreeADT);
BinaryTreeADT RightSubtree(BinaryTreeADT);
bool TreeIsEmpty(BinaryTreeADT);
TreeNodeADT Root(BinaryTreeADT);
TreeNodeADT NewTreeNode(char*, int);
int GetNodeData(TreeNodeADT);
char *GetNodeKey(TreeNodeADT);



