#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"
#include <vector>

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

    std::vector<Circle> c_vec;
    std::vector<Rectangle> r_vec;

    Rectangle r1{Vec2{50,100},Vec2{400,400}};
    Rectangle r2{Vec2{450.0,500},Vec2{700.0,650.0}};
    r_vec.push_back(r1);
    r_vec.push_back(r2);

    float r = 100;
    Circle c1{Vec2{180,220},r};
    r = 66.6;
    Circle c2{Vec2{400,400},r};
    c_vec.push_back(c1);
    c_vec.push_back(c2);


  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1{400 + 380 * std::sin(t)};
    float y1{400 + 380 * std::cos(t)};

    float x2{400 + 380 * std::sin(2.0f*t)};
    float y2{400 + 380 * std::cos(2.0f*t)};

    float x3{400 + 380 * std::sin(t-10.f)};
    float y3{400 + 380 * std::cos(t-10.f)};

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto m = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30, 30, // from
          m.first, m.second, // to
          1.0,0.0,0.0);
    }

    win.draw_line(0, m.second, 10, m.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, m.second, win.window_size().second, m.second, 0.0, 0.0, 0.0);

    win.draw_line(m.first, 0, m.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(m.first, win.window_size().second - 10, m.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string text = "mouse position: (" + std::to_string(m.first) + ", " + std::to_string(m.second) + ")";
    win.draw_text(10, 5, 35.0f, text);


    for (unsigned int i = 0; i < r_vec.size(); i++){
      if(r_vec[i].is_inside(Vec2{(float)m.first,(float)m.second}) == true){
        r_vec[i].draw(win,Color{0.0,0.0,1.0});
      }else{
        r_vec[i].draw(win);
      }
    }

    for (unsigned int i = 0; i < c_vec.size(); i++){
      if(c_vec[i].is_inside(Vec2{(float)m.first,(float)m.second}) == true){
        c_vec[i].draw(win,Color{0.0,0.0,1.0});
      }else{
        c_vec[i].draw(win);
      }
    }

    win.update();
  }

  return 0;
}
