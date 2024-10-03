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

struct Ray2D{
    Point2D startVec;
    Point2D endVec;

    Ray2D(Point2D startVec, Point2D endVec) : 
        startVec(startVec),
        endVec(endVec) {}
};

struct Line2D
{
    double Acoff;
    double Bcoff;
    double Ccoff;

    Line2D(double Acoff, double Bcoff, double Ccoff) :
        Acoff(Acoff),
        Bcoff(Bcoff),
        Ccoff(Ccoff) {}
};

double CalcDistanceBetweenPointAndLine(Point2D point, Line2D line) {
    return std::abs(line.Acoff * point.X + line.Bcoff * point.Y + line.Ccoff) /
        std::sqrt(line.Acoff * line.Acoff + line.Bcoff * line.Bcoff);
}

Line2D ConvertToNormalEqualization(Point2D A, Point2D B) {
    double ACoff = B.Y - A.Y;
    double BCoff = A.X - B.X;
    double CCoff = A.Y * (B.X - A.X) - A.X * (B.Y - A.Y);

    return Line2D(ACoff, BCoff, CCoff);
}

double Calc2DVectorLength(Point2D A, Point2D B) {
    return sqrt(pow(B.X - A.X, 2) +
        (pow(B.Y - A.Y, 2)));
}

Vec2D CalcVectorBetweenPoints(Point2D p1, Point2D p2) {
    double vecX = p2.X - p1.X;
    double vecY = p2.Y - p1.Y;

    return Vec2D(vecX, vecY);
}

double CalcScalarProd(Vec2D vec1,Vec2D vec2) {
    return vec1.X * vec2.X + vec1.Y * vec2.Y;
}

double CalcDistanceBetweenPointAndRay(Point2D point,Ray2D ray) {

    Vec2D abVector = CalcVectorBetweenPoints(ray.startVec, point);
    Vec2D bcVector = CalcVectorBetweenPoints(ray.startVec, ray.endVec);

    if (CalcScalarProd(abVector, bcVector) < 0) {// перпендикуляр не попадает
        return Calc2DVectorLength(point, Point2D(ray.startVec));
    }

    // перпендикуляр попадет на луч
    auto normalLine = ConvertToNormalEqualization(Point2D(ray.startVec), Point2D(ray.endVec));
    return CalcDistanceBetweenPointAndLine(point, normalLine);
}

int main()
{
    std::ifstream fin("distance3.in");
    std::ofstream fout("distance3.out");

    double x;
    double y;

    double x1;
    double y1;

    double x2;
    double y2;

    fin >> x >> y >> x1 >> y1 >> x2 >> y2;

    fout << std::setprecision(7) << CalcDistanceBetweenPointAndRay(Point2D(x, y),
        Ray2D(Point2D(x1, y1), Point2D(x2, y2))) << "\n";
}