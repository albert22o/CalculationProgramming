#include <iostream>

int main()
{
  freopen("point3.in", "r", stdin);
  freopen("point3.out", "w", stdout);

  double x_p, y_p, x_a, y_a, x_b, y_b;
  std::cin >> x_p >> y_p >> x_a >> y_a >> x_b >> y_b;

  double det = (x_b - x_a) * (y_p - y_a) - (y_b - y_a) * (x_p - x_a);

  if (det == 0)
  {
    if ((x_p >= std::min(x_a, x_b) && x_p <= std::max(x_a, x_b)) &&
        (y_p >= std::min(y_a, y_b) && y_p <= std::max(y_a, y_b)))
    {
      std::cout << "YES" << std::endl;
    }
    else
    {
      std::cout << "NO" << std::endl;
    }
  }
  else
  {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
