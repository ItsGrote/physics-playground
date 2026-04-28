#pragma once
#include<cmath>
#include<algorithm>

class Vector2D{
public:
    float x{0.f};
    float y{0.f};

    Vector2D(float x, float y){
        this->x = x;
        this->y = y;
    }

    float magnitude() const{
        return sqrt(x * x + y * y);

    }
    Vector2D normalized() const{
        float mag = magnitude();

        if (mag == 0)
            return Vector2D(0, 0);

        return Vector2D(x / mag, y / mag);
    }

    Vector2D operator+(const Vector2D& other) const{
        return Vector2D(x + other.x, y + other.y);

    }
    Vector2D operator-(const Vector2D& other) const{
        return Vector2D(x - other.x, y - other.y);

    }
    Vector2D operator*(float scalar) const{
        return Vector2D(x * scalar, y * scalar);

    }

    Vector2D clampVector(const Vector2D& v, float minMag, float maxMag){
        float mag = v.magnitude();

        if (mag == 0.f) return v;

        float clamped = std::max(minMag, std::min(mag, maxMag));
        return v.normalized() * clamped;
    }

    Vector2D clampMin(float minMag) const{
        float mag = magnitude();

        if (mag == 0.f) return *this;

        if (mag < minMag)
            return normalized() * minMag;

        return *this;
    }

};