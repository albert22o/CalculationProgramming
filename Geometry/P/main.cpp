#include <iostream>

int main()
{
  freopen("point1.in", "r", stdin);
  freopen("point1.out", "w", stdout);

  double x_p, y_p, A, B, C;
  std::cin >> x_p >> y_p >> A >> B >> C;

  if (A * x_p + B * y_p + C == 0)
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
