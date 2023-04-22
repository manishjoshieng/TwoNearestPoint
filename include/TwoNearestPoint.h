#pragma once

#include    <vector>
#include    <tuple>
#include    <ostream>

using namespace std;



struct Point{
    int x;
    int y;
    Point(int x = 0, int y = 0):x(x),y(y){}
    double distance(const Point& other) const;

    friend ostream& operator<<(ostream& os, const Point& p) {
        return os << "{" << p.x << " " << p.y << "}\n";
    }
};

class TwoNearestPoint{
    public:
        TwoNearestPoint(const vector<Point>& data) 
        :  _points(data)
        {}

        tuple<double, pair<Point, Point>>     getPoints();

        int                                 getMinDistance();

    private:

        pair<Point,Point> getPointsInternal(
            const vector<Point>& points, 
            int start, int end);


        //Data

        vector<Point> _points;
};