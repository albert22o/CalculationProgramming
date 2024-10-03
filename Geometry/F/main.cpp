#include <bits/stdc++.h>

struct Point2D {
    double X;
    double Y;

    Point2D(double x,double y) : X(x),Y(y) {}
};

struct Line2D
{
    double Acoff;
    double Bcoff;
    double Ccoff;

    Line2D(double Acoff, double Bcoff, double Ccoff) :
        Acoff(Acoff), Bcoff(Bcoff), Ccoff(Ccoff) {}
};

double CalcDistanceBetweenPointAndLine(Point2D point,Line2D line) {
    return std::abs(line.Acoff * point.X + line.Bcoff * point.Y + line.Ccoff) /
        std::sqrt(line.Acoff * line.Acoff + line.Bcoff * line.Bcoff);
}

int main() { // F solution
    std::ifstream fin("distance1.in");
    std::ofstream fout("distance1.out");

    double x;
    double y;
    double a;
    double b;
    double c;

    fin >> x >> y >> a >> b >> c;
    fout << std::setprecision(7) << CalcDistanceBetweenPointAndLine(Point2D(x,y),Line2D(a,b,c)) << "\n";
}