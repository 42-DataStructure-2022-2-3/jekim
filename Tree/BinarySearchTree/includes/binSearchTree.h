#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct BinSearchTreeNodeType {
	int data;

	struct BinSearchTreeNodeType* pLeftChild;
	struct BinSearchTreeNodeType* pRightChild;
} BSTNode;

typedef struct BinSearchTreeType {
	struct BinSearchTreeNodeType* pRootNode;
} BinSearchTree;

BinSearchTree* makeBinSearchTree(BSTNode rootNode);
BSTNode* getRootNodeBST(BinSearchTree* pBinSearchTree);
BSTNode* insert_recursive(BSTNode* pParentNode, BSTNode element);
BSTNode* search_recursive(BSTNode* pParentNode, int data);
BSTNode* insert_loop(BinSearchTree* pBinSearchTree, BSTNode element);
BSTNode* search_loop(BinSearchTree* pBinSearchTree, int data);

BSTNode *find_max_in_left_subtree(BSTNode *del_Node);
BSTNode *find_min_in_right_subtree(BSTNode *del_Node);


bool deleteBSTNode(BinSearchTree* pBinSearchTree, int data);
BSTNode* copyBSTNode(BSTNode element);
BSTNode* makeBSTNode(int inputData);

#endif // _BIN_SEARCH_TREE_