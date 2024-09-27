#include <iostream>

int main()
{
  freopen("point2.in", "r", stdin);
  freopen("point2.out", "w", stdout);

  double x_p, y_p, x_a, y_a, x_b, y_b;
  std::cin >> x_p >> y_p >> x_a >> y_a >> x_b >> y_b;

  double det = (x_b - x_a) * (y_p - y_a) - (y_b - y_a) * (x_p - x_a);
  double scalar_product = (x_b - x_a) * (x_p - x_a) + (y_b - y_a) * (y_p - y_a);

  if (det == 0 && scalar_product >= 0)
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
