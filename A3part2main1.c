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
    printf("\n");
    tree_print_sorted(create_bst("FLOCCINAUCINIHILIPILIFICATION"));
    printf("\n");
    tree_search(x, 'Z');
    
    tree_delete(x);
    
    //tree_print_sorted(x);
    
}


///****************************
///
#include "bstdb.h"

// Write your submission in this file
//
// A main function and some profiling tools have already been set up to test
// your code in the task2.c file. All you need to do is fill out this file
// with an appropriate Binary Search Tree implementation.
//
// The input data will be books. A book is comprised of a title and a word
// count. You should store both these values in the tree along with a unique
// integer ID which you will generate.
//
// We are aiming for speed here. A BST based database should be orders of
// magnitude faster than a linked list implementation if the BST is written
// correctly; AVL!!!
//
// We have provided an example implementation of what a linked list based
// solution to this problem might look like in the db/listdb.c file. If you
// are struggling to understand the problem or what one of the functions
// below ought to do, consider looking at that file to see if it helps your
// understanding.
//
// There are 6 functions you need to look at. Each is provided with a comment
// which explains how it should behave. The functions are:
//
//  + bstdb_init
//  + bstdb_add
//  + bstdb_get_word_count
//  + bstdb_get_name
//  + bstdb_stat
//  + bstdb_quit
//
// Do not rename these functions or change their arguments/return types.
// Otherwise the profiler will not be able to find them. If you think you
// need more functionality than what is provided by these 6 functions, you
// may write additional functions in this file.


int
bstdb_init ( void ) {
    // This function will run once (and only once) when the database first
    // starts. Use it to allocate any memory you want to use or initialize
    // some globals if you need to. Function should return 1 if initialization
    // was successful and 0 if something went wrong.
    
    
    
    
    return 1;
}

int
bstdb_add ( char *name, int word_count ) {
    // This function should create a new node in the binary search tree,
    // populate it with the name and word_count of the arguments and store
    // the result in the tree.
    //
    // This function should also generate and return an identifier that is
    // unique to this document. A user can find the stored data by passing
    // this ID to one of the two search functions below.
    //
    // How you generate this ID is up to you, but it must be an integer. Note
    // that this ID should also form the keys of the nodes in your BST, so
    // try to generate them in a way that will result in a balanced tree.
    //
    // If something goes wrong and the data cannot be stored, this function
    // should return -1. Otherwise it should return the ID of the new node
    return -1;
}

int
bstdb_get_word_count ( int doc_id ) {
    // This is a search function. It should traverse the binary search tree
    // and return the word_count of the node with the corresponding doc_id.
    //
    // If the required node is not found, this function should return -1
    return -1;
}

char*
bstdb_get_name ( int doc_id ) {
    // This is a search function. It should traverse the binary search tree
    // and return the name of the node with the corresponding doc_id.
    //
    // If the required node is not found, this function should return NULL or 0
    return 0;
}

void
bstdb_stat ( void ) {
    // Use this function to show off! It will be called once after the
    // profiler ends. The profiler checks for execution time and simple errors,
    // but you should use this function to demonstrate your own innovation.
    //
    // Suggestions for things you might want to demonstrate are given below,
    // but in general what you choose to show here is up to you. This function
    // counts for marks so make sure it does something interesting or useful.
    //
    //  + Check if your tree is balanced and print the result
    //
    //  + Does the number of nodes in the tree match the number you expect
    //    based on the number of insertions you performed?
    //
    //  + How many nodes on average did you need to traverse in order to find
    //    a search result?
    //
    //  + Can you prove that there are no accidental duplicate document IDs
    //    in the tree?
}

void
bstdb_quit ( void ) {
    // This function will run once (and only once) when the program ends. Use
    // it to free any memory you allocated in the course of operating the
    // database.
    
    
}

