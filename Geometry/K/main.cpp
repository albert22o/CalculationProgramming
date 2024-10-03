#include <bits/stdc++.h>

using namespace std;

double determinant(double a, double b, double c, double d) {
    return a * d - b * c;
}

int main() {

    std::ifstream fin("intersec1.in");
    std::ofstream fout("intersec1.out");

    double A, B, C, A2, B2, C2;
    fin >> A >> B >> C >> A2 >> B2 >> C2;

    double det = determinant(A, B, A2, B2);
    double detx = determinant(-C, B, -C2, B2);
    double dety = determinant(A, -C, A2, -C2);

    double x = detx / det;
    double y = dety / det;

    fout << setprecision(7) << x << " " << y << endl;
}