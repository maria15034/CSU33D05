//
//  main.c
//  testingstrtok
//
//  Created by Maria Isabella on 20/09/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *myFile; //file pointer
    myFile = fopen("/Users/mariaisabella/Desktop/School/3rd year/SEM1/DATA STRUCTURES AND ALGORITHMS/Coding/Assignment0/booboooo/booboooo/pokemon (1).csv", "r"); //opening file
    
    char buffer[1024];
    //fgets(stored, num chars, where they taken from?)
       while (fgets(buffer, 1024, myFile)) {
           // If you only need the first column of each row
           /*  char *token = strtok(buffer, ",");
           if (token) {
               //int n = atoi(token);
               printf("%s\n", token);
           }*/

           // If you need all the values in a row
           char *token = strtok(buffer, ",");
           while (token) {
               // Just printing each integer here but handle as needed
               //int n = atoi(token);
               printf("%s\n", token);
               
               token = strtok(NULL, ",");
           }
       }

}
//fgets? 3 inputs?
//why char points to token? strtok? while token?
//
