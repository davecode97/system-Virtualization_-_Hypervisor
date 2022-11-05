#include <iostream>

class Instructions
{
    private:
    std::string pathOsImage;

    public:
        void createVM();
        void memorySettingUpVM();
        void createDiskWithISO();
        void enableRDP();
        void startVM();
};