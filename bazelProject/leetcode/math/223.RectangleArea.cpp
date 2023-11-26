#include "223.RectangleArea.h"
#include <algorithm>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    int left = std::max(ax1, bx1);
    int right = std::max(left, std::min(ax2, bx2));

    int bottown = std::max(ay1, by1);
    int up = std::max(std::min(ay2, by2), bottown);
    return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - (right - left) * (up - bottown);
}