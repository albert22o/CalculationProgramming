#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("area.in", "r", stdin);
    freopen("area.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> vertices;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vertices.push_back(make_pair(x, y));
    }

    double area = 0;

    for (int i = 0; i < vertices.size() - 1; i++)
    {
        area += vertices[i].first * vertices[i + 1].second - vertices[i + 1].first * vertices[i].second;
    }
    area += vertices[vertices.size() - 1].first * vertices[0].second - vertices[0].first * vertices[vertices.size() - 1].second;

    cout << fabs(area) / 2.0;

    return 0;
}