#include "Instructions.hpp"
using namespace std;


void Instructions::createVM() {
    cout<<"#----  Create VM  ------\n"<<endl;
    cout<<"###   Command Executing: " <<"VBoxManage createvm --name linuxLite --ostype \"Other_64\" --register --basefolder ~/Documents ###\n" << endl;
    system("VBoxManage createvm --name linuxLite --ostype \"Ubuntu_64\" --register --basefolder ~/Documents");

    cin.get();
}

void Instructions::memorySettingUpVM() 
{
    cout<< "#------ Set memory and network -------\n" << endl;
    cout<<"###   Command Executing: " << "VBoxManage modifyvm linuxLite --ioapic on ###\n"<<endl;
    system("VBoxManage modifyvm linuxLite --ioapic on");
    cin.get();

    cout<<"###   Command Executing: " << "VBoxManage modifyvm linuxLite --memory 4096 --vram 256 ###\n"<<endl;
    system("VBoxManage modifyvm linuxLite --memory 4096 --vram 256");
    cin.get();

    cout<<"###   Command Executing: " << "VBoxManage modifyvm linuxLite --nic1 nat ###\n"<<endl;
    system("VBoxManage modifyvm linuxLite --nic1 nat");
    cin.get();
}


void Instructions::createDiskWithISO() 
{
    cout<< "#------ Create Disk and connect Debian Iso-------\n" << endl;
    cout<<"###   Command Executing: " << "VBoxManage createhd --filename ~/Documents/linuxLite/linuxLite.vdi --size  28540 --format VDI ###\n"<<endl;
    system("VBoxManage createhd --filename ~/Documents/linuxLite/linuxLite.vdi --size  28540 --format VDI");
    cin.get();

    cout<<"###   Command Executing: " << "VBoxManage storagectl linuxLite --name \"SATA Controller\" --add sata --controller IntelAhci  ###\n"<<endl;
    system("VBoxManage storagectl linuxLite --name \"SATA Controller\" --add sata --controller IntelAhci");    
    cin.get();

    cout<<"###   Command Executing: " << "VBoxManage storageattach linuxLite --storagectl \"SATA Controller\" --port 0 --device 0 --type hdd --medium  ~/Documents/linuxLite/linuxLite.vdi  ###\n"<<endl;
    system("VBoxManage storageattach linuxLite --storagectl \"SATA Controller\" --port 0 --device 0 --type hdd --medium  ~/Documents/linuxLite/linuxLite.vdi");    
    cin.get();

    cout<<"###   Command Executing: " << "VBoxManage storagectl linuxLite --name \"IDE Controller\" --add ide --controller PIIX4  ###\n"<<endl;
    system("VBoxManage storagectl linuxLite --name \"IDE Controller\" --add ide --controller PIIX4");    
    cin.get();


    cout<<"###   Command Executing: " << "VBoxManage storageattach linuxLite --storagectl \"IDE Controller\" --port 1 --device 0 --type dvddrive --medium ~/Documents/linux-lite-6.0-64bit.iso  ###\n"<<endl;
    system("VBoxManage storageattach linuxLite --storagectl \"IDE Controller\" --port 1 --device 0 --type dvddrive --medium ~/Documents/linux-lite-6.0-64bit.iso");    
    cin.get();

    cout<<"###   Command Executing: " << "VBoxManage modifyvm linuxLite --boot1 dvd --boot2 disk --boot3 none --boot4 none ###\n"<<endl;
    system("VBoxManage storageattach linuxLite --storagectl \"IDE Controller\" --port 1 --device 0 --type dvddrive --medium ~/Documents/linux-lite-6.0-64bit.iso");    
    cin.get();

}

void Instructions::enableRDP() 
{
    cout<< "#------  Enable RDP  -------\n" << endl;
    cout<<"###   Command Executing: " << "VBoxManage modifyvm linuxLite  --vrde on ###\n"<<endl;
    system("VBoxManage modifyvm linuxLite  --vrde on");
    cin.get();

    cout<<"###   Command Executing: " << "VBoxManage modifyvm linuxLite --vrdemulticon on --vrdeport 10001 ###\n"<<endl;
    system("VBoxManage modifyvm linuxLite --vrdemulticon on --vrdeport 10001");
    cin.get();
}

void Instructions::startVM() 
{
    cout<< "#------  Start the VM  -------\n" << endl;
    cout<<"###   Command Executing: " << "VBoxHeadless --startvm linuxLite ###\n"<<endl;
    system("VBoxHeadless --startvm linuxLite");
    cin.get();
}