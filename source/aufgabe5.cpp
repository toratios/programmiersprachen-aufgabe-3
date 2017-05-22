#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>


bool is_multiple_of_3(unsigned int x){
  if(x % 3 == 0){
    return true;
  }
  else{
    return false;
  }
}

bool is_not_multiple_of_3(unsigned int x){
  return !is_multiple_of_3(x);
}

TEST_CASE("filter alle vielfache von drei", "[erase]")
{
  std::vector<unsigned int> v(100);
  for(auto& vit : v){
    vit = std::rand() %101;
  }
  v.erase(std::remove_if(v.begin(), v.end(), is_not_multiple_of_3), v.end());

  std::copy(std::begin(v), std::end(v), 
    std::ostream_iterator <unsigned int>(std::cout, "\n")); 

REQUIRE(std::all_of(v.begin(), v.end(), is_multiple_of_3));
}

int main(int argc, char * argv[])
{
    return Catch::Session().run(argc, argv);
}