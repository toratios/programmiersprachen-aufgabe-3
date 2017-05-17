# ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include "vec2.hpp" 
# include "mat2.hpp"
# include "color.hpp"
//# include "window.hpp"


class Circle{
    Vec2 center_;
    float r_;
    Color color_;

  public:
    Circle();
    Circle(Vec2 const& center, float r);
    Circle(Color const& col);
    Circle(Vec2 const& center, float r, Color const& col);

    Vec2 const& get_center() const;
    float get_r() const;
    Color const& get_color() const; 
    float circumference() const;
  /*void draw(Window const& win);
    void draw(Window const& win, Color const& col); */
    bool is_inside(Vec2 const& p);

    bool operator < (Circle const& c);
    bool operator > (Circle const& c);
    bool operator == (Circle const& c);
};

# endif