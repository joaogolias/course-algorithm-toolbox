#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

struct LOOT
{
  int weight;
  int value;
  double density;
};

bool sorting_loots_by_density(LOOT i, LOOT j) { return (i.density > j.density); }

double get_optimal_value(int capacity, vector<LOOT> loots)
{
  double value = 0.0;
  double remaining_capacity = capacity;
  int loot_index = 0;
  while (remaining_capacity >= 0 && loot_index < loots.size())
  {
    double fraction = 1;
    double current_weight = loots[loot_index].weight;
    if (loots[loot_index].weight > remaining_capacity)
    {
      fraction = (1.0) * remaining_capacity / loots[loot_index].weight;
      current_weight = remaining_capacity;
    }

    remaining_capacity -= current_weight;
    value += fraction * loots[loot_index].value;
    // value += remaining_capacity * loots[loot_index].density;
    ++loot_index;
  }

  return value;
}

vector<LOOT>
generate_loot_vector(vector<int> values,
                     vector<int> weights)
{
  vector<LOOT> loots(values.size());
  for (int i = 0; i < values.size(); ++i)
  {
    LOOT loot;
    loot.value = values[i];
    loot.weight = weights[i];
    loot.density = ((1.0) * loot.value) / loot.weight;
    loots[i] = loot;
  }
  sort(loots.begin(), loots.end(), sorting_loots_by_density);
  return loots;
}
int main()
{
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> values[i] >> weights[i];
  }
  vector<LOOT> loots = generate_loot_vector(values, weights);
  double optimal_value = get_optimal_value(capacity, loots);
  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
