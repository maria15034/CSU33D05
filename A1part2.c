#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 30
#define ARRAY_SIZE 501 //
//PART 2 CODE;

typedef struct element element;
int collisions = 0; //how many duplicate names or names which are anagrams of eachother (based on my current hash function
//which takes the total ASCII count of the characters in a string, so ie 'Adrian' and 'Draina' would return the same hash
//and thus be sent to be stored in the same location, causing a collision
int termcount = 0; //# names

struct element{
    char name[MAX_STRING_SIZE];
    int frequency;
};

element *hashTable[ARRAY_SIZE]; //our hashtable is an array of structs

int hash_function(char*s){
//my hash function which gives the location in the table where to store the name
    int hash = 0;
    int i =0;
    
    size_t len = strlen(s);
    
    while(*s){
        for(;i<len;i++){
            hash = hash + s[i]*(2^i); //multiplying by character value in list and const
            // raised to power of index of character
            //this way anagrams won't go to same index in array
        }
        s++;
    }
    return ((hash % ARRAY_SIZE));
}

element* createNewElement(char* name){
  //creates a new name in the table
    struct element *new = (struct element*)malloc(sizeof(struct element));
    strcpy(new->name, name);
    new->frequency = 1;
    termcount++;
    return new;
}

void insert (char *name){
    //takes the name and decides whether to increment its frequency if it already exists in the table,
  //or to create a new element and insert it into the table
    int i = hash_function(name);
    int match_found = 0;
    
    if(hashTable[i] !=NULL){
    while((hashTable[i] != NULL)){
        collisions++;
          if((strcmp(hashTable[i]->name, name)) == 0){ //if they the same
        hashTable[i]->frequency = ((hashTable[i]->frequency) +1);
              match_found = 1; //match found, increment
              
              break;
        
    }else{
        i++;
        //++i; //go to next cell
        i %= ARRAY_SIZE;
        
    }}}
    //if no match for our name ends up being found, we create a new element for it at i.
    else if(match_found ==0){
        hashTable[i] = createNewElement(name); //no match
        
    }
}

element* search (char* name){
  //searches for name in table
    int i = hash_function(name);
    int s = 0;
    int found_name = 0;
    
    //what we wanna do is loop till we reach null
    //while(hashTable[i] != NULL){
    for(;s<ARRAY_SIZE;s++){
        if((hashTable[i]!=NULL)&&strcmp(hashTable[i]->name, name) == 0) { //if the names are the same
            found_name = 1;
            //printf("FOUND NAME\n");
            printf("%s - %i\n", hashTable[i]->name, hashTable[i]->frequency);
            //printf("McCormuck Dun: %i\n", hashTable[i]->frequency); //for testing :D
            return hashTable[i];
            break;
        }
        else{
            found_name =0;
        }
        ++i; //go to next cell
        i %= ARRAY_SIZE;

//}
    }
    printf("%s not in table\n", name);
    return NULL;
}

void next_token ( char *buf, FILE *f, int string_max ) {
  //part 2 of csv reader, parses
    // start by skipping any characters we're not interested in
    buf[0] = fgetc(f);
    while ( !isalnum(buf[0]) && !feof(f) ) { buf[0] = fgetc(f); }
    // read string of alphanumeric characters
    int i=1;
    for (;;) {
        buf[i] = fgetc(f);                // get next character from file
        if( !isalnum(buf[i]) && buf[i] != ' ') { break; } // only load letters and numbers
        if( feof(f) ) { break; }          // file ended
        if( i < (string_max-1) ) { ++i; } // truncate strings that are too long
    }
    buf[i] = '\0'; // NULL terminate the string
}

//  Reads the contents of a file and adds them to the hash table - returns 1 if file was successfully read and 0 if not.
int load_file ( char *fname ) {
  //part 1 of csv reader to load file
    FILE *f;
    char buf[MAX_STRING_SIZE];

    f = fopen(fname, "r");
    if (!f) {
        printf("Unable to open %s\n", fname);
        return 0;
    }
    
    while ( !feof(f) ) {
        next_token(buf, f, MAX_STRING_SIZE); //loads full word into buffer
        insert(buf);
    }
    fclose(f);
    return 1;
}

//int main(int argc, char *argv[]) //this is to take in an argument file...
int main()
{
    char *file = ("/Users/mariaisabella/Desktop/School/3rd year/SEM1/DATA STRUCTURES AND ALGORITHMS/Coding/Assignment1/names.csv");
    //char *file = ("names.csv");
    load_file(file); //loading file
    //load_file(argv[1]);
    
    double load;
    load = ((1.0*termcount)/ARRAY_SIZE); //'load' here is a term telling you how full the table is,
    //higher load = higher collisions likely
    //it's the percentage of the number of terms in your array divided by the area size

    printf("File %s loaded\n", file);
    printf("Capacity: %i\n", ARRAY_SIZE);
    printf("Num Terms: %i\n", termcount);
    printf("Collisions: %i\n", collisions);
    printf("Load: %f\n", load);
    printf("Enter term to get frequency or type \"quit\" to escape\n");
    
    char userinput[50]; //this part takes the user input
    while(1){
    scanf("%s", userinput);
    if(strcmp(userinput, "quit") ==0){
        break;
    }
    else{
        search(userinput);}
    }
    
    return 0;
}

