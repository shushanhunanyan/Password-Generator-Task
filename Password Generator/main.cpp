#include "PasswordGenerator.h"
#include "FileManager.h"

#include <iostream>

int main()
{
        Generator pass;

        for (size_t i = 0; i < 5; ++i) {
                pass.WriteToFile("generatedPassword․txt", pass.GeneratePassword());
        }

        pass.Compare("commonPassword.txt", "generatedPassword․txt");

}

