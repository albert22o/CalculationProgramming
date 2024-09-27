#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
  freopen("line3.in", "r", stdin);
  freopen("line3.out", "w", stdout);

  long double A, B, C, R;
  std::cin >> A >> B >> C >> R;


  if (B == 0)
  {
    long double x1 = -C / A + R;
    long double x2 = -C / A - R;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "0 1 " << -x1 << std::endl;
    std::cout << "0 1 " << -x2 << std::endl;
  }
  else
  {
    long double distance = R * sqrt(A * A + B * B) / B;
    long double C1 = C + distance;
    long double C2 = C - distance;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << A << " " << B << " " << C1 << std::endl;
    std::cout << A << " " << B << " " << C2 << std::endl;
  }

  return 0;
}
