#include <iostream>
#include "arduino.h"
#include <unistd.h>

using namespace std;

int main()
{
    try
    {
        /*
         *Change "/dev/ttyACM0" to your arduino serial port on your machine
         *Do not forget to give the appropriate rights to the serial port
         */
        Arduino arduino("/dev/ttyACM0",9600);
        //Example : simple communication
        std::cout << arduino.getHelloResponse() << std::endl;

        //Exemple : action on arduino :
        for (int i = 0 ; i < 10 ; i++)
        {
            sleep(1);
            std::cout << "led : " << arduino.switchLed() << std::endl;
        }
    } catch(boost::system::system_error& e)
    {
        cout<<"Error: "<<e.what()<<endl;
    }
    return 0;
}

