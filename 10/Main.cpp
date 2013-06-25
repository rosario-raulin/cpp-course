#include "SpaceShipFactory.h"
#include "SpaceShips.h"
#include "Fleet.h"

#include <sstream>
#include <memory>

int main()
{
	// Register SpaceShips by using the SpaceShipFactory::getInstance().registerSpaceShip with lambda functions.

	// TODO: Register TieFighter with SpaceShipFactory::getInstance().registerSpaceShip
	// The string parameter contains the pilot.
	
	SpaceShipFactory::getInstance().registerSpaceShip("TieFighter",
		SpaceShipFactory::CreateSpaceShipFunc(
			[](const std::string& pilotName)
			{ return std::shared_ptr<SpaceShip>(new TieFighter(pilotName)); }));

	// TODO: Register DeathStar
	// The string parameter has to be interpreted a float, determining its buildProgress

	SpaceShipFactory::getInstance().registerSpaceShip("DeathStar",
		SpaceShipFactory::CreateSpaceShipFunc(
			[](const std::string& param) {
				float buildProgress;
				std::stringstream sstr;
				sstr << param;
				sstr >> buildProgress;
				return std::shared_ptr<SpaceShip>(new DeathStar(buildProgress));
			}));

	// TODO: Register Destroyer
	// The string parameter has to be interpreted a int, determining the number of lasers
	// Note that the a appropriate parameterized instance of the "Destroyer"-class should be created.
	SpaceShipFactory::getInstance().registerSpaceShip("Destroyer",
		SpaceShipFactory::CreateSpaceShipFunc(
			[](const std::string& param) {
				int numLasers;
				std::stringstream sstr;
				sstr << param;
				sstr >> numLasers;
				return std::shared_ptr<SpaceShip>(new Destroyer(false, numLasers));
			}));
	
	// TODO: Register LargeDestroyer
	// The string parameter has to be interpreted a int, determining the number of lasers.
	// Note that the a appropriate parameterized instance of the "Destroyer"-class should be created.
	SpaceShipFactory::getInstance().registerSpaceShip("LargeDestroyer",
		SpaceShipFactory::CreateSpaceShipFunc(
			[](const std::string& param) {
				int numLasers;
				std::stringstream sstr;
				sstr << param;
				sstr >> numLasers;
				return std::shared_ptr<SpaceShip>(new Destroyer(true, numLasers));
			}));

	// Loads fleet from file
	Fleet imperialFleet("imperialships.txt");
}
