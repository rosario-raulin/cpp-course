#include <iostream>
// #include <thread>

char** createSomeMap();
void freeMap( char** );
void drawMap( char** );
void moveMap( char** );
void freeMap( char** );

int main()
{
	char** map = createSomeMap();

	do
	{
		drawMap( map );
		moveMap( map );
		//std::this_thread::sleep_for( std::chrono::milliseconds( 20 ) );
	} while( std::cin.get() == '\n' );


        freeMap(map);

	return 0;
}
