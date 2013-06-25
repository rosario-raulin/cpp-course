#include "SpaceShipFactory.h"

// If SpaceShips.h would be not included, the SpaceShip's destructor would be unknown.
// This leads normally to a warning
#include "SpaceShips.h"

void SpaceShipFactory::registerSpaceShip(const std::string& name, const CreateSpaceShipFunc& fn) {
	if (m_createSpaceShipFuncRegister.find(name) != m_createSpaceShipFuncRegister.end()) {
		throw std::exception();
	}
	m_createSpaceShipFuncRegister[name] = fn;
}

std::shared_ptr<SpaceShip> SpaceShipFactory::buildSpaceShip(const std::string& spaceShipTypeName, const std::string& parameter) {
	auto fn = m_createSpaceShipFuncRegister.find(spaceShipTypeName);
	if (fn != m_createSpaceShipFuncRegister.end()) {
		return fn->second(parameter);
	} else {
		return nullptr;
	}
}
