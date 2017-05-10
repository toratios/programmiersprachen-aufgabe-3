# include "rectangle.hpp"

Rectangle::Rectangle() :
    min_{Vec2{0.0,0.0}},
    max_{Vec2{1.0,1.0}},
    color_{Color{}} {}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max) :
    min_{min},
    max_{max},
    color_{Color{}} {}

Rectangle::Rectangle(Color const& col) :
    min_{Vec2{0.0,0.0}},
    max_{Vec2{1.0,1.0}},
    color_{col} {}

Rectangle::Rectangle(Vec2 const& min, Vec2 const& max, Color const& col) :
    min_{min},
    max_{max},
    color_{col} {}

Vec2 const& Rectangle::get_min(){
    return this->min_;
}

Vec2 const& Rectangle::get_max(){
    return this->max_;
}

float Rectangle::circumference() const{
    float a = 0;
    float b = 0;

    if(this->max_.x_>this->min_.x_){
        a = this->max_.x_-this->min_.x_;
    }else{
        a = this->min_.x_-this->max_.x_;
    }
    if(this->max_.y_>this->min_.y_){
        b = this->max_.y_-this->min_.y_;
    }else{
        b = this->min_.y_-this->max_.y_;
    }
    return (a)*2+(b)*2;
}

void Rectangle::draw(Window const& win){
    win.draw_line(min_.x_,min_.y_,max_.x_,min_.y_,color_.r_,color_.g_,color_.b_);
    win.draw_line(min_.x_,min_.y_,min_.x_,max_.y_,color_.r_,color_.g_,color_.b_);
    win.draw_line(min_.x_,max_.y_,max_.x_,max_.y_,color_.r_,color_.g_,color_.b_);
    win.draw_line(max_.x_,min_.y_,max_.x_,max_.y_,color_.r_,color_.g_,color_.b_);
}

void Rectangle::draw(Window const& win, Color const& col){
    win.draw_line(min_.x_,min_.y_,max_.x_,min_.y_,col.r_,col.g_,col.b_);
    win.draw_line(min_.x_,min_.y_,min_.x_,max_.y_,col.r_,col.g_,col.b_);
    win.draw_line(min_.x_,max_.y_,max_.x_,max_.y_,col.r_,col.g_,col.b_);
    win.draw_line(max_.x_,min_.y_,max_.x_,max_.y_,col.r_,col.g_,col.b_);
}

bool Rectangle::is_inside(Vec2 const& p){
    float xmax = max_.x_;
    float ymax = max_.y_;
    float xmin = min_.x_;
    float ymin = min_.y_;

    if(xmax < xmin){
        xmax = min_.x_;
        xmin = max_.x_;
    }
    if(ymax < ymin){
        ymax = min_.y_;
        ymin = max_.y_;
    };
    if(xmax >= p.x_ && xmin <= p.x_ && ymax >= p.y_ && ymin <= p.y_){
        return true;
    }else{
        return false;
    }
}