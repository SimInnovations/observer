#include <observer.h>
#include <iostream>

int main( int /* argc */, char * /* argv */[] )
{
    pg::connection_owner                 owner;
    pg::blockable_subject< const char* > s;

    owner.connect( s, []( const char* const msg ){ std::cout << msg << std::endl; } );

    s.notify( "Hello World!" );

    {
        pg::subject_blocker< pg::blockable_subject< const char* > > blocker( s );
        s.notify( "Blocked!" );
    }

    s.notify( "Hello World again!" );

    return 0;
}
