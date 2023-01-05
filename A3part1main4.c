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
 
/*
 create bst,
 takes in string of characters
 sizes the string w while
 create a new node root
 iterates through the string with a for loop -> into tree insert
 
 in tree insert,
 if the spot isn't NULL, then we go right/left depending on whether < or >
 then we new_node at the NULL spot.
 also, duplicates are placed on the left node.
 
 returns the whole thing when done.
 then you can print sorted off that.
 */

void tree_insert(Tree_Node** root, char data){
    
    Tree_Node *rootptr = *root;
    if (rootptr == NULL){
        //the tree is empty
        (*root) = new_node(data);
        return;
    }
    if(data == rootptr->data){
        //do nothing bc its already there
        //return;
        
        
        //we aren't removing duplicates, so; *****************
        tree_insert(&(rootptr->left),data);
        return;
        
        
    }
    
    if(data < rootptr->data){
        tree_insert(&(rootptr->left),data);
    }else{
        tree_insert(&(rootptr->right),data);
    }
    
}

Tree_Node *new_node(char data){
    
    Tree_Node* result = malloc(sizeof(Tree_Node));
    
        result->left = NULL;
        result->right = NULL;
        result->data = data;
    //printf("%c->",result->data);
    
    return result;
    
    
}

Tree_Node* create_bst (char data[]){
 
    Tree_Node *root = NULL;
    //2. declaring tree root
    
    //3. counting how many characters there are in the string
    int i =0;
    while(data[i]!='\0'){
        //printf("%c*", data[i]);
        i++;
    }
    //printf("\n%d\n\n", i);
    
    
    //4. inserting each character in the string into the bst
    for(int a=0; a<i; a++){
        //printf("%c->", data[a]);
        tree_insert(&root, data[a]);
    }

    //printf("\n\nSorted Data:\n");
    //tree_print_sorted(root);
    //printf("\n\n");
    return root;
    
}

Tree_Node* tree_search(Tree_Node* root, char data){
    
    if (root == NULL)
    {
        //printf("%d", root->data);
        //printf("%c is not in the dataset\n", data);
        return NULL;
    }
    
    if(root->data == data){
        //printf("%c found\n", root->data);
        return root;
    }
        
        // if what we're looking for is greater than root's key
    if (data < root->data){
        return tree_search(root->left, data);//recursion
        
    }else{
        // if what we're looking for is lesser than root's key
        
        return tree_search(root->right, data);//recursion
        
    }
    
    return NULL;
}

void tree_print_sorted(Tree_Node* root){
    
    
    if (root == NULL){
        //printf("EMPTY");
        return;
    }
    
    
    //INORDER TRAVERSAL HERE, as opposed to preorder/postorder
    tree_print_sorted(root->left);
     
    printf("%c", root->data);
     
        // recurring on right child here, after the left part of the tree is printed
    tree_print_sorted(root->right);
        return;
    
    
}


void tree_delete(Tree_Node* root){
    //USE FREE FUNCTION TO DELETE THE WHOLE THING
    if (root == NULL) {
           return;
       }
       else {

           tree_delete(root->left);
           tree_delete(root->right);
           free(root);
       }

    
    
    
    
    }
    


int main(){
    
  //1. create bst for "FLOCCINAUCINIHILIPILIFICATION”; can be loaded and printed in sorted order
    Tree_Node *x = create_bst("FLOCCINAUCINIHILIPILIFICATION");
    tree_print_sorted(create_bst("FLOCCINAUCINIHILIPILIFICATION"));
    printf("\n");
    tree_search(x, 'Z');
    
    
    
    tree_delete(x);
    
    
    

    //tree_print_sorted(x);
    
    /*Tree_Node *n1 = create_bst(4);
     Tree_Node *n2 = create_bst(3);
     Tree_Node *n3 = create_bst(5);
     
     n1->left = n2;
     n1->right = n3;
     
     
     tree_print_sorted(n1);
     tree_search(n1,4);
     
     Tree_Node *rootb = NULL;
     tree_insert(&rootb, 15);
     tree_insert(&rootb, 11);
     tree_insert(&rootb, 12);
     tree_insert(&rootb, 13);
     tree_insert(&rootb, 18);
     tree_insert(&rootb, 20);
     
     tree_print_sorted(rootb);
     
     tree_search(rootb, 15);
     tree_search(rootb, 21);*/
    
}

