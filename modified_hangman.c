

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For rand()
#include <time.h>   // For srand()

int main() {
    int i, n, randomIndex;
    int found;
    char guess;
    int triesLeft;
    char playAgain;
    
    char secretWord[50];
    char currentHint[100]; // Variable to store the specific question/hint
    char guessedWord[50];
    int length;

    // Initialize random number generator
    srand(time(0)); 

    do {
        triesLeft = 5;
        
        printf("\n--- NEW HANGMAN GAME ---\n");
        printf("Select difficulty: 1.Easy (Cities) 2.Medium (Food) 3.Hard (Places): ");
        scanf("%d", &n);

        // Random number between 0 and 2
        randomIndex = rand() % 3; 

        if (n == 1) {
            // EASY: Cities with specific hints
            char *words[] = {"AHMEDABAD", "BENGALURU", "MUMBAI"};
            char *hints[] = {"Manchester of the East", "Silicon Valley of India", "Home of Bollywood"};
            
            strcpy(secretWord, words[randomIndex]);
            strcpy(currentHint, hints[randomIndex]); // Copy specific hint
        } 
        else if (n == 2) {
            // MEDIUM: Sweets with specific hints
            char *words[] = {"MALPUVA", "JALEBI", "LADDU"};
            char *hints[] = {"Fried pancake sweet", "Spiral orange sweet", "Round sphere sweet (Ganesh's favorite)"};
            
            strcpy(secretWord, words[randomIndex]);
            strcpy(currentHint, hints[randomIndex]);
        } 
        else if (n == 3) {
            // HARD: Places with specific hints
            char *words[] = {"NATHDWARA", "KEDARNATH", "AMARNATH"};
            char *hints[] = {"Temple of Shrinathji", "Shiva temple in Himalayas", "Cave temple with Ice Lingam"};
            
            strcpy(secretWord, words[randomIndex]);
            strcpy(currentHint, hints[randomIndex]);
        } 
        else {
            printf("Invalid choice! Defaulting to Easy.\n");
            strcpy(secretWord, "BENGALURU");
            strcpy(currentHint, "Silicon Valley of India");
            n = 1;
        }

        length = strlen(secretWord);

        // Create the mask
        for(i=0; i<length; i++) {
            guessedWord[i] = '_';
        }
        guessedWord[length] = '\0';

        // GAME LOOP
        while (triesLeft > 0) {
            printf("\nWord: %s\n", guessedWord);
            printf("Tries left: %d\n", triesLeft);
            
            // PRINT THE SPECIFIC HINT HERE
            printf("Hint: %s (Enter CAPITAL Letter): ", currentHint);
            
            scanf(" %c", &guess); 

            found = 0;
            for (i = 0; i < length; i++) {
                if (secretWord[i] == guess) {
                    guessedWord[i] = guess;
                    found = 1;
                }
            }

            if (found == 0) {
                printf("Wrong!\n");
                triesLeft--;
            } else {
                printf("Good job!\n");
            }

            if (strcmp(secretWord, guessedWord) == 0) {
                printf("\nCONGRATULATIONS! You won! Word: %s\n", secretWord);
                break; 
            }
        }

        if (triesLeft == 0) {
            printf("\nMAN IS HANGED! The word was: %s\n", secretWord);
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nThank you for playing!\n");
    return 0;

}
