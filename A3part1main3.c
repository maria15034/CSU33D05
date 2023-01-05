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

//1. count the size of the array by a while loop IN CREATE BST
//2. then pass it to TREE INSERT function by for loop single single character wise
//3 and for easeness, create a separate function to create a new node.

void tree_insert(Tree_Node** root, char data){
    //TODO
    Tree_Node *rootptr = *root;
    if (rootptr == NULL){
        //the tree is empty
        (*root) = new_node(data);
        //i think instead of this^ we do new_node...
        return;
    }
    if(data == rootptr->data){
        //do nothing bc its already there - duplicate values?
        return;
        
    }
    
    if(data < rootptr->data){
        tree_insert(&(rootptr->left),data);
    }else{
        tree_insert(&(rootptr->right),data);
    }
    
}

Tree_Node* create_bst (char *data[]){
    // creating a node here
    
    //our root
    Tree_Node *rootb = NULL;
    
    //getting the size of our string of characters
    int i;
    while(&data[i]!='\0'){
        i++;
    }
    //then we have the size of the tree, so we want to create a for loop that inserts from
    //data [1] to data[i]
    
    for(int a = 1; a<=i; a++){
        
        tree_insert(&rootb, &data[a]);
        
    }
    
    //OUR NEW_NODE FUNCTION!!!
    return &rootb;
}

Tree_Node* new_node(char data){
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
    
    create_bst('a');
    //tree_print_sorted(create_bst('a'));
    
}
