import time
import random


class TicTacToe():
    '''Class that has all necesarry components for a tic tac toe game'''
    def __init__(self, player1, player2):
        self.board = [[None, None, None],
                      [None, None, None],
                      [None, None, None]]
        self.current_player = player1.player_mark
        self.player1 = player1
        self.player2 = player2

    def render(self):
        '''Renders the current board state'''
        for row in self.board:
            print("|", end="")
            for item in row:
                if item is None:
                    print(".", end="|")
                else:
                    print(item, end="|")
            print()

    def possible_moves(self):
        '''Finds all possible_moves of current board state'''
        moves = []
        for x in range(len(self.board)):
            for y in range(len(self.board[x])):
                if self.board[x][y] is None:
                    moves.append((x, y))

        return moves

    def legal_move(self, move):
        '''Determines if given move is legal'''
        legal_moves = self.possible_moves()
        if move in legal_moves:
            return True
        return False

    def move(self, move):
        '''Moves a piece and switches current_player'''
        if self.legal_move(move):
            move_x = move[0]
            move_y = move[1]
            self.board[move_x][move_y] = self.current_player
            self.last_move = move
            self.switch()
            return True
        else:
            return False

    def switch(self):
        '''Switches current player'''
        if self.current_player == "x":
            self.current_player = "o"
        else:
            self.current_player = "x"

    def game_over(self):
        '''Finds if current board_state is full and the game is over'''
        if self.game_won():
            return True
        for row in self.board:
            for item in row:
                if item is None:
                    return False
        return True

    def game_won(self):
        '''Finds if game is won and updates self.winning_player'''
        board = self.board
        for x in range(len(self.board)):
            for y in range(len(self.board[x])):
                mark = self.board[x][y]
                if board[x][y] is not None:
                    if board[0][y] == board[1][y] == board[2][y]:
                        self.winning_player = mark
                        return True
                    if board[x][0] == board[x][1] == board[x][2]:
                        self.winning_player = mark
                        return True
                    if x == y and board[0][0] == board[1][1] == board[2][2]:
                        self.winning_player = mark
                        return True
                    if x + y == 2:
                        if board[0][2] == board[1][1] == board[2][0]:
                            self.winning_player = mark
                            return True
        return False

    def revert_move(self, move):
        x = move[0]
        y = move[1]
        self.switch()
        self.board[x][y] = None

    def play(self):
                
        while not self.game_over():
            player_1_move = self.player1.best_move(self)
            time.sleep(1)
            self.move(player_1_move)
            self.render()
            print()
            
            if self.game_over():
                if self.game_won():
                    print(self.winning_player, "has won!")
                    exit(0)
                print("Nobody has won")
                exit(0)                

            player_2_move = self.player2.best_move(self)
            time.sleep(1)
            self.move(player_2_move)
            self.render()
            print()

        if self.game_won():
            print(self.winning_player, "has won!")
            exit(0)
        else:
            print("Nobody has won.")


class MiniMaxPlayer():
    '''A perfect player that uses minimax to determine best move'''
    def __init__(self, player):
        self.player_mark = player

    def score(self, game, depth):
        '''returns score of given board'''
        if game.game_won():
            if game.winning_player is self.player_mark:
                return 10 - depth
            else:
                return depth - 10
        return 0

    def minimax(self, game, depth):
        '''Minimax solution to selecting what to play'''
        if game.game_over():
            return self.score(game, depth)

        depth += 1

        scores = []
        moves = []
        # Recursively adds all scores of every possible move of a given state
        for move in game.possible_moves():
            game.move(move)
            scores.append(self.minimax(game, depth))
            game.revert_move(move)
            moves.append(move)

        self.scores = scores
        self.moves = moves

        # max solution in case current player is this player
        if game.current_player is self.player_mark:
            max_score_idx = scores.index(max(scores))
            highest_score = scores[max_score_idx]
            # finds all moves with same value and selects one at random so
            # every game doesn't play out the same
            best_moves = []
            for i, move in enumerate(moves):
                if scores[i] == highest_score:
                    best_moves.append(move)
            self.choice = (random.choice(best_moves))
            return scores[max_score_idx]

        # min solution in case current player is opponent
        else:
            min_score_idx = scores.index(min(scores))
            self.choice = moves[min_score_idx]
            return scores[min_score_idx]

    def best_move(self, game):
        '''returns best move calculated with mini-max'''
        self.minimax(game, 0)
        return self.choice


class HumanPlayer():
    def __init__(self, player):
        self.player_mark = player

    def best_move(self, game):
        possible_moves = game.possible_moves()
        x = None
        y = None
        while True:
            x = int(input("What row do you want to mark?: ")) - 1
            y = int(input("What column do you want to mark?: ")) - 1
            if (x, y) in possible_moves:
                break
            else:
                print("That position has already been marked")
        return (x, y)


# player1 starts, indepent of marks.
player1 = HumanPlayer("x")
player2 = MiniMaxPlayer("o")

game = TicTacToe(player1, player2)
game.play()