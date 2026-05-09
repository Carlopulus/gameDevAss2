#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2 {
public:
  float x = 0;
  float y = 0;

  Vec2();
  Vec2(float xin, float yin);

  // Operadores matemáticos
  Vec2 operator+(const Vec2 &rhs) const;
  Vec2 operator-(const Vec2 &rhs) const;
  Vec2 operator*(float rhs) const;
  Vec2 operator/(float rhs) const;

  void operator+=(const Vec2 &rhs);
  void operator-=(const Vec2 &rhs);
  void operator*=(float val);
  void operator/=(float val);

  // Métodos de utilidad
  Vec2 &add(const Vec2 &v);
  Vec2 &scale(float s);
};

#endif
