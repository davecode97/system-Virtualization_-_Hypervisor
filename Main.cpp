#include <string>
#include <iostream>
#include <stdlib.h>
#include<cstdlib>
#include "Instructions.hpp"

using namespace std;
int main(int argc, char* argv[]) 
{
    Instructions instructions;

    instructions.createVM();
    instructions.memorySettingUpVM();
    instructions.createDiskWithISO();
    instructions.enableRDP();
    instructions.startVM();


    return 0; 
}
