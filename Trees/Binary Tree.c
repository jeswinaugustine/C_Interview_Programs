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

int find_max(tnode_t* root) {
    int val=0;
    int left_max=0;
    int right_max=0;
    int max=0;

    if(root == NULL){
        return 0;
    }
    val = root->data;
    left_max=find_max(root->left);
    right_max=find_max(root->right);

    //find the max
    if(right_max>left_max) {
        max=right_max;
    } else {
        max=left_max;
    }
    if(val>max)
        return val;
    else
        return max;

}

int find_node(tnode_t *root,int data) {
    if(!root) {
        return 0;
    }
    if(data==root->data){
        return 1;
    }
    if(data < root->data){
        return find_node(root->left,data);
    }
    if(data > root->data){
        return find_node(root->right,data);
    }

}

int find_size(tnode_t *root){
    if(!root) {
        return 0;
    } else {
        return find_size(root->left) + 1 + find_size(root->right);
    }
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
    insert(root,110);

    printf(" \n Pre-order \n");
    inorder(root);

    printf(" \n InOrder \n");
    inorder(root);

    printf(" \n Post-order \n");
    postorder(root);

    printf("\n Find Max - %d \n",find_max(root));

    if(find_node(root,90)) {
        printf("\n 90 is present \n");
    } else {
        printf("\n 90 is not present \n");
    }

    if(find_node(root,100)) {
        printf("\n 100 is present \n");
    } else {
        printf("\n 100 is not present \n");
    }

    printf("\n Size of a tree - %d \n",find_size(root));

    return 0;
}

