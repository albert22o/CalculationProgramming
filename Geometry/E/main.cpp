#include <iostream>
#include <cmath>
#include <tuple>

std::tuple<double, double, double> lineEquation(double x1, double y1, double x2, double y2)
{
  double A = y2 - y1;
  double B = x1 - x2;
  double C = -(A * x1 + B * y1);
  return std::make_tuple(A, B, C);
}

std::tuple<double, double, double> findBisectorCoefficients(double A1, double B1, double C1, double A2, double B2, double C2)
{
  double norm1 = std::sqrt(A1 * A1 + B1 * B1);
  double norm2 = std::sqrt(A2 * A2 + B2 * B2);
  double A_bis = A1 / norm1 + A2 / norm2;
  double B_bis = B1 / norm1 + B2 / norm2;
  double C_bis = C1 / norm1 + C2 / norm2;

  return std::make_tuple(A_bis, B_bis, C_bis);
}


std::tuple<double, double, double> normalizeEquation(double A, double B, double C)
{
  double norm = std::sqrt(A * A + B * B);
  return std::make_tuple(A / norm, B / norm, C / norm);
}

int main()
{
  freopen("bisector.in", "r", stdin);
  freopen("bisector.out", "w", stdout);
  double x_v, y_v, x1, y1, x2, y2;
  std::cin >> x_v >> y_v;
  std::cin >> x1 >> y1;
  std::cin >> x2 >> y2;
  auto [A1, B1, C1] = lineEquation(x_v, y_v, x1, y1);
  auto [A2, B2, C2] = lineEquation(x_v, y_v, x2, y2);
  auto [A_bis, B_bis, C_bis] = findBisectorCoefficients(A1, B1, C1, A2, B2, C2);
  auto [A_norm, B_norm, C_norm] = normalizeEquation(A_bis, B_bis, C_bis);
  std::cout << A_norm << " " << B_norm << " " << C_norm << " " << std::endl;

  return 0;
}
