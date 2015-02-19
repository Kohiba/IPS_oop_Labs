#include "stdafx.h"
#include "ClassCar.h"

CCar::CCar()
{
	m_engineState = false;
	m_directionOfMotion = 0;
	m_speed = 0;
	m_gear = 0;
}
CCar::~CCar()
{

}

bool CCar::GetEngineState()const
{
	return m_engineState;
}
int CCar::GetDirectionOfMotion()const
{
	return m_directionOfMotion;
}
int CCar::GetSpeed()const
{
	return m_speed;
}
int CCar::GetGear()const
{
	return m_gear;
}
bool CCar::TurnOnEngine()
{
	if (!m_engineState)
	{
		m_engineState = true;
		m_directionOfMotion = 0;
		m_speed = 0;
		m_gear = 0;
		return true;
	}
	return false;
}
bool CCar::TurnOffEngine()
{
	bool readyToTurnOff = m_engineState &&
						 (m_speed == 0) &&
						 (m_gear == 0);
	if (readyToTurnOff)
	{
		m_engineState = false;
		return true;
	}
	return false;
}

bool CCar::SetGear(int gear)
{
	//попытка ключить какую либо передачу с выключенным двигателем
	if (!m_engineState)
	{
		m_gear = 0;
		return true;
	}

	// перключится с задней на первую только после того как достигнут покой
	if (gear == 1 && m_gear == -1 && m_directionOfMotion == -1)
	{
		if (m_speed == 0)
		{
			m_directionOfMotion = 1;
			m_gear = 1;
			return true;
		}
	}
	switch (gear)
	{
		case (-1):
		{
			if (m_speed == 0 && (m_gear == 0 || m_gear == 1) && m_directionOfMotion >= 0)
			{
				m_gear = -1;
				m_directionOfMotion = -1;
				return true;
			}
			break;
		}
		case (0):
		{
			m_gear = 0;
			return true;
			break;
		}
		case (1):
		{
			if (m_speed >= 0 && m_speed <= 30 && m_directionOfMotion >= 0)
			{
				m_gear = 1;
				m_directionOfMotion = 1;
				return true;
			}
			break;
		}
		case (2):
		{
			if (m_speed >= 20 && m_speed <= 50 && m_directionOfMotion == 1)
			{
				m_gear = 2;
				return true;
			}
			break;
		}
		case (3):
		{
			if (m_speed >= 30 && m_speed <= 60 && m_directionOfMotion == 1)
			{
				m_gear = 3;
				return true;
			}
			break;
		}
		case (4):
		{
			if (m_speed >= 40 && m_speed <= 90 && m_directionOfMotion == 1)
			{
				m_gear = 4;
				return true;
			}
			break;
		}
		case (5):
		{
			if (m_speed >= 50 && m_speed <= 150 && m_directionOfMotion == 1)
			{
				m_gear = 5;
				return true;
			}
			break;
		}
	}
	return false;
}

bool CCar::SetSpeed(int speed)
{
	if (!m_engineState || speed < 0)
	{
		m_speed = 0;
		return false;
	}
	switch (m_gear)
	{
		case (-1):
		{
			if (speed <= 20)
			{
				m_speed = speed;
				if (m_speed == 0)
				{
					m_directionOfMotion = 0;
				}
				return true;
			}
			break;
		}
		case (0):
		{
			if (speed <= m_speed)
			{
				m_speed = speed;
				if (m_speed == 0)
				{
					m_directionOfMotion = 0;
				}
				return true;
			}
			break;
		}
		case (1):
		{
			if (speed <= 30)
			{
				m_speed = speed;
				if (m_speed == 0)
				{
					m_directionOfMotion = 0;
				}
				return true;
			}
			break;
		}
		case (2):
		{
			if (speed >= 20 && speed <= 50 )
			{
				m_speed = speed;
				return true;
			}
			break;
		}
		case (3):
		{
			if (speed >= 30 && speed <= 60)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
		case (4):
		{
			if (speed >= 40 && speed <= 90)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
		case (5):
		{
			if (speed >= 50 && speed <= 150)
			{
				m_speed = speed;
				return true;
			}
			break;
		}
	}
	return false;
}