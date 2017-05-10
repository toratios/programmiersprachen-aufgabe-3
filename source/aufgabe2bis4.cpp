#include <vector>       // std::vector<>
#include <list>         // std::list<>
#include <cstdlib>      // std::rand()
#include <iostream>     // std::cout
#include <iterator>     // std::ostream_iterator<>

int main ()
{
    std::list<unsigned int> l0(100);
    for(auto& l : l0){
        l = std::rand() %101;
    }
    std::vector<unsigned int> v0(l0.size());
    std::copy(std::begin(l0), std::end(l0), std::begin(v0));

    std::copy(std::begin(l0), std::end(l0), std::ostream_iterator <unsigned int>(std::cout, "\n"));   
}