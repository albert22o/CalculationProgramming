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

Line2D ConvertToNormalEqualization(Point2D A, Point2D B) {
    double ACoff = B.Y - A.Y;
    double BCoff = A.X - B.X;
    double CCoff = A.Y * (B.X - A.X) - A.X * (B.Y - A.Y);

    return Line2D(ACoff, BCoff, CCoff);
}

double CalcDistanceBetweenPointAndLine(Point2D point,Line2D line) {
    return std::abs(line.Acoff * point.X + line.Bcoff * point.Y + line.Ccoff) /
        std::sqrt(line.Acoff * line.Acoff + line.Bcoff * line.Bcoff);
}

int main() { // G solution
    std::ifstream fin("distance2.in");
    std::ofstream fout("distance2.out");

    double x;
    double y;

    double lineX1;
    double lineX2;

    double lineY1;
    double lineY2;

    fin >> x >> y >> lineX1 >> lineY1 >> lineX2 >> lineY2;
    
    Line2D lineNormalForm = 
    ConvertToNormalEqualization(Point2D(lineX1,lineY1),
        Point2D(lineX2,lineY2));

    fout << std::setprecision(7) << 
    CalcDistanceBetweenPointAndLine(Point2D(x, y),lineNormalForm) << "\n";
}