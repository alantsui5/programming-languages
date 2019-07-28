//
// Created by Alan on 2019-03-16.
//
#include "BinaryTreeOp.h"
BinaryTreeADT InsertNode(BinaryTreeADT t, TreeNodeADT n) {
    if (TreeIsEmpty(t)) return NonemptyBinaryTree(n, EmptyBinaryTree(), EmptyBinaryTree());
    else {
        int sign = strcmp(GetNodeKey(n), GetNodeKey(Root(t)));
        if (sign == 0)
            return NonemptyBinaryTree(n,LeftSubtree(t), RightSubtree(t)));
        if (sign < 0)
            return NonemptyBinaryTree(Root(t),InsertNode(LeftSubtree(t),n), RightSubtree(t));
    return NonemptyBinaryTree(Root(t),LeftSubtree(t), InsertNode(RightSubtree(t), n));
    }
}

TreeNodeADT FindMinNode(BinaryTreeADT t) {
    if (TreeIsEmpty(t)) return SpecialErrNode;
    if (TreeIsEmpty(LeftSubtree(t))) return Root(t);
    return FindMinNode(LeftSubtree(t));
}

BinaryTreeADT DeleteNode(BinaryTreeADT t, TreeNodeADT n) {
    if (TreeIsEmpty(t)) exit(EXIT_FAILURE);
    int sign = strcmp(GetNodeKey(n), GetNodeKey(Root(t)));
    if (sign<0) return NonemptyBinaryTree(Root(t),
        DeleteNode(LeftSubtree(t), RightSubtree(t));
    if (sign>0) return NonemptyBinaryTree(Root(t),
        LeftSubtree(t), DeleteNode(RightSubtree(t), n));
    if (!TreeIsEmpty(LeftSubtree(t)) && !TreeIsEmpty(RightSubtree(t))) {
        TreeNodeADT M = FindMinNode(RightSubtree(t));
        return NonemptyBinaryTree(M, LeftSubtree(t),
        DeleteNode(RightSubtree(t), M));};
    if (TreeIsEmpty(RightSubtree(t)))
        return LeftSubtree(t);
    else
        return RightSubtree(t);
}

