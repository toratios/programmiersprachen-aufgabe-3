#include "color.hpp"

Color::Color() :
    r_{},
    g_{},
    b_{} {}

Color::Color(float r, float g, float b) :
    r_{r},
    g_{g},
    b_{b} {}

Color::Color(float col) :
    r_{col},
    g_{col},
    b_{col} {}
