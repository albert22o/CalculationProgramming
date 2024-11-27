#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

void parallel_lines(double A, double B, double C, double R, ostream &out)
{
  double norm = sqrt(A * A + B * B);
  double C1 = C + R * norm;
  double C2 = C - R * norm;
  out << fixed << setprecision(6) << A << " " << B << " " << C1 << " " << A << " " << B << " " << C2 << endl;
}

int main()
{
  ifstream in("line3.in");
  ofstream out("line3.out");

  double A, B, C, R;
  in >> A >> B >> C >> R;
  parallel_lines(A, B, C, R, out);

  return 0;
}
