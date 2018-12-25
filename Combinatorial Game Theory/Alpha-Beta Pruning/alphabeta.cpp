// C++ program to demonstrate working of Alpha-Beta Pruning
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
const int MIN = -1000;

int minimax(int depth, int nodeIndex, bool maximizingPlayer, int values[], int alpha, int beta)
{

  if (depth == 3)
    return values[nodeIndex];

  if (maximizingPlayer)
  {
    int best = MIN;

    for (int i = 0; i < 2; i++)
    {
      int val = minimax(depth + 1, nodeIndex * 2 + i, false, values, alpha, beta);
      best = max(best, val);
      alpha = max(alpha, best);

      if (beta <= alpha)
        break;
    }
    return best;
  }
  else
  {
    int best = MAX;
    for (int i = 0; i < 2; i++)
    {
      int val = minimax(depth + 1, nodeIndex * 2 + i, true, values, alpha, beta);
      best = min(best, val);
      beta = min(beta, best);
      if (beta <= alpha)
        break;
    }
    return best;
  }
}

int main()
{
  int values[8] = {3, 5, 6, 9, 1, 2, 0, -1};
  cout << "The optimal value is : " << minimax(0, 0, true, values, MIN, MAX);
  return 0;
}
