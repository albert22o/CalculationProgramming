#include <iostream>
#include <fstream>

int main() {
    std::ifstream in("line1.in");
    int x1, y1, x2, y2;
    in >> x1 >> y1 >> x2 >> y2;

    std::ofstream out("line1.out");
    int A = y2 - y1;
    int B = x1 - x2;
    int C = x2 * y1 - x1 * y2;
    out << A << " " << B << " " << C;

    return 0;
}