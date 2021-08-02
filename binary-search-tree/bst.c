#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#define max(a, b) ( (a > b) ? a : b )


queue* queate(void){ return calloc(1, sizeof(queue)); }


int enqueue(queue* Q, int key){
    lnode* n = calloc(1, sizeof(lnode));
    if (!n || !Q)
        return 0;
    n->key = key;

    if (Q->tail == NULL)
        Q->head = n;
    else {
        lnode* last = Q->tail;
        last->next = n;
    }

    Q->tail = n;
    Q->size++;
    return 1;
}


lnode* dequeue(queue* Q){
    if (!Q) return NULL;

    lnode* d = Q->head;

    if (Q->size > 0) {
        Q->head = d->next;
        Q->size--;
    }

    return d;
}


void printq(queue* Q){
    if (Q) {
        lnode* p = Q->head;
        if (p) {
            while (p->next != NULL) {
                printf("%d ", p->key);
                p = p->next;
            } printf("%d\n", p->key);
        } else
            printf("The queue is empty.\n");
    }
    else
        printf("There is no queue.\n");
}


void free_queue(queue* Q){
    if (Q) {
        lnode* p = Q->head;
        lnode* aux = NULL;

        while (p) {
            aux = p->next;
            free(p);
            p = aux;
        }
    }
    free(Q);
}


tree* bst_create(void){ return calloc(1, sizeof(tree)); }


node* bst_search(node* p, int k){
    if (p == NULL || p->key == k)
        return p;

    if (k > p->key)
        return bst_search(p->right, k);
    else
        return bst_search(p->left, k);
}


int bst_insert(tree* T, int data){
    if (T == NULL) {
        printf("invalid tree\n");
        return 0;
    }

    node* knot = calloc(1, sizeof(node));

    if (!knot) {  // that is: memory allocation failed
        printf("insufficient memory\n");
        return 0;
    }

    knot->key = data;
    node* p = T->root;
    if (p == NULL)
        T->root = knot;
    else {
        node *pp = NULL;
        while (p != NULL) {
            pp = p;
            if (p->key > data)
                p = p->left;
            else if (p->key < data)
                p = p->right;
            else {
                printf("the key (%d) is already in the tree\n", data);
                return 0;
            }
        }
        if (pp->key > data)
            pp->left = knot;
        else if (pp->key < data)
            pp->right = knot;
        else {
            printf("this key (%d) is already in the tree\n", data);
            return 0;
        }
        knot->father = pp;
    }
    return 1;
}


void bst_subtree_free(node* p){
    if (p) {
        bst_subtree_free(p->left);
        bst_subtree_free(p->right);
    } free(p);
}


void bst_free(tree* T){
    if (T)
        bst_subtree_free(T->root);
    free(T);
}


node* bst_minimum(node* p){
    if (!p)
        return NULL;
    while(p->left)
        p = p->left;
    return p;
}


node* bst_maximum(node* p){
    if (!p)
        return NULL;
    while(p->right)
        p = p->right;
    return p;
}


node* bst_successor(node* p){
    if (p == NULL)
        return NULL;

    /* if the p's right-son is not NULL,
     * then the successor of p will be the node with the
     * smallest key in the subtree rooted in p->right
     * (in which all nodes will have keys greater than p's)
     */
    if (p->right)
        return bst_minimum(p->right);

    /*
     * however, if p->right is NULL,
     * it's necessary to move backwards in the tree
     * (using a pointer to fathers 'n' and changing p)
     * until p == T->root (that is: n == NULL, no successor)
     * or until p becomes a left-son (that is: p != n->right),
     * because this means that its father's key (n->key) is greater than
     * any other key in the "family" of the initial-p,
     * therefore, this n is the successor of the initial-p
     */
    node *n = p->father;
    while (n && p == n->right) {
        p = n;
        n = n->father;
    }
    return n;
}


node* bst_predecessor(node* p){
    if (p == NULL)
        return NULL;

    /* if the p's left-son is not NULL,
     * then the predecessor of p will be the node with the
     * largest key in the subtree rooted in p->left
     * (in which all nodes will have keys less than p's)
     */
    if (p->left)
        return bst_maximum(p->left);

    /*
     * however, if p->left is NULL,
     * it's necessary to move backwards in the tree
     * (using a pointer to fathers 'n' and changing p)
     * until p == T->root (that is: n == NULL, no predecessor)
     * or until p becomes a right-son (that is: p != n->left),
     * because this means that its father's key (n->key) is less than
     * any other key in the "family" of the initial-p,
     * therefore, this n is the predecessor of the initial-p
     */
    node* n = p->father;
    while (n && p == n->left) {
        p = n;
        n = n->father;
    }
    return n;
}


