# Zobrist Hashinng

Zobrist Hashing is a hashing function that is widely used in 2 player board games. It is the most common hashing function used in transposition table. Transposition tables basically store the evaluated values of previous board states, so that if they are encountered again we simply retrieve the stored value from the transposition table. We will be covering transposition tables in a later article. In this article we shall take the example of chess board and implement a hashing function for that.


## Pseudocode :

// A matrix with random numbers initialized once
Table[#ofBoardCells][#ofPieces] 

// Returns Zobrist hash function for current conf-
// iguration of board.
function findhash(board):
    hash = 0
    for each cell on the board :
        if cell is not empty :
            piece = board[cell]
            hash ^= table[cell][piece]
    return hash


## Explanation :

The idea behind Zobrist Hashing is that for a given board state, if there is a piece on a given cell, we use the random number of that piece from the corresponding cell in the table. 
If more bits are there in the random number the lesser chance of a hash collision. Therefore 64 bit numbers are commonly used as the standard and it is highly unlikely for a hash collision to occur with such large numbers. The table has to be initialized only once during the programs execution.

Also the reason why Zobrist Hashing is widely used in board games is because when a player makes a move, it is not necessary to recalculate the hash value from scratch. Due to the nature of XOR operation we can simply use few XOR operations to recalculate the hash value.
