#pragma once
#include "ClassCar.h"
#include "string"
#include "functional"
#include "map"


class CHandler
{
public:
	CHandler(CCar & car);
	~CHandler();
	void ExecuteCommand(std::string const& command);
private:
	CCar & m_car;
	typedef std::function<void(CCar &)> FuncCommand;
	std::map<std::string, FuncCommand> m_commandHandler;
};

