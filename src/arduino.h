#ifndef ARDUINO_H
#define ARDUINO_H
#include <boost/asio.hpp>
#include <unistd.h>

class Arduino
{
public:
    Arduino(const std::string& port, const unsigned int& baud_rate);
    std::string getHelloResponse();
    std::string switchLed();

private:
    void writeString(const std::string& s);
    std::string readLine();

    boost::asio::io_service _io;
    boost::asio::serial_port _serial;
};

#endif // ARDUINO_H
