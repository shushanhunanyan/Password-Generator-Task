#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H


#include "FileManager.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>


class Generator : public FileManager
{
public:
	Generator() = default;
	~Generator() = default;

        std::string GeneratePassword(); 
private:
        char GenerateUppercase();
        char GenerateLowercase();
        char GenerateSpecialSymbol();
	char GenerateDigit();

private:
	const size_t password_size = 12;
};


#endif // PASSWORDGENERATOR_H
