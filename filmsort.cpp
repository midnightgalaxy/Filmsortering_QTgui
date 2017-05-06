#include "filmsort.h"

Filmsort::Filmsort()
{
    input = 0;
    output = 0;
}

Filmsort::~Filmsort()
{
    delete input;
    delete output;
}

void Filmsort::takeInputAndProcess(const char * adr)
{
    input = new std::ifstream(adr);
    std::string temp;
    // fill vector
    while (std::getline(*input, temp))
    {
        // set first letter to a capital if not
        if (islower(temp[0]))
            temp[0] = toupper(temp[0]);

        std::string temp2 = temp;

        // add a couple of search strings as well
        temp += ":\n    https://thepiratebay.org/search/";
        temp += temp2;
        temp += "\n    http://www.filmtipset.se/search.cgi?search_value=";
        temp += temp2;
        temp += "\n";

        vec.push_back(temp);
    }

    input->close();

    // sort vector, just sort by the first letter only
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i+1; j < vec.size(); j++)
        {
            if (vec.at(j)[0] < vec.at(i)[0]) {
                std::string temp = vec.at(j);
                vec.at(j) = vec.at(i);
                vec.at(i) = temp;
            }
        }
    }
}

void Filmsort::takeOutputAndWrite(const char * adr)
{
    output = new std::ofstream(adr);
    for (int i = 0; i < vec.size(); i++)
            *output << vec.at(i) << "\n";

    output->close();
}
