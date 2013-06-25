#include "Fleet.h"
#include "SpaceShipFactory.h"

#include <fstream>
#include <sstream>
#include <string>
#include <assert.h>

Fleet::Fleet(const std::string& fleetFilename)
{
	std::ifstream infile(fleetFilename);

	std::string line;
	while (std::getline(infile, line)) {
		size_t spacePos = line.find(' '); // find first space
		assert(spacePos != std::string::npos); // a space must exist

		std::string type = line.substr(0, spacePos);
		std::string param = line.substr(spacePos+1);

		auto ship = SpaceShipFactory::getInstance().buildSpaceShip(type, param);
		if (ship != nullptr) {
			m_spaceShips.push_back(ship);
		}
	}
}
