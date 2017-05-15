#include <vector>   // std::vector<>
#include <list>     // std::list<>
#include <cstdlib>  // std::rand()
#include <iostream> // std::cout
#include <iterator> // std::ostream_iterator<>
#include <set>      // std::set<>
#include <map>      // std::map<>

int main ()
{
  std::list<unsigned int> l0(100);
  for(auto& l : l0){
    l = std::rand() %101;
  }
  
  std::vector<unsigned int> v0(l0.size());
  std::copy(std::begin(l0), std::end(l0), std::begin(v0));

  //std::copy(std::begin(l0), std::end(l0), 
  //  std::ostream_iterator <unsigned int>(std::cout, "\n")); 

  std::set<unsigned int> s0;
  for(auto& l : l0){
    s0.insert(l);
  }

  std::set<unsigned int> s1;
  for(int i = 0; i <= 100; ++i){
    s1.insert(i);
  }

  for(auto& s : s0){
    s1.erase(s1.find(s));
  }

  std::copy(std::begin(s0), std::end(s0), 
    std::ostream_iterator <unsigned int>(std::cout, "\n")); 
  
  std::cout << "Number of elements in s0: " << s0.size() << "\n";

  std::copy(std::begin(s1), std::end(s1), 
  std::ostream_iterator <unsigned int>(std::cout, "\n")); 

  std::map<unsigned int, unsigned int> m0;
  for(auto& l : l0){
    m0[l] += 1;   
  }

  for(auto& m : m0){
    std::cout << m.first << ":" << m.second << "\n"; 
  }

}