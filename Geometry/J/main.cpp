#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

struct Point
{
  long double x, y;
};

long double distanceBetweenPoints(const Point &p1, const Point &p2)
{
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

long double distancePointToSegment(const Point &p, const Point &a, const Point &b)
{
  long double dx = b.x - a.x;
  long double dy = b.y - a.y;

  if (dx == 0 && dy == 0)
  {
    return distanceBetweenPoints(p, a);
  }

  long double t = ((p.x - a.x) * dx + (p.y - a.y) * dy) / (dx * dx + dy * dy);

  if (t < 0)
  {
    return distanceBetweenPoints(p, a);
  }
  else if (t > 1)
  {
    return distanceBetweenPoints(p, b);
  }

  Point projection = {a.x + t * dx, a.y + t * dy};
  return distanceBetweenPoints(p, projection);
}

long double distanceBetweenSegments(const Point &a1, const Point &a2, const Point &b1, const Point &b2)
{
  long double d1 = distancePointToSegment(a1, b1, b2);
  long double d2 = distancePointToSegment(a2, b1, b2);
  long double d3 = distancePointToSegment(b1, a1, a2);
  long double d4 = distancePointToSegment(b2, a1, a2);
  return std::min(std::min(d1, d2), std::min(d3, d4));
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
  auto orientation = [](Point p, Point q, Point r)
  {
    long double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
      return 0;
    return (val > 0) ? 1 : 2;
  };

  int o1 = orientation(p1, q1, p2);
  int o2 = orientation(p1, q1, q2);
  int o3 = orientation(p2, q2, p1);
  int o4 = orientation(p2, q2, q1);

  if (o1 != o2 && o3 != o4)
    return true;

  auto onSegment = [](Point p, Point q, Point r)
  {
    return q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
           q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y);
  };

  if (o1 == 0 && onSegment(p1, p2, q1))
    return true;
  if (o2 == 0 && onSegment(p1, q2, q1))
    return true;
  if (o3 == 0 && onSegment(p2, p1, q2))
    return true;
  if (o4 == 0 && onSegment(p2, q1, q2))
    return true;

  return false;
}

int main()
{
  freopen("distance5.in", "r", stdin);
  freopen("distance5.out", "w", stdout);
  Point a1, a2, b1, b2;
  std::cin >> a1.x >> a1.y >> a2.x >> a2.y;
  std::cin >> b1.x >> b1.y >> b2.x >> b2.y;

  if (doIntersect(a1, a2, b1, b2))
  {
    std::cout << std::fixed << std::setprecision(10);
    std::cout << 0.0 << std::endl;
  }
  else
  {
    long double distance = distanceBetweenSegments(a1, a2, b1, b2);
    std::cout << std::fixed << std::setprecision(10);
    std::cout << distance << std::endl;
  }

  return 0;
}
