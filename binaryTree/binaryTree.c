#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

binaryTree *searchTree(binaryTree *node, int key)
{
    if (node == NULL) return(NULL);

    if (node->item == key) return(node);

    if (key < node->item)
    {
        return(searchTree(node->left, key));
    }
    else
    {
        return(searchTree(node->right, key));
    }
}

// Time Complexity: O(h), where h denotes the height of the tree

void insertNode(binaryTree **node, int key, binaryTree *parent)
{
    binaryTree *p;

    if (*node == NULL)
    {
        p = malloc(sizeof(binaryTree));
        p->item = key;
        p->left = p->right = NULL;
        p->parent = parent;
        *node = p;
        return;
    }

    if (key < (*node)->item)
    {
        insertNode(&((*node)->left), key, *node);
    }
    else
    {
        insertNode(&((*node)->right), key, *node);
    }
}

void traverseTree(binaryTree *node)
{
    if (node != NULL)
    {
        traverseTree(node->left);
        printf("Item: %d\n", node->item);
        traverseTree(node->right);
    }
}

binaryTree *minimumIterativeSearch(binaryTree *node)
{
    binaryTree *min;

    if (node == NULL) return(NULL);
    min = node;
    while (min->left != NULL)
    {
        min = min->left;
    }
    return(min);
}

binaryTree *minimumRecursiveSearch(binaryTree *node)
{
    if (node == NULL)
    {
        return(NULL);
    }
    else if (node->left != NULL)
    {
        return(minimumRecursiveSearch(node->left));
    }
    else
    {
        return(node);
    }
}

binaryTree *maximumIterativeSearch(binaryTree *node)
{
    binaryTree *max;

    if (node == NULL) return(NULL);
    max = node;
    while (max->right != NULL)
    {
        max = max->right;
    }
    return(max);
}

binaryTree *maximumRecursiveSearch(binaryTree *node)
{
    if (node == NULL)
    {
        return(NULL);
    }
    else if (node->right != NULL)
    {
        return(maximumRecursiveSearch(node->right));
    }
    else
    {
        return(node);
    }
}