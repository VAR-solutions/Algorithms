#include <iostream>
#include <vector>
using namespace std;

//vector <int> coins = {1,2,3};
vector<int> coins;
int coinChange(int amount)
{

    vector<int> combinations(amount + 1, 0);
    combinations[0] = 1;

    for (auto &&coin : coins)
    {

        for (int i = 1; i < combinations.size(); i++)
        {
            if (coin <= i)
            {
                combinations[i] += combinations[i - coin];
            }
        }
    }

    return combinations[amount];
}

int main(int argc, char const *argv[])
{

    int amount;
    cin >> amount;

    int size, item;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> item;
        coins.push_back(item);
    }

    cout << coinChange(amount);

    return 0;
}
