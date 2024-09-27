#include <iostream>

int main()
{
  freopen("position.in", "r", stdin);
  freopen("position.out", "w", stdout);

  double x1, y1, x2, y2, A, B, C;
  std::cin >> x1 >> y1 >> x2 >> y2 >> A >> B >> C;

  double d1 = A * x1 + B * y1 + C;
  double d2 = A * x2 + B * y2 + C;

  if ((d1 > 0 && d2 > 0) || (d1 < 0 && d2 < 0))
  {
    std::cout << "YES" << std::endl;
  }
  else
  {
    std::cout << "NO" << std::endl;
  }

  return 0;
}
