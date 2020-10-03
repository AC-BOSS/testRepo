#include <bits/stdc++.h>
using namespace std;
typedef struct Point Point;

struct Point
{
    int x, y;
};

float dist(Point p1, Point p2)
{
    //calculating distance by formula root(x2-x1)^2+(y2-y1)^2
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

//for n<3 we can apply brut force
float Normal(Point p[], int n)
{
    float min = INT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dist(p[i], p[j]) < min)
                min = dist(p[i], p[j]);
    return min;
}

float min(float x, float y)
{
    return (x < y) ? x : y;
}

int comparex(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int comparey(const void *a, const void *b)
{
    Point *p1 = (Point *)a, *p2 = (Point *)b;
    return (p1->y - p2->y);
}

float closestPair(Point *p, int n)
{
    if (n <= 3)
    {
        return Normal(p, n);
    }
    int m = n / 2;
    Point mid = p[m];

    float leftdist = closestPair(p, m);
    float rightdist = closestPair(p + m, n - m);

    //minimum of min distance of left and right part
    float mindist = min(leftdist, rightdist);

    Point s[n];
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(p[i].x - mid.x) < mindist)
        {
            s[k] = p[i];
            k++;
        }
    }
    float q = mindist;
    qsort(s, k, sizeof(Point), comparey);

    for (int i = 0; i < k; ++i)
    {
        for (int j = i + 1; j < k && (s[j].y - s[i].y) < q; ++j)
        {
            if (dist(s[i], s[j]) < q)
            {
                q = dist(s[i], s[j]);
            }
        }
    }
    return min(mindist, q);
}

float closest(Point p[], int n)
{
    qsort(p, n, sizeof(Point), comparex);
    return closestPair(p, n);
}

int main()
{
    Point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    float min = closest(p, 6);
    cout << "Minimun distance between the given pairs : ";
    printf("%f", min);
    return 0;
}
