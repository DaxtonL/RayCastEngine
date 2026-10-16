#include "raycast/ray.h"
#include <cmath>

using std::pair;

Ray::Ray(float x0, float y0, float dx, float dy)
    : x0(x0), y0(y0), dx(dx), dy(dy) {}

std::optional<pair<float, float>> Ray::getIntersectPoint(const Rectangle& rect) const {
    float bestT = INFINITY;
    pair<float, float> closest;

    if (dy != 0.0f) {
        {   // Check top
            float t = (rect.y - y0) / dy;
            float x = x0 + dx * t;
            if (t >= 0 && t < bestT && x >= rect.x && x <= rect.x + rect.width) {
                bestT = t;
                closest = {x, rect.y};
            }
        }
        {   // Check bottom
            float t = (rect.y + rect.height - y0) / dy;
            float x = x0 + dx * t;
            if (t >= 0 && t < bestT && x >= rect.x && x <= rect.x + rect.width) {
                bestT = t;
                closest = {x, rect.y + rect.height};
            }
        }
    }

    if (dx != 0.0f) {
        {   // Check left
            float t = (rect.x - x0) / dx;
            float y = y0 + dy * t;
            if (t >= 0 && t < bestT && y >= rect.y && y <= rect.y + rect.height) {
                bestT = t;
                closest = {rect.x, y};
            }
        }
        {   // Check right
            float t = (rect.x + rect.width - x0) / dx;
            float y = y0 + dy * t;
            if (t >= 0 && t < bestT && y >= rect.y && y <= rect.y + rect.height) {
                bestT = t;
                closest = {rect.x + rect.width, y};
            }
        }
    }

    if (bestT == INFINITY) {
        return std::nullopt;
    }
    return closest;
}