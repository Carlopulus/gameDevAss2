#if INTERFACE

class Vec2 {
public:
  float x = 0;
  float y = 0;

  Vec2();

  Vec2(float xin, float yin) : x(xin), y(yin) {}

  Vec2 operator+(const Vec2 &rhs) const { return Vec2(x + rhs.x, y + rhs.y); }

  Vec2 operator-(const Vec2 &rhs) const { return Vec2(x - rhs.x, y - rhs.y); }

  Vec2 operator*(float rhs) { return Vec2(x * rhs, y * rhs); }

  Vec2 operator/(float rhs) { return Vec2(x / rhs, y / rhs); }

  void operator+=(const Vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
  }

  void operator-=(const Vec2 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
  }

  void operator*=(float val) {
    x = x * val;
    y = y * val;
  }

  void operator/=(float val) {
    x = x / val;
    y = y / val;
  }

  Vec2 &add(const Vec2 &v) {
    x += v.x;
    y += v.y;
    return *this;
  }

  Vec2 &scale(float s) {
    x *= s;
    y *= s;
    return *this;
  }
};

#endif
