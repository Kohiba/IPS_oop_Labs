#include "stdafx.h"
#include "Handler.h"
#include "utility"
#include "iostream"

using namespace std;
using namespace std::placeholders;

void GetCarInfo(CCar & m_car);
void SetEngineOn(CCar & m_car);
void SetEngineOff(CCar & m_car);
void SetGear(CCar & m_car);
void SetSpeed(CCar & m_car);

CHandler::CHandler(CCar & car)
	:m_car(car)
{
	m_commandHandler.insert(make_pair("Info", bind(GetCarInfo, _1)));
	m_commandHandler.insert(make_pair("EngineOn", bind(SetEngineOn, _1)));
	m_commandHandler.insert(make_pair("EngineOff", bind(SetEngineOff, _1)));
	m_commandHandler.insert(make_pair("SetGear", bind(SetGear, _1)));
	m_commandHandler.insert(make_pair("SetSpeed", bind(SetSpeed, _1)));
}


CHandler::~CHandler()
{
}


void CHandler::ExecuteCommand(std::string const& command)
{
	auto it = m_commandHandler.find(command);
	if (it != m_commandHandler.end())
	{
		FuncCommand handler = it->second;
		handler(m_car);
	}
	else
	{
		cout << "      unknown command" << endl;
	}
}

void GetCarInfo(CCar & m_car)
{
	cout << "      {------Info------}" << endl;
	cout << "      Engine state: ";
	if (m_car.GetEngineState())
	{
		cout << "On" << endl;
	}
	else
	{
		cout << "Off" << endl;
	}
	cout << "      Direction of motion: ";
	int directionOfMotion = m_car.GetDirectionOfMotion();
	switch (directionOfMotion)
	{
	case (-1):
	{
		 cout << "back draft" << endl;
		 break;
	}
	case (0):
	{
		cout << "quiescence" << endl;
		break;
	}
	case (1):
	{
		cout << "onward movement" << endl;
		break;
	}
	default:
		break;
	}
	cout << "      Gear: " << m_car.GetGear() << endl;
	cout << "      Speed: " << m_car.GetSpeed() << endl;
	cout << "      {----------------}" << endl;
}
void SetEngineOn(CCar & m_car)
{
	if (m_car.TurnOnEngine())
	{
		cout << "      Engine starts" << endl;
	}
	else
	{
		cout << "      The engine fails to start" << endl;
	}
}
void SetEngineOff(CCar & m_car)
{
	if (m_car.TurnOffEngine())
	{
		cout << "      The engine is stopped" << endl;
	}
	else
	{
		cout << "      Engine failed to stop" << endl;
	}
}
void SetGear(CCar & m_car)
{
	int gearNumber;
	cin >> gearNumber;
	if (m_car.SetGear(gearNumber))
	{
		cout << "      Transmission of successfully changed" << endl;
	}
	else
	{
		cout << "      Transmission can not be changed" << endl;
	}
}
void SetSpeed(CCar & m_car)
{
	int speed;
	cin >> speed;
	if (m_car.SetSpeed(speed))
	{
		cout << "      The rate of successfully changed" << endl;
	}
	else
	{
		cout << "      Rate can not be changed" << endl;
	}
}