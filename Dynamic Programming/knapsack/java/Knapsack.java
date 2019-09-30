
public class Knapsack {

  public int knapSack(int weights[], int costs[], int capacity) {
    int numberOfWeights = weights.length;
    int best[][] = new int[numberOfWeights + 1][capacity + 1];

    // calculate the best array
    for (int i = 0; i <= numberOfWeights; i++) {
      for (int weight = 0; weight <= capacity; weight++) {

        if (i == 0 || weight == 0) {
          best[i][weight] = 0;

        } else if (weights[i - 1] <= weight) {
          best[i][weight] = Math.max(best[i - 1][weight],
              costs[i - 1] + best[i - 1][weight - weights[i - 1]]);

        } else {
          best[i][weight] = best[i - 1][weight];
        }
      }
    }

    return best[numberOfWeights][capacity];
  }
}
