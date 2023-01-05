//
//  bst.h
//  assignment3.1
//
//  Created by Maria Isabella on 13/11/2022.
//

#ifndef BST_H_
#define BST_H_
typedef struct Tree_Node{
    
    struct Tree_Node *left;
    struct Tree_Node *right;
    char data[];
    
} Tree_Node;


void tree_insert ( Tree_Node** root, char data );
Tree_Node* create_bst (char data[]);
Tree_Node* tree_search ( Tree_Node* root, char data );
void tree_print_sorted ( Tree_Node* root );
void tree_delete ( Tree_Node* root );


#endif
