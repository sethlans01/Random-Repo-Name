#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable : 4996)
using namespace std;

int main() {
    //Welcome 
    cout << "Welcome to Random Repo Name generator:" << endl;
    cout << "This program will generate you a random two-words name for you repository on GitHub!" << endl << endl;

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

    //Print the result
    cout << "Here's your random name: " << endl << word_1 << word_2 << endl << endl;
    do {
        cout << "Press a key to close the program..." << endl;
    } while (cin.get() != '\n');
    return 0;
}
