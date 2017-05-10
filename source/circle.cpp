#include "circle.hpp"
#include <cmath>


Circle::Circle() :
    center_{Vec2{1.0,1.0}},
    r_{1.0},
    color_{Color{}} {}

Circle::Circle(Vec2 const& center, float r) :
    center_{center},
    r_{r},
    color_{Color{}} {}

Circle::Circle(Color const& col) :
    center_{Vec2{1.0,1.0}},
    r_{1.0},
    color_{col} {}

Circle::Circle(Vec2 const& center, float r, Color const& col) :
    center_{center},
    r_{r},
    color_{col} {}

Vec2 const& Circle::get_center() const{
    return this->center_;
}

float Circle::get_r() const{
    return this->r_;   
}

Color const& Circle::get_color() const{
    return this->color_;
}

float Circle::circumference() const{
    float circ = 2*M_PI*this->r_;
    return circ;
}

void Circle::draw(Window const& win){
    Vec2 rad1{r_,0.0};
    Vec2 rad2{rad1};
    Mat2 m = make_rotation_mat2(M_PI/180);
    for (float i = 1; i<=360; i++){
        rad1 += center_;
        rad2 = m*rad2;
        rad2 += center_;
        win.draw_line(rad1.x_,rad1.y_,rad2.x_,rad2.y_,color_.r_,color_.g_,color_.b_);
        rad2 -= center_;
        rad1 = rad2;
    }
}

void Circle::draw(Window const& win, Color const& col){
    Vec2 rad1{r_,0.0};
    Vec2 rad2{rad1};
    Mat2 m = make_rotation_mat2(M_PI/180);
    for (float i = 1; i<=360; i++){
        rad1 += center_;
        rad2 = m*rad2;
        rad2 += center_;
        win.draw_line(rad1.x_,rad1.y_,rad2.x_,rad2.y_,col.r_,col.g_,col.b_);
        rad2 -= center_;
        rad1 = rad2;
    }
}

bool Circle::is_inside(Vec2 const& p){
    float a = p.x_ - center_.x_;
    float b = p.y_ - center_.y_;
    float c = sqrt(pow(a,2)+pow(b,2));
    if (r_ >= c){
        return true;
    }else{
        return false;
    }
} 