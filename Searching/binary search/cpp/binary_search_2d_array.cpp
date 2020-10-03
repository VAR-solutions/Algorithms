// matrix is a 2d array 
// target is a value to search for in a 2d array
bool searchMatrix(vector<vector<int>>& matrix, int target) {

  int i, j, m = matrix.size();
  
  // if it is an empty matrix return false
  if(m == 0)
      return false;
      
  // l is the lower bound which is set to 0
  // r is the upper bound of a column which is set to (n-1)
  // row is declared to traverse every row
  int n = matrix[0].size(), l = 0, r = n-1, row = 0;
  
  while(l <= r && row < m)
  {
      // find middle value of a row
      int mid=(l+r)/2;
      
      // if middle of a row is target value then return true
      if(matrix[row][mid] == target)
          return true;
          
      // if target is less than middle value of row, then search in left direction
      else if(target < matrix[row][mid])
          r = mid-1;
          
      // if target is greater than middle of row and less than last value of that row, search in between them
      else if(target > matrix[row][mid] && target <= matrix[row][r])
          l = mid+1;
          
       // if target is greater than end value of row, search in next row
      else if(target > matrix[row][r])
          row++;
  }
  
  // if not found in matrix, return false
  return false;
}
