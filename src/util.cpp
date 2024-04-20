#include <util.hpp>

Util::Util()
{
}

Util::~Util()
{
}

void Util::print(std::string string, const sf::Vector2f& v1) 
{
    std::cout << string << " " << v1.x << ", " << v1.y << std::endl;
}

void Util::print(std::string string, const float& f) 
{  
    std::cout << string << " " << f << std::endl;
}

void Util::print(std::string string) 
{  
    std::cout << string << std::endl;
}