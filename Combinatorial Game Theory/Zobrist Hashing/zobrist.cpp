
// A program to illustrate Zobeist Hashing Algorithm 
#include <bits/stdc++.h> 
using namespace std; 
  
unsigned long long int ZobristTable[8][8][12]; 
mt19937 mt(01234567); 
  
// Generates a Randome number from 0 to 2^64-1 
unsigned long long int randomInt() 
{ 
    uniform_int_distribution<unsigned long long int> 
                                 dist(0, UINT64_MAX); 
    return dist(mt); 
} 
  
// This function associates each piece with 
// a number 
int indexOf(char piece) 
{ 
    if (piece=='P') 
        return 0; 
    if (piece=='N') 
        return 1; 
    if (piece=='B') 
        return 2; 
    if (piece=='R') 
        return 3; 
    if (piece=='Q') 
        return 4; 
    if (piece=='K') 
        return 5; 
    if (piece=='p') 
        return 6; 
    if (piece=='n') 
        return 7; 
    if (piece=='b') 
        return 8; 
    if (piece=='r') 
        return 9; 
    if (piece=='q') 
        return 10; 
    if (piece=='k') 
        return 11; 
    else
        return -1; 
} 
  
// Initializes the table 
void initTable() 
{ 
    for (int i = 0; i<8; i++) 
      for (int j = 0; j<8; j++) 
        for (int k = 0; k<12; k++) 
          ZobristTable[i][j][k] = randomInt(); 
} 
  
// Computes the hash value of a given board 
unsigned long long int computeHash(char board[8][9]) 
{ 
    unsigned long long int h = 0; 
    for (int i = 0; i<8; i++) 
    { 
        for (int j = 0; j<8; j++) 
        { 
            if (board[i][j]!='-') 
            { 
                int piece = indexOf(board[i][j]); 
                h ^= ZobristTable[i][j][piece]; 
            } 
        } 
    } 
    return h; 
} 
  
// Main Function 
int main() 
{ 
    // Uppercase letters are white pieces 
    // Lowercase letters are black pieces 
    char board[8][9] = 
    { 
        "---K----", 
        "-R----Q-", 
        "--------", 
        "-P----p-", 
        "-----p--", 
        "--------", 
        "p---b--q", 
        "----n--k"
    }; 
  
    initTable(); 
  
    unsigned long long int hashValue = computeHash(board); 
    printf("The hash value is     : %llu\n", hashValue); 
  
    //Move the white king to the left 
    char piece = board[0][3]; 
  
    board[0][3] = '-'; 
    hashValue ^= ZobristTable[0][3][indexOf(piece)]; 
  
    board[0][2] = piece; 
    hashValue ^= ZobristTable[0][2][indexOf(piece)]; 
  
  
    printf("The new hash vlaue is : %llu\n", hashValue); 
  
    // Undo the white king move 
    piece = board[0][2]; 
  
    board[0][2] = '-'; 
    hashValue ^= ZobristTable[0][2][indexOf(piece)]; 
  
    board[0][3] = piece; 
    hashValue ^= ZobristTable[0][3][indexOf(piece)]; 
  
    printf("The old hash vlaue is : %llu\n", hashValue); 
  
    return 0; 
} 
