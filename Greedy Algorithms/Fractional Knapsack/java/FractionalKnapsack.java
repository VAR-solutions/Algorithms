import java.util.Arrays;
import java.util.Comparator;

public class FractionalKnapsack {
  
  double getOptimalValue(int capacity, int[] weights, int[] values) {
    double[][] weightValArr = new double[weights.length][2];
    for (int i = 0; i < weightValArr.length; i++) {
      weightValArr[i][0] = weights[i];
      weightValArr[i][1] = values[i];
    }

    Arrays.sort(weightValArr, new Comparator<double[]>() {
      @Override
      public int compare(double[] a, double[] b) {
        double weigthByValue1 = a[0] / a[1];
        double weightByValue2 = b[0] / b[1];
        if (weigthByValue1 == weightByValue2) {
          return 0;
        }
        return weigthByValue1 > weightByValue2 ? 1 : -1;
      }
    });

    double maxValue = 0;
    double weightRemaining = capacity;
    for (int i = 0; i < weightValArr.length; i++) {
      if (weightRemaining == 0) {
        break;
      }
      double weight = weightValArr[i][0];
      double value = weightValArr[i][1];
      if (weightRemaining - weight >= 0) {
        weightRemaining -= weight;
        maxValue += value;
      } else {
        double qty = weightRemaining / weight;
        maxValue += value * qty;
        weightRemaining -= (weight * qty);
      }
    }
    return maxValue;
  }
}
