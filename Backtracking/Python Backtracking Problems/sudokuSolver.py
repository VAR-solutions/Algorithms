"""	Sudoku Solver In Python using Backtracking
	Input:- 2D matrix consisting of numbers from 1->9
			cells to be filled are represnted by '.'
	Output:- True/False and Filled Board if True
	
	Time Complexity:- O(9^(N*N)) It is exponential time complexity 
					  9 is the number of possible combinations for a cell, n*n is for whole board
	Space Complexity: O(N*N)
"""

class Sudoku:

	board = [[]]

	# constructor to initialize board
	def __init__(self,board):	
		print("Sudoku Solver has Started")
		self.board=board			

	# prints the board
	def show_board(self):
		for row in range(9):
			for col in range(9):
				print(self.board[row][col],end=' ')
			print()

	# searches cell to be filled in board
	def search_empty_location(self,empty_cell):
		# traverse over whole board and search for empty cell
		for row in range(9):
			for col in range(9):
				if(self.board[row][col]=='.'):
					empty_cell[0]=row
					empty_cell[1]=col
					return True
		return False	

	# checks horizontally for a row if value exists 
	def is_row_safe(self, row, num):
		for i in range(9):
			if(self.board[row][i]==num):
				return True
		return False

	# checks vertically for column if value exists
	def is_col_safe(self, col, num):
		for i in range(9):
			if(self.board[i][col]==num):
				return True
		return False

	# checks if 3x3 block is safe or not 
	def is_square_safe(self, row, col, num):
		for i in range(3):
			for j in range(3):
				if(self.board[i + row][j+col] == num):
					return True
		return False

	# check for the cell if filled value is safe to fill or not 
	def is_safe(self,row,col,i):
		return not self.is_row_safe(row,i) and not self.is_col_safe(col,i) and not self.is_square_safe(row-row%3,col-col%3,i)


	# main function for solving sudoku
	def solve_sudoku(self):

		empty_cell=[0,0]
		# we find the empty cell in board else if there is no empty cell then return True 
		if(not self.search_empty_location(empty_cell)):
			return True
		# empty_cell[0]=x coordinate empty_cell[1]=y coordinate
		rowNum =empty_cell[0]
		colNum =empty_cell[1]

		# traverse over the whole board
		for i in range(1,10):

			# if the value we filled in cell is safe then fill it
			if(self.is_safe(rowNum,colNum,i)):
				# fill the value and check for validity
				self.board[rowNum][colNum] = i

				if(self.solve_sudoku()):
					return True

				# backtrack and remove the value than we filled
				self.board[rowNum][colNum] = '.'

		# if True is not returned that means no possible solution exists
		return False


# driver code
board =[[0 for x in range(9)]for y in range(9)] 	  
board =[  [3    , '.'  , 6   , 5    , '.'	, 8		, 4		,  '.'	, '.'], 
		  [5    , 2    , '.' , '.'  , '.'	,'.'	,  '.'	,  '.'	, '.'], 
		  ['.'  , 8    , 7   , '.'  , '.'	, '.'	,  '.'	, 3		, 1  ], 
		  ['.'  , '.'  , 3   , '.'  , 1		, '.'	,  '.'	, 8		, '.'], 
		  [9    , '.'  , '.' , 8    , 6		, 3		,  '.'	,  '.'	, 5  ], 
		  ['.'  , 5    , '.' , '.'  , 9		, '.'	, 6		,  '.'	, '.'], 
		  [1    , 3    , '.' , '.'  , '.'	, '.'	, 2		, 5		, '.'], 
		  ['.'  , '.'  , '.' , '.'  , '.'	, '.'	,  '.'	, 7		, 4  ], 
		  ['.'  , '.'  , 5   , 2    , '.'	, 6		, 3		,  '.'	, '.']] 

# create object of Sudoku class
solve = Sudoku(board)

if(solve.solve_sudoku()):
	print(True)
	solve.show_board()
	
else:
	print(False)