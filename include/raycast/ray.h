#pragma once
#include <optional>
#include <utility>
#include "raycast/rectangle.h"

// A ray starting at (x0, y0) travelling in direction (dx, dy).
// If the direction is normalized, t values equal real distances.
class Ray {
public:
    Ray(float x0, float y0, float dx, float dy);

    // Returns the nearest point where the ray hits the rectangle's edges,
    // or std::nullopt if it misses.
    std::optional<std::pair<float, float>> getIntersectPoint(const Rectangle& rect) const;

private:
    float x0;
    float y0;
    float dx;
    float dy;
};