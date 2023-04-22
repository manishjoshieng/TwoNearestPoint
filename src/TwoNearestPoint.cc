#include "../include/TwoNearestPoint.h"
#include <algorithm>
#include <cmath>
#include <set>
#include <tuple>


double 
Point::distance(const Point& other) const {
    auto sq1 = pow(x - other.x,2);
    auto sq2 = pow(y - other.y,2);
    return sqrt(sq1+sq2);
}

tuple<double,pair<Point,Point> > 
TwoNearestPoint::getPoints()
{
    int size = _points.size();
    if(size==0 || size==1){
        return make_pair(-1,make_pair(Point(),Point()));
    }

    sort(_points.begin(),_points.end(),[](const Point& p1, const Point& p2){
        return p1.x < p2.x;
    });

    pair<Point,Point> pair = getPointsInternal(_points,0,_points.size()-1);

    double minDist = pair.first.distance(pair.second);
    return make_tuple(minDist,pair);

}

pair<Point,Point> 
TwoNearestPoint::getPointsInternal(
            const vector<Point>& points, 
            int start, int end) {
    int size = end - start + 1;

    if (size == 2){
        return make_pair(points[start],points[end]);
    } else if(size==3){
        double dis1 = points[start].distance(points[start+1]);
        double dis2 = points[start].distance(points[start+2]);
        double dis3 = points[start+1].distance(points[start+2]);
        if(dis1 > dis2 && dis1> dis3) return make_pair(points[start],points[start+1]);
        else if(dis2 > dis1 && dis2 > dis3) return make_pair(points[start],points[start+2]);
        else return make_pair(points[start+1],points[start+2]);
    }

    int mid = start + (end-start)/2;
    auto pair1 = getPointsInternal(points,start,mid);
    auto pair2 = getPointsInternal(points,mid+1,end);

    auto d1 = pair1.first.distance(pair1.second);
    auto d2 = pair2.first.distance(pair2.second);

    double dist = d1; auto pair = pair1;
    if(d1 > d2) {dist = d2; pair=pair2;}

    auto compY = [](const Point& p1,const Point& p2){return p1.y < p2.y;};
    set<Point, decltype(compY)> strip(compY);

    for(int i = start, x1 = points[mid].x;i<=end;i++){
        int x2 = points[i].x;
        if(abs(x2-x1) < dist)strip.emplace(points[i]);        
    }
    for(auto itr = strip.begin();itr!= strip.end();itr++) {
        for(auto itr2 = (std::next(itr));itr2!=strip.end() && (itr2->y - itr->y < dist); itr2++){
            auto d = itr2->distance(*itr);
            if(d < dist){
                dist = d;
                pair = make_pair(*itr, *itr2);
            }
        }
    }

    return pair;
}
