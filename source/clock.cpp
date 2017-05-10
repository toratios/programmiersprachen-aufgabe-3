#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "circle.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    float t = win.get_time()+(3600*0); 

    Vec2 center{400,350};

    Circle clock{center, 300, Color{0.0,0.8,1.0}};

    clock.draw(win); 

    Vec2 line12a{400,50};
    Vec2 line12i{400,100};
    Vec2 line3a{700,350};
    Vec2 line3i{650,350};
    Vec2 line6a{400,650};
    Vec2 line6i{400,600};
    Vec2 line9a{100,350};
    Vec2 line9i{150,350};

    win.draw_line(line12a.x_,line12a.y_,line12i.x_,line12i.y_,0.0,0.8,1.0);
    win.draw_line(line3a.x_,line3a.y_,line3i.x_,line3i.y_,0.0,0.8,1.0);
    win.draw_line(line6a.x_,line6a.y_,line6i.x_,line6i.y_,0.0,0.8,1.0);
    win.draw_line(line9a.x_,line9a.y_,line9i.x_,line9i.y_,0.0,0.8,1.0);

    Vec2 s{(float)sin((2*t*M_PI)/60)*280,(float)-cos((2*t*M_PI)/60)*280};
    Vec2 m{(float)sin((2*t*M_PI)/3600)*240,(float)-cos((2*t*M_PI)/3600)*240};
    Vec2 h{(float)sin((2*t*M_PI)/(43200))*200,(float)-cos((2*t*M_PI)/(43200))*200};

    s += center;
    m += center;
    h += center;

    win.draw_line(center.x_,center.y_,s.x_,s.y_,1.0,0.0,0.0);
    win.draw_line(center.x_,center.y_,m.x_,m.y_,0.0,1.0,0.0);
    win.draw_line(center.x_,center.y_,h.x_,h.y_,1.0,0.5,1.0);

    
    std::string text = "time: " + std::to_string((int)t/3600 %24) + ":" 
    + std::to_string((int)t/60 %60) + ":" + std::to_string((int)t%60);
    win.draw_text(10, 5, 35.0f, text);
  
    win.update();
  }

  return 0;
}