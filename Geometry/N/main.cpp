#include <bits/stdc++.h>

struct Point2D {
    double X;
    double Y;

    Point2D(double x, double y) : 
        X(x), Y(y) {}
};

struct Vec2D
{
    double X;
    double Y;

    Vec2D(double x, double y) :
        X(x), Y(y) {}
};

struct NormalLine2D
{
    double Acoff;
    double Bcoff;
    double Ccoff;

    NormalLine2D(double Acoff, double Bcoff, double Ccoff) :
        Acoff(Acoff),
        Bcoff(Bcoff),
        Ccoff(Ccoff) {}
};

NormalLine2D normal_equation(Point2D p, Vec2D v) {
   
    double A = v.X;
    double B = v.Y;
    double C = -A * p.X - B * p.Y;

    return NormalLine2D(A, B, C);
}


int main() {
    std::ifstream fin("line2.in");
    std::ofstream fout("line2.out");

    double x;
    double y;

    double vecX;
    double vecY;

    fin >> x >> y >> vecX >> vecY;

    auto normalLine = normal_equation(Point2D(x, y), Vec2D(vecX, vecY));

    fout << normalLine.Acoff << " " << normalLine.Bcoff << " " << normalLine.Ccoff << "\n";
}