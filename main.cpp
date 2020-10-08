//Ермакова Анна
//М80-201Б-19
//Создать класс Bottle для работы с емкостями. Класс должен состоять из двух вещественных чисел: a- объем емкости в литрах и b – процент наполнения емкости (0 – пустая, 1 – полная). Реализовать операции сложения и вычитания, а также сравнения объектов класса бутылка в виде перегрузки операторов. При сложении должен складываться фактический объем заполнения бутылок.
//Необходимо реализовать пользовательский литерал для работы с константами типа Bottle.

#include "Bottle.hpp" //библиотека с объявлением класса
#include <fstream> //библиотека для работы с файлами
#include <iostream> //библиотека для работы с файлами

#define UNUSED(value) (void)value

Bottle operator "" _bot(const char *bot, size_t){ //реализация пользовательского литерала - преобразует строку вида "34.7 0.65" в элмент класса Bottle
    char * sz;
    double a = strtod(bot,&sz); //"достали" первое число - объем
    double b = strtod(sz,nullptr); //"достали" второе число - заполненность
    
    return Bottle(a, b);
}

int main(int argc, char** argv) {
    
    std::ifstream f("test.txt");
    if (!f.is_open()){ // если файл не открыт
        std::cout << "error!\n"; // сообщить об этом
        return 0;}
        
    double n = 0;
  
    std::cout << "the form to enter the expression: 10 0.6 + 5 0.2 (value1 filling1 operation value2 filling2)" << std::endl;
    
    while(n == 0){
        //цикл для неоднокраного использования меню в ходе работы программы
       
        int r = 0;
        std::cout << "Enter the expression" << std::endl;
        
        const char *SEP = "\n "; //разделители
        const int N = 256;  //максимальная длина слова
        char str[N];
        f.getline(str, N); //считали строку в стр
        std::cout << str << std::endl;
        char *ptr = 0;
        ptr = strtok(str,SEP); // первое слово из строки
        std::string x1,y1,x2,y2; //х1 - объем первой бутылки, х2 - второй, у1 - наполненность первой бутылки, у2 - второй
        char *z = 0;
       
        if (ptr){                //если (ptr != NULL)
            x1 = ptr;
            ptr = strtok(0,SEP);   //Подбираем слово
        }
        
        if (ptr){                //если (ptr != NULL)
            y1 = ptr;
            ptr = strtok(0,SEP);   //Подбираем слово
        }
        
        if (ptr){                //если (ptr != NULL)
            z = ptr;
            ptr = strtok(0,SEP);   //Подбираем слово
        }
        else {r = 1 ;std::cout << "Try again" << std::endl;}
        
        if (ptr){                //если (ptr != NULL)
            x2 = ptr;
            ptr = strtok(0,SEP);   //Подбираем слово
        }
        
        if (ptr){                //если (ptr != NULL)
            y2 = ptr;
            ptr = strtok(0,SEP);   //Подбираем слово
        }
        
        std::string::size_type ptr1,ptr2,ptr3,ptr4;
        double a1 = std::stod('0' + x1, &ptr1); //достаем вещественное число из х1 (по умолчанию 0)
        double b1 = std::stod('0' + y1, &ptr2); //достаем вещественное число из у1 (по умолчанию 0)
        double a2 = std::stod('0' + x2, &ptr3); //достаем вещественное число из х2 (по умолчанию 0)
        double b2 = std::stod('0' + y2, &ptr4); //достаем вещественное число из у2 (по умолчанию 0)
        
        Bottle bot1(a1,b1), bot2(a2,b2);
        
        if (r != 1)
        switch(*z){
            //меню в соответсвии с введенным пользователем выражением
            
            case '+':
            std::cout << "Result: " << bot1 + bot2 << std::endl;
            break;
            
            case '-':
            std::cout << "Result: " << bot1 - bot2 << std::endl;
            break;
            
            case '=':
            if (bot1 == bot2)
            std::cout << "true" << std::endl;
            else
            std::cout << "false" << std::endl;
            break;
            
            case '>':
            if (bot1 > bot2)
            std::cout << "true" << std::endl;
            else
            std::cout << "false" << std::endl;
            break;
            
            case '<':
            if (bot1 < bot2)
            std::cout << "true" << std::endl;
            else
            std::cout << "false" << std::endl;
            break;
            
            default:
            std::cout << "Try again" << std::endl;
            break;
            
        }
        
        std::cout << "If you dont want to continue, enter 1 (else - 0): " ; //условие выхода
        char arr[N];
        f.getline(arr, N); //считали строку в стр
        char *ptrr = 0;
        ptrr = strtok(arr,SEP); // первое слово из строки
        std::string::size_type p = 0;
        std::string l = ptrr;
        n = std::stod('0' + l, &p); //достаем вещественное число из х1 (по умолчанию 0)
        std::cout << n << std::endl;

    }
    
    Bottle bot3;
    bot3 = "1.6 0.25"_bot;//демонстрация использования пользовательского литерала
    std::cout << "Example of using literal: " << std::endl << "Bottl3: " << bot3;
    
    UNUSED(argc);
    UNUSED(argv);
    return 0;
}
