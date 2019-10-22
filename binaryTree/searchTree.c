#include "binaryTree.c"

int main(void)
{
    binaryTree tree = { 5, NULL, NULL, NULL };
    binaryTree *pTree = &tree;
    binaryTree *minimumValue;
    binaryTree *maximumValue;
    // Initialize a binary tree
    insertNode(&pTree, 15, pTree);
    insertNode(&pTree, 42, pTree);
    insertNode(&pTree, 29, pTree);
    insertNode(&pTree, 36, pTree);
    insertNode(&pTree, 1, pTree); 
    // Traverse the binary tree & display all of its elements
    traverseTree(pTree);
    // Display the minimum key in the tree using iteration
    minimumValue = minimumIterativeSearch(pTree);
    printf("Minimum Value in the Binary Tree: %d\n", minimumValue->item);
    // Display the minimum key in the tree using recursion
    minimumValue = minimumRecursiveSearch(pTree);
    printf("Minimum Value in the Binary Tree: %d\n", minimumValue->item);
    // Display the maximum key in the tree using iteration
    maximumValue = maximumIterativeSearch(pTree);
    printf("Maximum Value in the Binary Tree: %d\n", maximumValue->item);
    // Display the maximum key in the tree using recursion
    maximumValue = maximumIterativeSearch(pTree);
    printf("Maximum Value in the Binary Tree: %d\n", maximumValue->item);

    return 0;
}