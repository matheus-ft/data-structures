/*
    To test this implementation of a BST of <int>s you'll have to keep 
in mind the following commands:

create : creates an empty BST (if there is one already, the old is released and the new is allocated)
insert x : inserts the key x in the BST (x is int)
remove x : removes the key x from the BST
search x : tells you if the key x is in the BST or not
pre-order : prints all the nodes in the BST with Pre-Order
in-order : prints all the nodes in the BST with In-Order
post-order : prints all the nodes in the BST with Post-Order
successor x : finds the key of the successor node relative to the one with key x
predecessor x : finds the key of the predecessor node relative to the one with key x
avl? : checks if the tree is AVL or not
info : prints the number of nodes, the number of leaves, and the height fo the BST
longest-path : prints the longest path in the BST
end : finishes program

    Any other command is suppossed to be ignored. Therefore the input should be:

create
commands
end
^D

    'commands' being a sequence of some operations from the ones available.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


int main(void) {
    tree* T = NULL;
    char input[13];  // each position is a letter (last one is '\0')

    do {
        scanf("%s ", input);

        if (strcmp(input, "create") == 0) {
            if (T != NULL) {
                bst_subtree_free(T->root);
            }
            T = bst_create();
        }

        else if (strcmp(input, "insert") == 0) {
            int x;
            scanf("%d ", &x);
            bst_insert(T, x);
        }

        else if (strcmp(input, "remove") == 0) {
            int x;
            scanf("%d ", &x);
            bst_remove(T, x);
        }

        else if (strcmp(input, "search") == 0) {
            int x;
            scanf("%d ", &x);
            if (bst_search(T->root, x))
                printf("%d is in the tree\n", x);
            else
                printf("%d is not in the tree\n", x);
        }

        else if (strcmp(input, "pre-order") == 0) {
            if (!T || !T->root)
                printf("empty tree\n");
            else {
                printf("pre-order: ");
                bst_pre_order(T->root);
                printf("\n");
            }
        }

        else if (strcmp(input, "in-order") == 0) {
            if (!T || !T->root)
                printf("empty tree\n");
            else {
                printf("in-order: ");
                bst_in_order(T->root);
                printf("\n");
            }
        }

        else if (strcmp(input, "post-order") == 0) {
            if (!T || !T->root)
                printf("empty tree\n");
            else {
                printf("post-order: ");
                bst_post_order(T->root);
                printf("\n");
            }
        }

        else if (strcmp(input, "successor") == 0) {
            int x;
            scanf("%d ", &x);
            node* p = bst_search(T->root, x);
            node* z = bst_successor(p);
            if (p && z)  // that is: if x is in T AND has a successor
                printf("successor of %d: %d\n", x, z->key);
            else
                printf("%d has no successor\n", x);
        }

        else if (strcmp(input, "predecessor") == 0) {
            int x;
            scanf("%d ", &x);
            node* p = bst_search(T->root, x);
            node* z = bst_predecessor(p);
            if (p && z)  // that is: if x is in T AND has a predecessor
                printf("predecessor of %d: %d\n", x, z->key);
            else
                printf("%d has no predecessor\n", x);
        }

        else if (strcmp(input, "avl?") == 0) {
            bst_BF(T->root, T);
            if (bst_is_avl(T->root))
                printf("yes\n");
            else
                printf("no\n");
        }
        
        else if (strcmp(input, "info") == 0) 
            printf("nodes: %d, leaves: %d, height: %d\n", bst_nnodes(T->root), bst_nleaves(T->root), bst_height(T->root, T));
        
        else if (strcmp(input, "longest-path") == 0) 
            bst_print_height(T->root);

        else if (strcmp(input, "end") == 0) {
            bst_free(T);
            return 1;
        }

        else printf("Oops, '%s' is an invalid command, try again!\n", input);

    } while (1);

    return 0;
}
