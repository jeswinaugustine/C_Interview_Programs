#include <stdio.h>
#include <stdlib.h>

typedef struct t_node {
    int data ;
    struct t_node *left, *right;
} tnode_t;

tnode_t* new_node(int value) {

    tnode_t *temp = (tnode_t *) malloc( sizeof(tnode_t));
    temp->data  =   value;
    temp->left  =   NULL;
    temp->right =   NULL;
    return temp;

}

void inorder(tnode_t *node) {

    if(node != NULL) {
        inorder(node->left);
        printf(" %d",node->data);
        inorder(node->right);
    }
}


void preorder(tnode_t *node) {

    if(node != NULL) {
        printf(" %d",node->data);
        inorder(node->left);
        inorder(node->right);
    }
}

void postorder(tnode_t *node) {

    if(node != NULL) {
        inorder(node->left);
        inorder(node->right);
        printf(" %d",node->data);
    }
}

tnode_t* insert(tnode_t *node, int value) {
    if(node == NULL) {
        return new_node(value);
    }

    if(  value < node->data ) {
        node->left = insert(node->left,value);
    } else if (value > node->data  ) {
        node->right =insert(node->right,value);
    }

    return node;

}



int main()
{
    tnode_t *root= new_node(50);
    insert(root,40);
    insert(root,20);
    insert(root,30);
    insert(root,60);
    insert(root,90);
    insert(root,10);
    insert(root,70);

    printf(" \n Pre-order \n");
    inorder(root);

    printf(" \n InOrder \n");
    inorder(root);

    printf(" \n Post-order \n");
    postorder(root);

    return 0;
}

