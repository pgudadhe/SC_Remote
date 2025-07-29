#include <iostream>
#include <vector>
#include <string>
#include "systemc.h"


using namespace std;

// Basic SC_MODULE with a SC_METHOD
SC_MODULE(SCHelloWorld) 
{
    sc_in<bool> clock; 
    vector<string> msg {"Hello", "SystemC", "World", "from", "VS Code", "via", "Windows", "Subsystem", "for", "Linux"};
    uint32_t count = 0;

    void process() 
    {
        if(count < msg.size())
            std::cout << "Message: " << msg[count] << " at time: " << sc_time_stamp() << std::endl;
        else
            std::cout << "Tick at time: " << sc_time_stamp() << std::endl;

        count++;
    }

    SC_CTOR(SCHelloWorld) 
    {
        SC_METHOD(process);
        sensitive << clock.pos(); 
    }
};

int sc_main(int argc, char* argv[])
{
    sc_clock clock("clock", 1, SC_NS); // Create a clock signal with 1 ns period

    SCHelloWorld schw_module("SC HelloWorld");
    schw_module.clock(clock);

    sc_start(10, SC_NS); // Run the simulation for 10 ns


   return 0;
}