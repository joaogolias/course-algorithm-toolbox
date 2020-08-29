#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    stops.push_back(dist);
    int index = 0;
    int lastRefillIndex = 0;
    int count = 0;
    while (index < stops.size())
    {
        lastRefillIndex = index;

        while (index < stops.size() && stops[index + 1] - stops[lastRefillIndex] <= tank)
        {
            ++index;
        }

        if (lastRefillIndex == index)
        {
            return -1;
        }

        if (index < stops.size())
        {
            ++count;
        }
    }
    return count;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n + 1);
    stops[0] = 0;
    for (size_t i = 1; i < n + 1; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
