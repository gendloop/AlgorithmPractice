#pragma once
/**
 * @file	point_in_polygon.h
 * @brief	判断点是否在多边形内部
 * @author  gendloop
 */

// c++
#include <vector>

class PointInPolygon {
public:
    class Point {
    public:
        double x, y;
    };

    /// 点是否在多边形内
    bool isPointInPolygon(const std::vector<Point>& polygon, const Point& p) {
        // 先判断是否在边上
        for (size_t i = 0; i < polygon.size(); ++i) {
            Point a = polygon[i];
            Point b = polygon[(i + 1) % polygon.size()];
            if (isPointOnEdge(p, a, b)) {
                return true;
            }
        }
        // 再判断是
        return windingNumber(polygon, p) != 0;
    }
    
protected:
    /// 叉积
    double cross(const Point& O, const Point& a, const Point& b) {
        return (a.x - O.x) * (b.y - O.y) - (a.y - O.y) * (b.x - O.x);
    }

    /// 点相对于多边形的环绕数
    int windingNumber(const std::vector<Point>& polygon, const Point& p) {
        int count = 0;
        for (size_t i = 0; i < polygon.size(); ++i) {
            Point a = polygon[i];
            Point b = polygon[(i + 1) % polygon.size()];
            if (a.y <= p.y && b.y > p.y) {
                if (cross(p, a, b) > 0) {
                    ++count;
                }
            }
            else if (a.y > p.y && b.y <= p.y) {
                if (cross(p, a, b) < 0) {
                    --count;
                }
            }
        }
        return count;
    }

    /// 点是否在边上
    bool isPointOnEdge(const Point& p, const Point& a, const Point& b) {
        if (cross(a, b, p) > tolerance_) return false;
        double min_x = __min(a.x, b.x);
        double max_x = __max(a.x, b.x);
        double min_y = __min(a.y, b.y);
        double max_y = __max(a.y, b.y);
        return (p.x >= min_x - tolerance_ && p.x <= max_x + tolerance_)
            && (p.y >= min_y - tolerance_ && p.y <= max_y + tolerance_);
    }
   
private:
    double tolerance_ = .1;
};
