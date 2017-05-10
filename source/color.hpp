# ifndef COLOR_HPP
# define COLOR_HPP

// Color class definition
struct Color
{
    float r_;
    float g_;
    float b_;

    Color();
    Color(float r, float g, float b);
    Color(float col);
};

# endif // COLOR_HPP