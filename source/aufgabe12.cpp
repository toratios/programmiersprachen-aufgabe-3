#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "circle.hpp"


TEST_CASE("copy_Circle", "[copy]")
{
  std::vector<Circle> circles{{5.0f},{3.0f},{8.0f},{1.0f},{5.0f}};
  std::vector<Circle> circles_filter(circles.size());

  auto it = std::copy_if(circles.begin(), circles.end(), circles_filter.begin(), [](Circle a){return a > 4.0f;});
  circles_filter.resize(std::distance(circles_filter.begin(),it));
  REQUIRE(std::all_of(circles_filter.begin(), circles_filter.end(), [](Circle a){return a > 3.0f;}));
}

int main(int argc, char* argv [])
{
    return Catch::Session().run(argc, argv);
}