#include <string>
#include <iostream>

class Karen{
    std::string complaintLevels[4];
    void (Karen::*complaintFuncts[4])();
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );

    public:
    Karen();
    void complain( std::string level );
};