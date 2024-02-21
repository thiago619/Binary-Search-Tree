#include "binarysearchtree.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <cstring>


int compare(void *data_1, void *data_2)
{
    int value_1;
    int value_2;

    memcpy(&value_1,data_1,sizeof(int));
    memcpy(&value_2,data_2,sizeof(int));

    if(value_1 == value_2) return 0;
    if(value_2 > value_1) return 1;
    if(value_2 < value_1) return -1;
    return 0;

}

int main()
{
    struct BinarySearchTree *bst = bst_constructor(compare);
    printf("Sequential insert:\n");
    for(int i = 0;i<=10;i++)
    {
        printf("\tInserting %d in the BST\n",i);
        BST_CODE result = bst_add(bst,&i, sizeof(int));
        if(result == BST_INSERTED){
            printf("\t\t%d inserted successfully\n",i);
        }else if(result == BST_ALREADY_INSERTED){
            printf("\t\t%d already inserted\n",i);
        }
    }

    printf("Inserting rep numbers:\n");
    for(int i = 0;i<=10;i++)
    {
        printf("\tInserting %d in the BST\n",i);
        BST_CODE result = bst_add(bst,&i, sizeof(int));
        if(result == BST_INSERTED){
            printf("\t\t%d inserted successfully\n",i);
        }else if(result == BST_ALREADY_INSERTED){
            printf("\t\t%d already inserted\n",i);
        }
    }

    printf("Removing itens outside of the BST:\n");
    for(int i = 20;i<=30;i++)
    {
        printf("\tRemoving %d in the BST\n",i);
        BST_CODE result = bst_delete(bst,&i);
        if(result == BST_DELETED){
            printf("\t\t%d removed successfully\n",i);
        }else if(result == BST_NOT_FOUND){
            printf("\t\t%d already deleted\n",i);
        }
    }

    printf("Removing all itens:\n");
    for(int i = 0;i<=10;i++)
    {
        printf("\tRemoving %d from BST\n",i);
        BST_CODE result = bst_delete(bst,&i);
        if(result == BST_DELETED){
            printf("\t\t%d deleted successfully\n",i);
        }else if(result == BST_NOT_FOUND){
            printf("\t\t%d already deleted\n",i);
        }
    }   return 0;
}