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