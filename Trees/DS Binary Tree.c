#include <stdio.h>
#include <stdlib.h>


struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *Right;
    struct BinaryTreeNode *Left;
};


void PreOrder( struct BinaryTreeNode *root) { //DLR
    if(root) {
        printf("%d\n",root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder( struct BinaryTreeNode *root) { //LDR
    if(root) {

        InOrder(root->left);
        printf("%d\n",root->data);
        InOrder(root->right);
    }
}

void PostOrder( struct BinaryTreeNode *root) { //LRD
    if(root) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d\n",root->data);
    }
}

/* Level order Traversal
1) Visit the node
2) While traversing the level 1, keep all the elements at level l+1 in queue
3) Go to next level and visit all the nodes at that level
4) Repeat this until all the levels are completed

*/

void LevelOrder( struct BinaryTreeNode *root) {
    struct BinaryTreeNode *temp
}
