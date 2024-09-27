#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

struct Point
{
  double x, y;
};

double distanceBetweenPoints(const Point &p1, const Point &p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double distancePointToRay(const Point &p, const Point &rayStart, const Point &rayDirection)
{
  double dx = rayDirection.x - rayStart.x;
  double dy = rayDirection.y - rayStart.y;

  if (dx == 0 && dy == 0)
  {
    return distanceBetweenPoints(p, rayStart);
  }

  double t = ((p.x - rayStart.x) * dx + (p.y - rayStart.y) * dy) / (dx * dx + dy * dy);
  if (t < 0)
  {
    return distanceBetweenPoints(p, rayStart);
  }

  Point projection = {rayStart.x + t * dx, rayStart.y + t * dy};
  return distanceBetweenPoints(p, projection);
}

bool checkIntersection(const Point &A, const Point &B, const Point &C, const Point &D)
{
  double det = (B.x - A.x) * (D.y - C.y) - (B.y - A.y) * (D.x - C.x);
  if (det == 0)
  {
    return false; // Лучи параллельны
  }

  double t1 = ((C.x - A.x) * (D.y - C.y) - (C.y - A.y) * (D.x - C.x)) / det;
  double t2 = ((C.x - A.x) * (B.y - A.y) - (C.y - A.y) * (B.x - A.x)) / det;

  return (t1 >= 0 && t2 >= 0); // Проверяем, что оба параметра неотрицательны
}

double distanceBetweenRays(const Point &A, const Point &B, const Point &C, const Point &D)
{
  if (checkIntersection(A, B, C, D))
    return 0.0; 

  double d1 = distancePointToRay(A, C, D);
  double d2 = distancePointToRay(B, C, D);
  double d3 = distancePointToRay(C, A, B);
  double d4 = distancePointToRay(D, A, B);
  return std::min({d1, d2, d3, d4});
}

int main()
{
  freopen("raydist.in", "r", stdin);
  freopen("raydist.out", "w", stdout);

  Point A, B, C, D;
  std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

  double distance = distanceBetweenRays(A, B, C, D);

  std::cout << std::fixed << std::setprecision(5) << distance << std::endl;

  return 0;
}
