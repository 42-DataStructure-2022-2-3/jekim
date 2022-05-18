#include "../includes/binSearchTree.h"

BinSearchTree* makeBinSearchTree(BSTNode rootNode) {
    BinSearchTree* ret = (BinSearchTree *)calloc(sizeof(BinSearchTree), 1);
    if (!ret) return NULL;
    ret->pRootNode = copyBSTNode(rootNode);
    if (!ret->pRootNode) {
        free(ret);
        return NULL;
    }
    return ret;
};

BSTNode* copyBSTNode(BSTNode element) {
    BSTNode *ret = (BSTNode *)calloc(sizeof(BSTNode), 1);
    if (!ret) return NULL;
    ret->data = element.data;
    return ret;
};

BSTNode* makeBSTNode(int inputData) {
    BSTNode *ret = (BSTNode *)calloc(sizeof(BSTNode), 1);
    if (!ret) return NULL;
    ret->data = inputData;
    return ret;
};

BSTNode* getRootNodeBST(BinSearchTree* pBSTree) {
    return pBSTree->pRootNode;
};

BSTNode* insert_recursive(BSTNode* pParentNode, BSTNode element) {
    if (pParentNode->data == element.data) return NULL;
    if (!pParentNode) {
        pParentNode = copyBSTNode(element);
        return pParentNode;
    } else if (pParentNode->data < element.data) {
        insert(pParentNode->pRightChild, element);
    } else {
        insert(pParentNode->pLeftChild, element);
    }
};

BSTNode* search_recursive(BSTNode* pParentNode, int data) {
    if (!pParentNode || pParentNode->data == data) {
        return pParentNode;
    } else if (pParentNode->data < data) {
        search_recursive(pParentNode->pRightChild, data);
    } else {
        search_recursive(pParentNode->pLeftChild, data);
    }
};

BSTNode* insert_loop(BinSearchTree* pBinSearchTree, BSTNode element) {
    BSTNode *ret = pBinSearchTree->pRootNode;
    while (ret != NULL) {
        if (!ret) {
            break ;
        } else if (ret->data < element.data) {
            ret = ret->pRightChild;
        } else if (ret->data > element.data) {
            ret = ret->pLeftChild;
        } else {
            return NULL;
        }
    }
    ret = copyBSTNode(element);
};

BSTNode* search_loop(BinSearchTree* pBinSearchTree, int data) {
    BSTNode *ret = pBinSearchTree->pRootNode;
    while (ret != NULL) {
        if (ret->data == data) {
            break ;
        } else if (ret->data < data) {
            ret = ret->pRightChild;
        } else {
            ret = ret->pLeftChild;
        }
    }
    return ret;
};


bool deleteBSTNode(BinSearchTree* pBinSearchTree, int data) {

    BSTNode *del_Node = search_loop(pBinSearchTree, data);

    if (!del_Node) return false;

    if (!del_Node->pLeftChild && !del_Node->pRightChild)
    {   
        free(del_Node);
        del_Node = NULL;
    }
    if (!del_Node->pLeftChild || !del_Node->pRightChild)
    {
        BSTNode *tmp = del_Node;
        del_Node = del_Node->pLeftChild ? del_Node->pLeftChild : del_Node->pRightChild;
        free(tmp);
    }
    if (del_Node->pLeftChild && del_Node->pRightChild)
    {
        BSTNode *del = del_Node;
        BSTNode *tmp = NULL;
        BSTNode *del_Node_pLeftChild_Max = del_Node->pLeftChild;
        BSTNode *del_Node_pRightChild_Min = del_Node->pRightChild;

        while (true)
        {
            if (del_Node_pLeftChild_Max->pRightChild == NULL)
                break ;
            else
            {
                tmp = del_Node_pLeftChild_Max;
                del_Node_pLeftChild_Max = del_Node_pLeftChild_Max->pRightChild;
            }
        }
        del_Node = del_Node_pLeftChild_Max;
        if (del_Node_pLeftChild_Max->pLeftChild)
            tmp->pRightChild = del_Node_pLeftChild_Max->pLeftChild;
        else
            tmp->pRightChild = NULL;
        del_Node->pLeftChild = del->pLeftChild;
        del_Node->pRightChild = del->pRightChild;
        free(del);
    }
    return true;
};

BSTNode *find_max_in_left_subtree(BSTNode *del_Node)
{
    BSTNode *ret = del_Node->pLeftChild;
    
    while (ret->pRightChild)
        ret = ret->pRightChild;
    return (ret);
}

BSTNode *find_min_in_right_subtree(BSTNode *del_Node)
{
    BSTNode *ret = del_Node->pRightChild;
    
    while (ret->pLeftChild)
        ret = ret->pLeftChild;
    return (ret);

}

void printTreeData_InOrder(BSTNode* rootNode)
{
    if (rootNode->pLeftChild)
        printTreeData_InOrder(rootNode->pLeftChild);
    printf("%d ",rootNode->data);
    if (rootNode->pRightChild)
        printTreeData_InOrder(rootNode->pRightChild);
}