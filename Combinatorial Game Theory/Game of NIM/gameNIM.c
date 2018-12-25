/* A C program to implement Game of Nim. The program 
   assumes that both players are playing optimally */
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
  
#define COMPUTER 1 
#define HUMAN 2 
  
/* A Structure to hold the two parameters of a move 
  
 A move has two parameters- 
  1) pile_index = The index of pile from which stone is 
                    going to be removed 
  2) stones_removed = Number of stones removed from the 
                        pile indexed = pile_index  */
struct move 
{ 
    int pile_index; 
    int stones_removed; 
}; 
  
/* 
 piles[] -> Array having the initial count of stones/coins 
            in each piles before the game has started. 
 n       -> Number of piles 
  
 The piles[] are having 0-based indexing*/
  
// A C function to output the current game state. 
void showPiles (int piles[], int n) 
{ 
    int i; 
    printf ("Current Game Status -> "); 
    for (i=0; i<n; i++) 
        printf ("%d ", piles[i]); 
    printf("\n"); 
    return; 
} 
  
// A C function that returns True if game has ended and 
// False if game is not yet over 
bool gameOver(int piles[], int n) 
{ 
    int i; 
    for (i=0; i<n; i++) 
        if (piles[i]!=0) 
            return (false); 
  
    return (true); 
} 
  
// A C function to declare the winner of the game 
void declareWinner(int whoseTurn) 
{ 
    if (whoseTurn == COMPUTER) 
        printf ("\nHUMAN won\n\n"); 
    else
        printf("\nCOMPUTER won\n\n"); 
    return; 
} 
  
// A C function to calculate the Nim-Sum at any point 
// of the game. 
int calculateNimSum(int piles[], int n) 
{ 
    int i, nimsum = piles[0]; 
    for (i=1; i<n; i++) 
        nimsum = nimsum ^ piles[i]; 
    return(nimsum); 
} 
  
// A C function to make moves of the Nim Game 
void makeMove(int piles[], int n, struct move * moves) 
{ 
    int i, nim_sum = calculateNimSum(piles, n); 
  
    // The player having the current turn is on a winning 
    // position. So he/she/it play optimally and tries to make 
    // Nim-Sum as 0 
    if (nim_sum != 0) 
    { 
        for (i=0; i<n; i++) 
        { 
            // If this is not an illegal move 
            // then make this move. 
            if ((piles[i] ^ nim_sum) < piles[i]) 
            { 
                (*moves).pile_index = i; 
                (*moves).stones_removed = 
                                 piles[i]-(piles[i]^nim_sum); 
                piles[i] = (piles[i] ^ nim_sum); 
                break; 
            } 
        } 
    } 
  
    // The player having the current turn is on losing 
    // position, so he/she/it can only wait for the opponent 
    // to make a mistake(which doesn't happen in this program 
    // as both players are playing optimally). He randomly 
    // choose a non-empty pile and randomly removes few stones 
    // from it. If the opponent doesn't make a mistake,then it 
    // doesn't matter which pile this player chooses, as he is 
    // destined to lose this game. 
  
    // If you want to input yourself then remove the rand() 
    // functions and modify the code to take inputs. 
    // But remember, you still won't be able to change your 
    // fate/prediction. 
    else
    { 
        // Create an array to hold indices of non-empty piles 
        int non_zero_indices[n], count; 
  
        for (i=0, count=0; i<n; i++) 
            if (piles[i] > 0) 
                non_zero_indices [count++] = i; 
  
        (*moves).pile_index = (rand() % (count)); 
        (*moves).stones_removed = 
                 1 + (rand() % (piles[(*moves).pile_index])); 
        piles[(*moves).pile_index] = 
         piles[(*moves).pile_index] - (*moves).stones_removed; 
  
        if (piles[(*moves).pile_index] < 0) 
            piles[(*moves).pile_index]=0; 
    } 
    return; 
} 
  
// A C function to play the Game of Nim 
void playGame(int piles[], int n, int whoseTurn) 
{ 
    printf("\nGAME STARTS\n\n"); 
    struct move moves; 
  
    while (gameOver (piles, n) == false) 
    { 
        showPiles(piles, n); 
  
        makeMove(piles, n, &moves); 
  
        if (whoseTurn == COMPUTER) 
        { 
            printf("COMPUTER removes %d stones from pile "
                   "at index %d\n", moves.stones_removed, 
                   moves.pile_index); 
            whoseTurn = HUMAN; 
        } 
        else
        { 
            printf("HUMAN removes %d stones from pile at "
                   "index %d\n", moves.stones_removed, 
                   moves.pile_index); 
            whoseTurn = COMPUTER; 
        } 
    } 
  
    showPiles(piles, n); 
    declareWinner(whoseTurn); 
    return; 
} 
  
void knowWinnerBeforePlaying(int piles[], int n, 
                             int whoseTurn) 
{ 
    printf("Prediction before playing the game -> "); 
  
    if (calculateNimSum(piles, n) !=0) 
    { 
        if (whoseTurn == COMPUTER) 
            printf("COMPUTER will win\n"); 
        else
            printf("HUMAN will win\n"); 
    } 
    else
    { 
        if (whoseTurn == COMPUTER) 
            printf("HUMAN will win\n"); 
        else
            printf("COMPUTER will win\n"); 
    } 
  
    return; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Test Case 1 
    int piles[] = {3, 4, 5}; 
    int n = sizeof(piles)/sizeof(piles[0]); 
  
    // We will predict the results before playing 
    // The COMPUTER starts first 
    knowWinnerBeforePlaying(piles, n, COMPUTER); 
  
    // Let us play the game with COMPUTER starting first 
    // and check whether our prediction was right or not 
    playGame(piles, n, COMPUTER); 
  
    /* 
    Test Case 2 
    int piles[] = {3, 4, 7}; 
    int n = sizeof(piles)/sizeof(piles[0]); 
  
    // We will predict the results before playing 
    // The HUMAN(You) starts first 
    knowWinnerBeforePlaying (piles, n, COMPUTER); 
  
    // Let us play the game with COMPUTER starting first 
    // and check whether our prediction was right or not 
    playGame (piles, n, HUMAN);    */
  
    return(0); 
}
