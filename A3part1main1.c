//bst_skeleton.c

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include <string.h>

//MUST USE STRCMP FOR ALL COMPARISONS WITH CHAR!!!!!
/*
 int length = strlen(data);
 // /sizeof(data[0]);
 for(int i = 1; i<=length; i++){
 
 }
 */

void tree_insert(Tree_Node** root, char data){
    
    Tree_Node *rootptr = *root;
    //over here parse string?
    
    if (rootptr == NULL){
        //the tree is empty
        (*root) = create_bst(data);
        return;
    }
    
    /*if(data == rootptr->data){ //strcmp here?*******
        
     THIS IS FOR DUPLICATES; not a proper BST so this is unneeded
        //do nothing bc its already there
        return;
        
    }*/
    
    if(data < rootptr->data){//strcmp here?*******
        tree_insert(&(rootptr->left),data);
    }else{
        tree_insert(&(rootptr->right),data);
    }
    
}

Tree_Node* create_bst (char data[]){
    // creating a node here
    
    int i = 0;
        //while(data[i] != '\0'){
    Tree_Node* result = malloc(sizeof(Tree_Node));
        while(strcmp(data[i], '\0') != 0){
            printf("%c", data[i]);
            
            
            //Tree_Node* result = malloc(sizeof(Tree_Node)); //result that will be returned, allocated on heap
            if (result != NULL){
                result->left = NULL;
                result->right = NULL;
                result->data[i] = data[i];
                
            i++;
        }
   
    //create separate function here
    
   /* Tree_Node* result = malloc(sizeof(Tree_Node)); //result that will be returned, allocated on heap
    if (result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->data = data[i];*/
        
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
}

void tree_print_sorted(Tree_Node* root){
    //TODO
    if (root == NULL){
        //printf("EMPTY");
        return;
    }
    
    //INORDER TRAVERSAL HERE, as opposed to preorder/postorder
    tree_print_sorted(root->left);
     
    printf("%c\n", root->data);
     
        // recurring on right child here
    tree_print_sorted(root->right);
}

void tree_delete(Tree_Node* root){
    //TODO
}

int main(){
        
    //do it FOR CHARS:
    //MUST PARSE STRING in function, THEN PUT the individual CHARACTERS INTO the TREE
    Tree_Node *root = NULL;
    tree_insert(&root, "a");
    tree_insert(&root, "e");
    
    tree_print_sorted(root);
    
    tree_search(root, 'a');
    tree_search(root, 'f');
    
}

