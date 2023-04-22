#include <iostream>
#include <random>
#include "./include/TwoNearestPoint.h"


int main(int, char**) {
    std::vector<Point> points;

    // Seed the random number generator
    std::mt19937 rng(std::random_device{}());

    // Generate 15 random points with x and y coordinates between 0 and 99
    std::uniform_int_distribution<int> dist(0, 99);
    for (int i = 0; i < 15; i++) {
        Point p = {dist(rng), dist(rng)};
        std::cout<<p<<std::endl;
        points.push_back(p);
    }
    TwoNearestPoint util(points);

    auto [minDist, np] = util.getPoints();
    std::cout<<"Point1: "<<np.first<<"Point2: "<<np.second;
    std::cout<<"Distance: "<<minDist<<std::endl;
}
