#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int calculate_middle(int left, int right)
{
  return left + (right - left) / 2;
}

vector<int> generate_sub_vector(vector<int> a, int start, int end)
{
  vector<int> sub(end - start + 1);
  for (int i = start; i <= end; ++i)
  {
    sub[i - start] = a[i];
  }
  return sub;
}

int binary_search(const vector<int> &a, int l, int h, int x)
{
  if (h < l)
  {
    return -1;
  }

  int middle = calculate_middle(l, h);
  if (x == a[middle])
  {
    return middle;
  }

  if (x < a[middle])
  {
    return binary_search(a, l, middle - 1, x);
  }
  else
  {
    return binary_search(a, middle + 1, h, x);
  }
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    std::cout << binary_search(a, 0, a.size() - 1, b[i]) << ' ';
  }
}
