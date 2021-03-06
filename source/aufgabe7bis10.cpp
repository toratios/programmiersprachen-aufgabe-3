#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "circle.hpp"


TEST_CASE("Vergleichsoperator für Circle", "[operator]")
{
  std::vector<Circle> vec_c(10);

  for(auto& c : vec_c){
    c = Circle{Vec2 {0,0},float(std::rand()%100)};
  }

  std::sort (vec_c.begin(), vec_c.end());  
 
  REQUIRE(std::is_sorted(vec_c.begin(), vec_c.end()));
}

TEST_CASE("Lamdbda sort","[sort]")
{
  std::vector<Circle> vec_c(10);

  for (auto& c : vec_c){
    c = Circle{Vec2 {0,0},float(std::rand()%100)};
  }

  std::sort(vec_c.begin(), vec_c.end(), [](Circle& a, Circle& b){return a < b;});

  REQUIRE(std::is_sorted(vec_c.begin(), vec_c.end()));
}

TEST_CASE("Lambda Addition","[add]"){

  std::vector<int> v1{1,2,3,4,5,6,7,8,9};
  std::vector<int> v2{9,8,7,6,5,4,3,2,1};
  std::vector<int> v3(9);

  std::transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),[](int a,int b){return a + b;});

  REQUIRE(std::all_of(v3.begin(), v3.end(), [](int a){return a == 10;}));
}

bool is_even(int n){
  return n % 2 == 0;
  }


template <typename Container, typename Praedikat>
Container filter(Container const& cont, Praedikat const& pr){
	Container res_cont;
	for (auto& c : cont) {
		if(pr(c)){
			res_cont.push_back(c);
		}
	}
	return res_cont;
}


TEST_CASE("filter alle ungeraden", "[filter]")
{
  std::vector<int> v{1,2,3,4,5,6};
  std::vector<int> alleven = filter(v,is_even); 

  REQUIRE(std::all_of(alleven.begin(), alleven.end(), is_even));
}


int main(int argc, char * argv[])
{
    return Catch::Session().run(argc, argv);
}