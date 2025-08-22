#include <iostream>
#include <unitree/common/string_tool.hpp>
#include <unitree/common/time/time_tool.hpp>
using namespace unitree::common;
// using namespace unitree;

int main() {
    int32_t xt = Compare("Hello", "World");
    std::cout<< xt << std::endl;
    time_t currentTime = GetCurrentTimeNanosecond();
    std::cout << "Current time: " << currentTime << std::endl;
    std::cout<< "Hello, World 02!" << std::endl;
    return 0;
}
