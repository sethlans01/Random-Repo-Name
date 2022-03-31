#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

int main() {
    //Welcome 
    cout << "Welcome to Random Repo Name generator:" << endl;
    cout << "This program will generate a random two-word name for your repository on GitHub!" << endl << endl;

    //Open pointer to word list file
    FILE* wordlist;
    wordlist = fopen("Wordlist.txt", "r");
    if (wordlist == NULL) {  //If the file cannot be opened, print the error and shut down the program
        cout << "Error in loading file \"Wordlist.txt\"..." << endl;
        cout << "Please report any unknown issue on GitHub" << endl;
        do {
            cout << "Press a key to close the program..." << endl;
        } while (cin.get() != '\n');
        return 0;
    }

    //If the file can be opened start the generating procedure

    //Generate two random numbers for the words to be picked
    srand(time(NULL));
    int word_1_number = rand() % 25487 + 1;
    int word_2_number = rand() % 25487 + 1;

    //Pick the first word
    char word_1[20];
    for (int i = 0; i < word_1_number; i++) {
        fgets(word_1, 20, wordlist);
    }

    //Reset the file pointer to the top
    fseek(wordlist, 0, SEEK_SET);

    //Pick the second word
    char word_2[20];
    for (int j = 0; j < word_2_number; j++) {
        fgets(word_2, 20, wordlist);
    }

    //Remove endlines from words
    for (int i = 0; i < strlen(word_1); i++) {
        if(word_1[i] == '\n') {
            word_1[i] = '\0';
        }
    }

    //Concatenate the two words
    char repo_name[50];
    strcpy(repo_name, word_1);
    strcat(repo_name, " ");
    strcat(repo_name, word_2);

    //Make words lowercase
    for (int i = 0; i < strlen(repo_name); i++) {
        repo_name[i] = tolower(repo_name[i]);
    }

    //Print the result
    cout << "Here's your random name: " << repo_name << endl;
    do {
        cout << "Press a key to close the program..." << endl;
    } while (cin.get() != '\n');
    return 0;
}
