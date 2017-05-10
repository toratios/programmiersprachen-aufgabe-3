# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

# include "vec2.hpp"
# include "color.hpp"
# include "window.hpp"

class Rectangle{
    Vec2 min_;
    Vec2 max_;
    Color color_;

  public:
    Rectangle();
    Rectangle(Vec2 const& min, Vec2 const& max);
    Rectangle(Color const& col);
    Rectangle(Vec2 const& min, Vec2 const& max, Color const& col);

    Vec2 const& get_max();
    Vec2 const& get_min();
    Color const& get_color();
    float circumference() const;
    void draw(Window const& win);
    void draw(Window const& win, Color const& col);
    bool is_inside(Vec2 const& p);
};

# endif