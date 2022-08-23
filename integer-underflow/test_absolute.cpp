#include "absolute.h"

class AbsoluteTest : public CppUnit::TestCase { 
public: 
    AbsoluteTest( std::string name ) : CppUnit::TestCase( name ) {}

    void runTest() {
        CPPUNIT_ASSERT( absolute_int(10) == 10 );
        CPPUNIT_ASSERT( absolute_int(-65536) == 65536 );
    }
};