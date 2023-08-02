#include <iostream>

// cout cin
/*
int main()
{
    std::string name;

    std::cout << "what is your name?" << std::endl;
    std::cin >> name;
    // std::getline(std::cin, name);
    std::cout << "Hello Mr " << name << std::endl;
    std::cout << "what is your favorate food?" << std::endl;
    std::cin >> name;
    // std::getline(std::cin, name);
    std::cout << "oh my.. i love " << name << "too... yum yum" << std::endl;
}*/

#include <sstream>
// #include <string>
int main()
{
    std::string tmp;
    float   price;
    int     cnt;

    std::cout << "Enter price: ";
    std::getline(std::cin, tmp);
    std::stringstream(tmp) >> price;
    std::cout << "price = " << price << std::endl;

    std::cout << "Enter quantity: ";
    std::getline(std::cin, tmp);
    std::stringstream(tmp) >> cnt;
    std::cout << "quantity = " << cnt << std::endl;

    std::cout << "Total price: " << price * cnt << std::endl;
    return 0;
}