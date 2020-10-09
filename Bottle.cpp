#include "Bottle.hpp"

std::ostream &operator<<(std::ostream &out,const Bottle& bot){ //перегрузка << 
    out << "{" << std::endl << "\tvolume: " << bot.a << std::endl << "\tpercentage of filling: "  << bot.b << std::endl << "}" << std::endl;
    return out;
}

std::istream &operator>>(std::istream &in, Bottle& bot){//перегрузка >>
    std::string volume, filling;
    std::string::size_type ptr1;
    std::string::size_type ptr2;
    std::cout << "Enter volume: ";
    std::cin >> volume;//считали строку с объемом
    std::cout << "Enter percentage of filling: ";
    std::cin >> filling;//считали строку с наполненностью
    bot.a = std::stod('0' + volume, &ptr1); //"достали" объем из строки (по умолчанию 0)
    bot.b = std::stod('0' + filling, &ptr2);//"достали" наполненность из строки (по умолчанию 0)
    return in;
}

bool operator==(const Bottle& lhv,const Bottle& rhv){//перегрузка ==
    return lhv.a * lhv.b == rhv.a * rhv.b;
}

bool operator<(const Bottle& lhv,const Bottle& rhv){//перегрузка <
    return lhv.a * lhv.b < rhv.a * rhv.b;
}

bool operator>(const Bottle& lhv,const Bottle& rhv){//перегрузка >
    return lhv.a * lhv.b > rhv.a * rhv.b;
}

Bottle operator+(const Bottle& lhv,const Bottle& rhv){//перегрузка +
    return Bottle( lhv.a + rhv.a, (lhv.a * lhv.b + rhv.a * rhv.b)/(lhv.a + rhv.a));
}

Bottle operator-(const Bottle& lhv,const Bottle& rhv){//перегрузка -
    if (lhv > rhv)
    return Bottle(lhv.a + rhv.a, (lhv.a * lhv.b - rhv.a * rhv.b)/(lhv.a + rhv.a));
    
    return Bottle(lhv.a + rhv.a, (rhv.a * rhv.b - lhv.a * lhv.b)/(lhv.a + rhv.a));
}
