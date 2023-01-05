//  main.c
//  tryingagain.c
//
//  Created by Maria Isabella on 22/09/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//need to ignore first row of fields, then we can print the rest of the file...

//just count the rows and ignore num 1, put the other loops inside this loop :D

//OR add a boolean flag in your code that indicates if it is the first line and don't write if it's true*****

int main(int argc, char *argv[]){
//int main(){
    // Create a file pointer and attach the Pokémon dataset
    FILE* pokemon_dataset;
    //pokemon_dataset = fopen("/Users/mariaisabella/Desktop/School/3rd year/SEM1/DATA STRUCTURES AND ALGORITHMS/Coding/Assignment0/FILES WORKING/tryingagain2/pokemon.csv", "r");
    pokemon_dataset = fopen(argv[1], "r");
    
    // Error handling for if the dataset is missing
    if (pokemon_dataset == NULL) {
        perror("Failed to open pokemon.csv");
        return(0);
    }

    // Character buffer to hold each field
    char pokemon[256];
    
    //boolean which flips when a quote is detected :D
    bool quotes = 0;
    
    int rownumber = 0;
    //INCREMENT THIS EVERY TIME IT READS A ROW AND HAV it not print after row 1
    

    
    
    //LOOP until we reach \n for the first time, then break and into other loops!!

    // Loop over the entire file
    while (true) {

        // Check if we're at the end of the file to break out of infinite loop
        if (feof(pokemon_dataset)) {
            break;
        }
        
        // passes into pokemon buffer
        fgets(pokemon, 256, pokemon_dataset);
        
        

        for (int pos = 0; pos < 256; pos++) {
            
            
            while(row1 == 1){

                if (pokemon[pos] == '\n'){
                    row1 = 0;
                }
                break;
            }
            
            
            while(row1 == 0){
                
            
            if (pokemon[pos] == '\"'){
                quotes = !quotes;
            }
            else if ((pokemon[pos] == ',') && (quotes != 1)) {
                printf("\n");
            }else if ((pokemon[pos] == ',') && (quotes == 1)) {
                printf(",");
            }else if (pokemon[pos] == '\0') {
                break;
            } else {
                printf("%c", pokemon[pos]);
            }
            
            //if loop to ignore quotes
            pokemon[pos] = '\0';
        }
        }
        
        printf("\n");
    }

    fclose(pokemon_dataset);
    return(0);
}
