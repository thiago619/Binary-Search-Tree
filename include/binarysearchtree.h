#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

#ifdef __cplusplus
extern "C"{
#endif


struct BinarySearchTree{
    struct bst_node *head;
    int (*compare)(void *data_1,void *data_2);
};
    typedef enum _BST_CODE{
        BST_INSERTED,
        BST_ALREADY_INSERTED,
        BST_NOT_MEMORY,
        BST_NOT_FOUND,
        BST_DELETED
    }BST_CODE;

    /**
     * Create a Binary Tree
     * @param function A function that compares the data and return this values(0 if is values is equal, 1 if the data_2 is bigger and -1 if the data_2 is small)
     * @return A Binary Search Tree
     * @brief Create a Binary Tree and sets your comparison function. data_1 is the data inside of Binary Tree and data_2 is the exernal value.
     * 
    */
    struct BinarySearchTree* bst_constructor(int (*compare)(void *data_1,void *data_2));

    /**
     * Add a item in the tree
     * @param BinarySearchTree The tree
     * @param void the pointer containing the data
     * @param size the size of data
     * @return The code of the insertion status
    */
    BST_CODE bst_add(struct BinarySearchTree *bst, void *data, int size);

    /**
     * Search a item on the tree
     * @param BinarySearchTree The tree
     * @param void the pointer with the data you searching for
     * @returns a pointer to the data
    */
    void* bst_search(struct BinarySearchTree *bst, void *data);

    /**
     * Delete a item from the tree
     * @param BinarySearchTree The tree
     * @param void the pointer with the data you searching for delete
     * @return The status code of the deletion
    */
    BST_CODE bst_delete(struct BinarySearchTree *bst, void *data);

    /**
     * Destroy the tree and free the memory
     * @param BinarySearchTree the tree
    */
    void bst_destroy(struct BinarySearchTree *bst);


#ifdef __cplusplus
}
#endif

#endif //__BINARYSEARCHTREE_H__
