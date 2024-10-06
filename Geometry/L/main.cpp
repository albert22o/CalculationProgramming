#include <iomanip>
#include <bits/stdc++.h>

double Calc2DVectorLength(double x1,double x2,double y1,double y2) {
    return sqrt(pow(x2-x1,2) + (pow(y2-y1,2)));
}

int main() {
    std::ifstream fin("length.in");
    std::ofstream fout("length.out");

    double x1;
    double y1;
    double x2;
    double y2;

    fin >> x1 >> y1 >> x2 >> y2;
    double answ = Calc2DVectorLength(x1, x2, y1, y2);
    fout << std::setprecision(7) << answ << std::endl;
}