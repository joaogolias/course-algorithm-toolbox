#include <iostream>

int get_change(int m)
{
  int n = 0, value = m;
  while (value > 0)
  {
    if (value >= 10)
    {
      value = value - 10;
    }
    else if (value >= 5)
    {
      value = value - 5;
    }
    else if (value >= 1)
    {
      value = value - 1;
    }
    ++n;
  }
  //write your code here
  return n;
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
