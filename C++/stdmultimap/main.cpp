#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
#include <iterator>


class ACHistogram
{
public:
    float values[4];
    void print() const
    {
        printf("%.1f,%.1f,%.1f,%.1f \n", values[0], values[1], values[2], values[3]);
    };
  };




int main(int argc, char const *argv[])
{

    ACHistogram sampleHists[5];
    std::string keys[5] = {"a", "b", "b", "a", "a"};

    // pop samplehists
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            sampleHists[i].values[j] = i;
        }
    }


    // pop multimap

    std::unordered_multimap<std::string, ACHistogram> refHistSet;
    
    for (int i = 0; i < 5; ++i)
    {
        refHistSet.insert(std::pair<std::string, ACHistogram>(keys[i], sampleHists[i]));
    }


   std::pair<std::unordered_multimap<std::string, ACHistogram>::const_iterator, std::unordered_multimap<std::string, ACHistogram>::const_iterator> range = refHistSet.equal_range("a");


   // the following doesn't work because it assumes that the range 
   // std::pair<const std::string, ACHistogram>* ptr = &(*range.first) ;
   // int count = std::distance(range.first, range.second); // this gives correct number even if the iterators are not pointing to contiguously stored elements.
   // printf("count: %d\n",count );
   // for (int i = 0; i < count; ++i, ++ptr)
   // {
   //     (*ptr).second.print();
   //      std::cout <<  std::endl;
   // }


    std::unordered_multimap<std::string, ACHistogram>::const_iterator it;
    for (it = range.first; it != range.second; ++it)
    {
        (*it).second.print();
        std::cout <<std::endl;
    }




    return 0;
}

