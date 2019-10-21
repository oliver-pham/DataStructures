#include <stdio.h>
#include <binaryTree.h>

binaryTree *search(binaryTree *node, int key)
{
    if (node == NULL) return(NULL);

    if (node->item == key) return(node);

    if (key < node->item)
    {
        return(search(node->left, key));
    }
    else
    {
        return(search(node->right, key));
    }
}

// Time Complexity: O(h), where h denotes the height of the tree