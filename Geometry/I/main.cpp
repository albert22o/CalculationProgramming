#include <bits/stdc++.h>

struct Point2D {
    double X;
    double Y;

    Point2D(double x, double y) : 
        X(x), Y(y) {}
};

struct Segment2D {
    Point2D start;
    Point2D end;

    Segment2D(Point2D start,Point2D end) : start(start), end(end) {}
};

double Calc2DVectorLength(Point2D A, Point2D B) {
    return sqrt(pow(B.X - A.X, 2) +
        (pow(B.Y - A.Y, 2)));
}

double CalcDistanceBetweenPointAndSegment(Point2D point, Segment2D segment) {

    auto dx = segment.end.X - segment.start.X;
    auto dy = segment.end.Y - segment.start.Y;
    
    auto scalarProd = (dx * (point.X - segment.start.X) + dy * (point.Y - segment.start.Y)) /
        (dx * dx + dy * dy);

    if (scalarProd <= 0) {// точка лежит на продолжении луча, выходящего из первой точки отрезка
        return Calc2DVectorLength(point, segment.start);
    }
    else if (scalarProd >= 1) { // точка лежит на продолжении луча, выходящего из второй точки отрезка
        return Calc2DVectorLength(point, segment.end);
    }
    
    double t = dx * (point.Y - segment.start.Y) - dy * (point.X - segment.start.X);
    return abs(t) / sqrt(dx * dx + dy * dy);
}


int main()
{
    std::ifstream fin("distance4.in");
    std::ofstream fout("distance4.out");

    double x;
    double y;

    double x1;
    double y1;

    double x2;
    double y2;

    fin >> x >> y >> x1 >> y1 >> x2 >> y2;

    fout << std::setprecision(7) << CalcDistanceBetweenPointAndSegment(Point2D(x, y),
        Segment2D(Point2D(x1, y1), Point2D(x2, y2))) << "\n";
}
