#include "binarysearchtree.h"
#include <malloc.h>
#include <memory.h>

struct bst_node{
    void *data;
    struct bst_node *parent;
    struct bst_node *left;
    struct bst_node *right;
};

typedef enum _BST_DIRECTION{
    BST_LEFT,
    BST_RIGHT,
    BST_HERE
}BST_DIRECTION;

struct bst_node* bst_get_min_node(struct bst_node* head);
struct bst_node* bst_inordersucessor(struct bst_node* head);
struct bst_node* bst_iterate(struct BinarySearchTree *bst, struct bst_node* cursor, void* data, BST_DIRECTION *direction);
void bst_destroy_recursive(struct bst_node *m_node);


struct bst_node* bst_iterate(struct BinarySearchTree *bst, struct bst_node *cursor, void* data, BST_DIRECTION *direction){
    if(bst->compare(cursor->data,data) == 1)
    {
        if(cursor->right)
        {
            return bst_iterate(bst,cursor->right,data,direction);
        }else
        {
            *direction = BST_RIGHT;
            return cursor;
        }
        
    }
    else if(bst->compare(cursor->data, data) == -1)
    {
        if(cursor->left){
            return bst_iterate(bst,cursor->left,data,direction);
        }else
        {
            *direction = BST_LEFT;
            return cursor;
        }
    }
    else
    {
        *direction = BST_HERE;
        return cursor;
    }
}

struct BinarySearchTree* bst_constructor(int (*compare)(void* data_1, void* data_2))
{
    struct BinarySearchTree* bst = (struct BinarySearchTree*)malloc(sizeof(struct BinarySearchTree));
    if(bst){
        bst->head = NULL;
        bst->compare = compare;
    }
    return bst;
}

BST_CODE bst_add(struct BinarySearchTree *bst, void *data, int size){
    BST_DIRECTION direction;
    if(!bst->head){
        struct bst_node* newhead = (struct bst_node*)malloc(sizeof(struct bst_node));
        if(!newhead) return BST_NOT_MEMORY;
        newhead->data = malloc(size);
        if(!newhead->data) return BST_NOT_MEMORY;
        memcpy(newhead->data,data,size);
        newhead->left = NULL;
        newhead->right = NULL;
        newhead->parent = NULL;
        bst->head = newhead;
        return BST_INSERTED;
    }
    else{
        struct bst_node *current = bst_iterate(bst,bst->head,data,&direction);
        if(direction == BST_HERE) return BST_ALREADY_INSERTED;
        if(direction == BST_LEFT){
            current->left = (struct bst_node*)malloc(sizeof(struct bst_node));
            if(!current->left) return BST_NOT_MEMORY;
            current->left->data = malloc(size);
            if(!current->left->data) return BST_NOT_MEMORY;
            memcpy(current->left->data,data,size);
            current->left->left = NULL;
            current->left->right = NULL;
            current->left->parent = current;
            return BST_INSERTED;
        }
        else if(direction == BST_RIGHT)
        {
            current->right = (struct bst_node*)malloc(sizeof(struct bst_node));
            if(!current->right) return BST_NOT_MEMORY;
            current->right->data = malloc(size);
            if(!current->right->data) return BST_NOT_MEMORY;
            memcpy(current->right->data,data,size);
            current->right->left = NULL;
            current->right->right = NULL;
            current->right->parent = current;
            return BST_INSERTED;
        }
        else if(direction == BST_HERE)
        {
            return BST_ALREADY_INSERTED;
        }
    }
    return BST_NOT_FOUND;
}

void* bst_search(struct BinarySearchTree *bst, void *data){
    BST_DIRECTION direction;
    if(!bst->head) return NULL;
    struct bst_node *current = bst_iterate(bst,bst->head,data,&direction);
    if(direction == BST_HERE){
        return current->data;
    }else{
        return NULL;
    }
}

BST_CODE bst_delete(struct BinarySearchTree *bst, void *data){
    BST_DIRECTION direction;
    if(!bst->head) return BST_NOT_FOUND;
    struct bst_node *current = bst_iterate(bst,bst->head,data,&direction);
    if(direction != BST_HERE) return BST_NOT_FOUND;

    if((current->left == NULL) && (current->right == NULL))
    {
        if(current->parent){
            if(current->parent->left == current) current->parent->left = NULL;
            if(current->parent->right == current) current->parent->right = NULL;
        }else{
            bst->head = NULL;
        }
        free(current->data);
        free(current);
    }else if((current->left == NULL) != (current->right == NULL))
    {
        struct bst_node *temp;
        struct bst_node *parent;
        if(current->left == NULL){
            temp = current->right;
        }else{
            temp = current->left;
        }
        parent = current->parent;
        free(current->data);
        memcpy(current,temp,sizeof(struct bst_node));
        current->parent = parent;
        if(current->left != NULL) current->left->parent = current;
        if(current->right != NULL) current->right->parent = current;
        free(temp);
    }else
    {
        struct bst_node *inorder;

        inorder = bst_inordersucessor(current);

        memcpy(current->data,inorder->data,sizeof(int));
        free(inorder->data);
        if(inorder->right != NULL){
            inorder->right->parent = inorder->parent;
            inorder->parent->left = inorder->right;
        }else{
            inorder->parent->left = NULL;
        }
        free(inorder);
    }
    return BST_DELETED;
}

struct bst_node* bst_get_min_node(struct bst_node *head){
    struct bst_node *current = head;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

struct bst_node* bst_inordersucessor(struct bst_node *head){
    struct bst_node *cursor = head->right;
    if(cursor == NULL) return NULL;
    while (cursor->left != NULL)
    {
        cursor = cursor->left;
    }
    return cursor;
}

void bst_destroy_recursive(struct bst_node *m_node){
    if(m_node == NULL) return;
    bst_destroy_recursive(m_node->left);
    bst_destroy_recursive(m_node->right);
    free(m_node->data);
    free(m_node);
}

void bst_destroy(struct BinarySearchTree *bst){
    bst_destroy_recursive(bst->head);
    bst->head = NULL;
    free(bst);
}
