#include "mat2.hpp"
#include <iostream>
#include <cmath>

Mat2::Mat2() :
  xx_{1.0},
  xy_{0.0},
  yx_{0.0},
  yy_{1.0} {}
  
Mat2::Mat2(float xx, float xy, float yx, float yy) :
  xx_{xx},
  xy_{xy},
  yx_{yx},
  yy_{yy} {}

Mat2& Mat2::operator *=( Mat2 const& m ) {
    float a = (xx_ * m.xx_) + (xy_ * m.yx_);
    float b = (xx_ * m.xy_) + (xy_ * m.yy_);
    float c = (yx_ * m.xx_) + (yy_ * m.yx_);
    float d = (yx_ * m.xy_) + (yy_ * m.yy_);
    xx_ = a;
    xy_ = b;
    yx_ = c;
    yy_ = d;
    return *this;
  }

float Mat2::det() const{
    return(xx_ * yy_ - xy_ * yx_);
  }

Mat2 operator *=(Mat2 const& m1, Mat2 const& m2){
    return Mat2(m1) *= m2;
  }

Vec2 operator *(Mat2 const& m, Vec2 const& v){
    Vec2 vec;
    vec.x_ = m.xx_*v.x_ + m.xy_*v.y_;
    vec.y_ = m.yx_*v.x_ + m.yy_*v.y_;
    return vec;
  }

Vec2 operator *(Vec2 const& v, Mat2 const& m){
    Vec2 vec;
    vec.x_ = m.xx_*v.x_ + m.xy_*v.y_;
    vec.y_ = m.yx_*v.x_ + m.yy_*v.y_;
    return vec;
  }

Mat2 inverse(Mat2 const& m){
    Mat2 mat;
    if(m.det() == 0){
      std::cout << "Inverse not existing.";
      return mat;
    }
    mat.xx_ = (1/m.det()) * m.yy_;
    mat.xy_ = (1/m.det()) * - m.xy_;
    mat.yx_ = (1/m.det()) * - m.yx_;
    mat.yy_ = (1/m.det()) * m.xx_;
    return mat;
  }

Mat2 transpose(Mat2 const& m){
    Mat2 mat;
    mat.xx_ = m.xx_;
    mat.xy_ = m.yx_;
    mat.yx_ = m.xy_;
    mat.yy_ = m.yy_;
    return mat;
  }

Mat2 make_rotation_mat2(float phi){
    Mat2 mat;
    mat.xx_ = cos(phi);
    mat.xy_ = -sin(phi);
    mat.yx_ = sin(phi);
    mat.yy_ = cos(phi);
    return mat; 
  }