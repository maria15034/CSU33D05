//bst_skeleton.c
//
//  assignment3.1
//
//  Created by Maria Isabella on 13/11/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <string.h>


void tree_insert(Tree_Node** root, char data){
    //TODO
    Tree_Node *rootptr = *root;
    if (rootptr == NULL){
        //the tree is empty
        (*root) = create_bst(data);
        return;
    }
    if(data == rootptr->data){
        //do nothing bc its already there
        return;
        
    }
    
    if(data < rootptr->data){
        tree_insert(&(rootptr->left),data);
    }else{
        tree_insert(&(rootptr->right),data);
    }
    
}

Tree_Node* create_bst (char data[]){
    // creating a node here
    Tree_Node* result = malloc(sizeof(Tree_Node)); //result that will be returned, allocated on heap
    if (result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->data = data;
        //strcpy(result->data, data);
    }
    return result;
    
}

Tree_Node* tree_search(Tree_Node* root, char data){
    
    if (root == NULL)
    {
        //printf("%d", root->data);
        printf("did not find data\n");
        return NULL;
    }
    
    if(root->data == data){
        printf("found data\n");
        return root->data;
    }
        
        // if what we're looking for is greater than root's key
    if (data < root->data){
        return tree_search(root->left, data);//recursion
        
    }else{
        // if what we're looking for is lesser than root's key
        
        return tree_search(root->right, data);//recursion
        
    }
     
    
    //return NULL;
}

void tree_print_sorted(Tree_Node* root){
    //TODO
    if (root == NULL){
        //printf("EMPTY");
        return;
    }
    
    //INORDER TRAVERSAL HERE, as opposed to preorder/postorder
    tree_print_sorted(root->left);
     
    printf("%d\n", root->data);
     
        // recurring on right child here
    tree_print_sorted(root->right);
}

void tree_delete(Tree_Node* root){
    //TODO
}

int main(){
    
    /*Tree_Node *n1 = create_bst(4);
    Tree_Node *n2 = create_bst(3);
    Tree_Node *n3 = create_bst(5);
    
    n1->left = n2;
    n1->right = n3;
    
    
    tree_print_sorted(n1);
    tree_search(n1,4);*/
    
    Tree_Node *rootb = NULL;
    tree_insert(&rootb, 15);
    tree_insert(&rootb, 11);
    tree_insert(&rootb, 12);
    tree_insert(&rootb, 13);
    tree_insert(&rootb, 18);
    tree_insert(&rootb, 20);
    
    tree_print_sorted(rootb);
    
    tree_search(rootb, 15);
    tree_search(rootb, 21);
    
}
