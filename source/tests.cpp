#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "color.hpp"

TEST_CASE ("default_constructor_vec2", "[vec2]")
{
  Vec2 v2;
  REQUIRE (v2.x_ == 0.0);
  REQUIRE (v2.y_ == 0.0);
}

TEST_CASE ("user_constructor_vec2", "[vec2 ]")
{
  Vec2 v(5.0,-5.0);
  REQUIRE (v.x_ == 5.0);
  REQUIRE (v.y_ == -5.0);
}

TEST_CASE ("vec2&_+=_operator", "[vec2]")
{
  Vec2 v(4.0,4.5);
  Vec2 u(0.0,-8.0);
  v += u;
  REQUIRE(v.x_ == 4.0);
  REQUIRE(v.y_ == -3.5);
}

TEST_CASE ("vec2&_-=_operator", "[vec2]")
{
  Vec2 v(4.0,4.5);
  Vec2 u(0.0,-8.0);
  v -= u;
  REQUIRE(v.x_ == 4.0);
  REQUIRE(v.y_ == 12.5);
}

TEST_CASE ("vec2&_*=_operator", "[vec2]")
{
  Vec2 v(4.0,4.5);
  float s = 2.0;
  v *= s;
  REQUIRE(v.x_ == 8.0);
  REQUIRE(v.y_ == 9.0);
  s = -1.0;
  v *= s;
  REQUIRE(v.x_ == -8.0);
  REQUIRE(v.y_ == -9.0);
  s = 0.0;
  v *= s;
  REQUIRE(v.x_ == 0.0);
  REQUIRE(v.y_ == 0.0);
}

TEST_CASE ("vec2&_/=_operator", "[vec2]")
{
  Vec2 v(4.0,4.5);
  float s = 2.0;
  v /= s;
  REQUIRE(v.x_ == 2.0);
  REQUIRE(v.y_ == 2.25);
  s = 0;
  v /= s;
  REQUIRE(v.x_ == 0.0);
  REQUIRE(v.y_ == 0.0);
}

TEST_CASE ("default_constructor_mat2", "[mat2]")
{
  Mat2 m;
  REQUIRE (m.xx_ == 1.0);
  REQUIRE (m.yx_ == 0.0);
  REQUIRE (m.xy_ == 0.0);
  REQUIRE (m.yy_ == 1.0);
}

TEST_CASE ("user_constructor_mat2", "[mat2]")
{
  Mat2 m(5.0,6.0,-9.4,0.0);
  REQUIRE (m.xx_ == 5.0f);
  REQUIRE (m.xy_ == 6.0f);
  REQUIRE (m.yx_ == -9.4f);
  REQUIRE (m.yy_ == 0.0f);
}

TEST_CASE ("mat2&_*=_operator", "[mat2]")
{
  Mat2 m(1.0,2.0,3.0,4.0);
  m *= m;
  REQUIRE (m.xx_ == 7.0f);
  REQUIRE (m.xy_ == 10.0f);
  REQUIRE (m.yx_ == 15.0f);
  REQUIRE (m.yy_ == 22.0f);
}

TEST_CASE ("det_mat2", "[mat2]")
{
  Mat2 m(1.0, 3.0, 3.0, 1.0);
  REQUIRE (m.det() == -8.0);
  Mat2 n(5.0, 3.0, 5.0, 3.0);
  REQUIRE (n.det() == 0.0);
}

TEST_CASE ("mat2_*_vec2_operator", "[mat2]")
{
  Mat2 m(1.0,2.0,3.0,4.0);
  Vec2 v(2.0,-1.0);
  Vec2 n;
  n = m * v;
  REQUIRE (n.x_ == 0.0f);
  REQUIRE (n.y_ == 2.0f);
  n = v * m;
  REQUIRE (n.x_ == 0.0f);
  REQUIRE (n.y_ == 2.0f);
}

TEST_CASE ("inverse_mat2", "[mat2]")
{
  Mat2 m(1.0, 2.0, 3.0, 4.0);
  Mat2 n = inverse(m);
  REQUIRE (n.xx_ == -2.0);
  REQUIRE (n.xy_ == 1.0);
  REQUIRE (n.yx_ == 1.5);
  REQUIRE (n.yy_ == -0.5);
}

TEST_CASE ("transpose_mat2", "[mat2]")
{
  Mat2 m(1.0, 2.0, 3.0, 4.0);
  Mat2 n = transpose(m);
  REQUIRE (n.xx_ == 1.0);
  REQUIRE (n.xy_ == 3.0);
  REQUIRE (n.yx_ == 2.0);
  REQUIRE (n.yy_ == 4.0);
}

TEST_CASE ("make_rotation_mat2", "[mat2]")
{
  float s = M_PI/2;
  Mat2 m = make_rotation_mat2(s);
  REQUIRE (m.xx_ == Approx(0.0).epsilon(0.001));
  REQUIRE (m.xy_ == Approx(-1.0).epsilon(0.001));
  REQUIRE (m.yx_ == Approx(1.0).epsilon(0.001));
  REQUIRE (m.yy_ == Approx(0.0).epsilon(0.001));
}

TEST_CASE ("default_constructor_color", "[color]")
{
  Color c(0.0);
  REQUIRE(c.r_ == 0.0);
  REQUIRE(c.g_ == 0.0);
}

TEST_CASE ("default_constructor_circle", "[circle]")
{
  Circle c;
  Vec2 center = c.get_center();
  REQUIRE(center.x_ == 1.0);
  REQUIRE(center.y_ == 1.0);
}

TEST_CASE ("default_constructor_rectangle", "[rectangle]")
{
  Rectangle r;
  Vec2 max = r.get_max();
  Vec2 min = r.get_min();
  REQUIRE (max.x_ == 1.0);
  REQUIRE (max.y_ == 1.0);
  REQUIRE (min.x_ == 0.0);
  REQUIRE (min.y_ == 0.0);
}

TEST_CASE ("circumference_rectangle", "[rectangle]")
{
  Rectangle r(Vec2{0.0,0.0},Vec2{5.0,-8.0});
  REQUIRE (r.circumference() == 26);
}

TEST_CASE ("circumference_circle", "[circle]")
{
  Circle c;
  REQUIRE (c.circumference() == Approx(2*M_PI).epsilon(0.001));
}

TEST_CASE ("is_inside_rectangle", "[rectangle]")
{
  Rectangle r{Vec2{10,0},Vec2{0.0,10}};
  Vec2 p1{8,8};
  Vec2 p2{28,29};
  Vec2 p3{5,10};
  REQUIRE (r.is_inside(p1) == true);
  REQUIRE (r.is_inside(p3) == true);
  REQUIRE (r.is_inside(p2) == false);
}

TEST_CASE ("is_inside_circle", "[circle]")
{
  Circle c{Vec2{10,10},5};
  Vec2 p1{8,8};
  Vec2 p2{28,29};
  Vec2 p3{15,10};
  REQUIRE (c.is_inside(p1) == true);
  REQUIRE (c.is_inside(p3) == true);
  REQUIRE (c.is_inside(p2) == false);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
