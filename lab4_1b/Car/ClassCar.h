#pragma once

class CCar
{
public:
	CCar();
	~CCar();
	bool GetEngineState()const;
	int GetDirectionOfMotion()const;
	int GetSpeed()const;
	int GetGear()const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	bool m_engineState;
	int m_directionOfMotion;
	int m_speed;
	int m_gear;
};