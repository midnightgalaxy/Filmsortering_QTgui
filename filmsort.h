#ifndef FILMSORT_H
#define FILMSORT_H

#include <iostream>
#include <fstream>
#include <vector>


class Filmsort
{
public:
    Filmsort();
    ~Filmsort();
    void takeInputAndProcess(const char * adr);
    void takeOutputAndWrite(const char * adr);

private:
    std::vector<std::string> vec;
    std::ifstream *input;
    std::ofstream *output;
};

#endif // FILMSORT_H
