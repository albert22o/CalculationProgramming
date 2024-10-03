#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("area1.in", "r", stdin);
    freopen("area1.out", "w", stdout);

    int ax, ay;
    int bx, by;
    int cx, cy;

    cin >> ax >> ay >> bx >> by >> cx >> cy;

    double square = fabs((bx - ax) * (cy - ay) - (cx - ax) * (by - ay)) / 2;

    cout << fixed << square;
}