void bst_replace(tree* T, node* old, node* new){
    if (T && old) {
        
        // if the old node is the root of T, then the new root will be the new node
        if (old->father == NULL)
            T->root = new;

        // if the old node is a g-side son, then the new node will be a g-side son of the old node father (whether 'g' is left or right)
        else if (old == old->father->left)
            old->father->left = new;
        else
            old->father->right = new;


        if (new != NULL)
            new->father = old->father;
    }
}


void bst_delete(tree* T, node* p){
    if (p != NULL) {
        if (!p->left)
            bst_replace(T, p, p->right);
        else if (!p->right)
            bst_replace(T, p, p->left);

        else {  // node p has two "kids"
            node *q = bst_successor(p);
            if (q->father != p) {
                bst_replace(T, q, q->right);
                q->right = p->right;
                q->right->father = q;
            }
            bst_replace(T, p, q);
            q->left = p->left;
            q->left->father = q;
        }
    } free(p);
}


int bst_remove(tree* T, int key){
    if (T == NULL) return 0;

    node* p = bst_search(T->root, key);
    
    if (p == NULL)  // if the key to be removed is not in the tree,
        return 0;  //  nothing should be done

    bst_delete(T, p);
    return 1;
}


void bst_pre_order(node* n){
    if (n != NULL) {
        printf("%d ", n->key);
        bst_pre_order(n->left);
        bst_pre_order(n->right);
    }
}


void bst_in_order(node* n){
    if (n != NULL) {
        bst_in_order(n->left);
        printf("%d ", n->key);
        bst_in_order(n->right);
    }
}


void bst_post_order(node* n){
    if (n != NULL) {
        bst_post_order(n->left);
        bst_post_order(n->right);
        printf("%d ", n->key);
    }
}


int bst_nnodes(node* p){
    if (p == NULL)
        return 0;
    return 1 + bst_nnodes(p->left) + bst_nnodes(p->right);
}


int bst_nleaves(node* p){
    if (p == NULL)
        return 0;
    else if (!p->left && !p->right)
        return 1;
    else
        return bst_nleaves(p->left) + bst_nleaves(p->right);
}


int bst_height(node* n, tree* T){
    if (!T) return -10;

    if (n == NULL)
        return n == T->root ? 0 : -1;

    return max(bst_height(n->right, T), bst_height(n->left, T)) + 1;
}


queue* bst_height_path(node* n){
    queue* Q = queate();

    if (n == NULL)
        return Q;

    enqueue(Q, n->key);

    queue* Ql = queate();
    queue* Qr = queate();

    if (!n->right && !n->left) {
        free_queue(Ql);
        free_queue(Qr);
        return Q;
    }

    else if (n->right == NULL) {
        queue* left = bst_height_path(n->left);
        lnode* p = left->head;
        while (p) {
            enqueue(Ql, p->key);
            p = p->next;
        }
    }

    else if (n->left == NULL) {
        queue* right = bst_height_path(n->right);
        lnode* p = right->head;
        while (p) {
            enqueue(Qr, p->key);
            p = p->next;
        }
    }

    else {
        queue* left = bst_height_path(n->left);
        lnode* p = left->head;

        while (p) {
            enqueue(Ql, p->key);
            p = p->next;
        }

        queue* right = bst_height_path(n->right);
        p = right->head;
        while (p) {
            enqueue(Qr, p->key);
            p = p->next;
        }
    }

    queue* lst = (Ql->size > Qr->size) ? Ql : Qr;
    lnode* p = lst->head;
    while (p) {
        enqueue(Q, p->key);
        p = p->next;
    }

    free_queue(Ql);
    free_queue(Qr);
    return Q;
}


int bst_print_height(node* n){
    queue* Q = bst_height_path(n);

    if (Q->size == 0) {
        printf("empty tree\n");
        free_queue(Q);
        return 0;
    }

    printf("longest and most to the right path: ");
    printq(Q);
    printf("\n");

    free_queue(Q);
    return 1;
}


void bst_BF(node* n, tree* T){
    if (n != NULL) {
        bst_BF(n->left, T);
        n->BF = bst_height(n->left, T) - bst_height(n->right, T);
        bst_BF(n->right, T);
    }
}


int bst_is_avl(node* n){
    if (n != NULL) {
        int L = bst_is_avl(n->left);

        if (n->BF > 1 || n->BF < -1)
            return 0;

        int R = bst_is_avl(n->right);

        if (L == 0 || R == 0)
            return 0;
    }
    return 1;
}
