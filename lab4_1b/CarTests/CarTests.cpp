// CarTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Car\ClassCar.h"

/*
	���������� ��������� ������ 
		�������� ���������
		�������� - ��������
		����������� �������� - �����
		�������� = 0

	������ � ���������� ����������
		����������� �������� - �����
		�������� - ��������
		�������� = 0
*/

BOOST_AUTO_TEST_SUITE(JastCreativeCar)
BOOST_AUTO_TEST_CASE(IsCarCreate)
{
	CCar testCar;
	BOOST_CHECK(!testCar.GetEngineState());
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 0);
	BOOST_CHECK(testCar.GetSpeed() == 0);
	BOOST_CHECK(testCar.GetGear() == 0);
}

BOOST_AUTO_TEST_CASE(CheckTurnOnEngineAfterCreateCar)
{
	CCar testCar;
	BOOST_CHECK(testCar.TurnOnEngine());
	BOOST_CHECK(testCar.GetEngineState());
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 0);
	BOOST_CHECK(testCar.GetSpeed() == 0);
	BOOST_CHECK(testCar.GetGear() == 0);

	BOOST_CHECK(!testCar.TurnOnEngine());
	BOOST_CHECK(testCar.GetEngineState());
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 0);
	BOOST_CHECK(testCar.GetSpeed() == 0);
	BOOST_CHECK(testCar.GetGear() == 0);
}

BOOST_AUTO_TEST_CASE(CheckTurnOffEngineAfterTurnOn)
{
	CCar testCar;
	testCar.TurnOnEngine();
	BOOST_CHECK(testCar.TurnOffEngine());
}

BOOST_AUTO_TEST_CASE(CheckTransmissionShiftsFromNeutralToFirst)
{
	CCar testCar;
	testCar.TurnOnEngine();
	BOOST_CHECK(testCar.SetGear(1));	 //� �������� �� ������ ����������
	BOOST_CHECK(!testCar.SetGear(2));	 //� ������ �� ������ ������������
	BOOST_CHECK(testCar.SetGear(-1));	 //� ������ �� ������ ����������
	BOOST_CHECK(testCar.SetGear(1));	 //� ������ �� ������ ����������
}

BOOST_AUTO_TEST_CASE(CheckShiftingBackNeutralFirstWithTheChangeInVelocity)
{
	CCar testCar;
	BOOST_CHECK(testCar.TurnOnEngine());  //��������� �������
	BOOST_CHECK(!testCar.SetSpeed(10));	  //������� ���������� �� �������� - ��������
	BOOST_CHECK(testCar.SetGear(-1));	  //�������� ������ ��������
	BOOST_CHECK(testCar.GetSpeed() == 0); //��������� �������� = 0
	BOOST_CHECK(testCar.GetDirectionOfMotion() == -1); //��������� ����������� �������� - �����
	BOOST_CHECK(testCar.SetSpeed(5));	  //����������� �������� �� 5��/�
	BOOST_CHECK(testCar.SetSpeed(20));	  //����������� �������� �� 20��/�
	BOOST_CHECK(!testCar.TurnOffEngine()); //�������� ��������� ��������� �������
	BOOST_CHECK(!testCar.SetSpeed(25));	  //������� ��������� �������� �� 25��/� ��������
	BOOST_CHECK(testCar.GetSpeed() == 20);//��������� ������� �������� = 20��/�
	BOOST_CHECK(!testCar.SetGear(1));	  //������� �������� ������ �� ������������� = ��������
	BOOST_CHECK(testCar.SetSpeed(0));	  //������� �������� �� 0��/�
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 0); //��������� ����������� �������� - �����
	BOOST_CHECK(testCar.SetGear(1));	  //�������� ������ ��������
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 1); //��������� ����������� �������� - ������
	BOOST_CHECK(testCar.GetSpeed() == 0); //�������� �������� = 0��/�
	BOOST_CHECK(testCar.SetSpeed(5));	  //����������� �������� �� 5��/�
	BOOST_CHECK(testCar.SetSpeed(30));	  //����������� �������� �� 30��/�
	BOOST_CHECK(!testCar.SetSpeed(35));	  //������� ��������� �������� �� 35��/� ��������
	BOOST_CHECK(!testCar.SetGear(-1));	  //������� �������� ������ �������� ��������
	BOOST_CHECK(!testCar.TurnOffEngine()); //�������� ��������� ��������� �������
	BOOST_CHECK(testCar.GetSpeed() == 30); //�������� �������� = 30��/�
	BOOST_CHECK(testCar.SetSpeed(0));	  //������� �������� �� 0��/�
	BOOST_CHECK(testCar.SetGear(-1));	  //�������� ������ ��������
	BOOST_CHECK(testCar.SetSpeed(5));	  //����������� �������� �� 5��/�
	BOOST_CHECK(testCar.SetGear(0));	  //�������� ��������
	BOOST_CHECK(testCar.GetSpeed() == 5); //�������� �������� = 5��/�
	BOOST_CHECK(testCar.GetDirectionOfMotion() == -1); //��������� ����������� �������� - �����
	BOOST_CHECK(!testCar.TurnOffEngine()); //�������� ��������� ��������� �������
	BOOST_CHECK(testCar.SetSpeed(0));	  //���������������
	BOOST_CHECK(testCar.TurnOffEngine()); //��������� ���������
}

BOOST_AUTO_TEST_CASE(CheckShiftingFromTheFirstToTheFifth)
{
	CCar testCar;
	BOOST_CHECK(testCar.TurnOnEngine());    //������� ���������
	BOOST_CHECK(testCar.SetGear(1));        //�������� ������
	BOOST_CHECK(testCar.SetSpeed(15));		//����������� �� 15��/�
	BOOST_CHECK(!testCar.SetGear(2));		//�������� �������� ������ - �������
	BOOST_CHECK(testCar.SetSpeed(20));		//����������� �� 20��/�
	BOOST_CHECK(testCar.SetGear(2));		//�������� ������
	BOOST_CHECK(testCar.SetSpeed(29));		//����������� �� 29��/�
	BOOST_CHECK(!testCar.SetGear(3));		//�������� �������� ������ - �������
	BOOST_CHECK(testCar.SetSpeed(30));		//����������� �� 30��/�
	BOOST_CHECK(testCar.SetGear(3));		//�������� ������
	BOOST_CHECK(testCar.SetSpeed(39));		//����������� �� 39��/�
	BOOST_CHECK(!testCar.SetGear(4));		//�������� �������� ��������� - �������
	BOOST_CHECK(testCar.SetSpeed(40));		//����������� �� 40��/�
	BOOST_CHECK(testCar.SetGear(4));		//�������� ���������
	BOOST_CHECK(testCar.SetSpeed(49));		//����������� �� 49��/�
	BOOST_CHECK(!testCar.SetGear(5));		//�������� �������� ����� - �������
	BOOST_CHECK(testCar.SetSpeed(50));		//����������� �� 50��/�
	BOOST_CHECK(testCar.SetGear(5));		//�������� �����
	BOOST_CHECK(testCar.SetSpeed(150));		//����������� �� 150��/�
	BOOST_CHECK(!testCar.SetSpeed(151));	//�������� ���������� �� 151��/� - �������
	BOOST_CHECK(testCar.SetGear(0));		//������������� �� ��������
	BOOST_CHECK(testCar.GetSpeed() == 150);	//������� �������� = 150��/�
	BOOST_CHECK(testCar.SetSpeed(100));		//������� �������� �� 100��/�
	BOOST_CHECK(!testCar.SetSpeed(101));	//�������� ���������� �� �������� - �������
	BOOST_CHECK(testCar.SetSpeed(1));		//������� �������� �� 1 ��/�
 	BOOST_CHECK(!testCar.TurnOffEngine());	//�������� ��������� ��������� �� ������������� - �������
	BOOST_CHECK(testCar.SetSpeed(0));		//���������������
	BOOST_CHECK(testCar.TurnOffEngine());	//��������� ���������
}
BOOST_AUTO_TEST_CASE(CheckShiftingFromFifthToFirst)
{
	CCar testCar;
	BOOST_CHECK(testCar.TurnOnEngine());    //������� ���������
	BOOST_CHECK(testCar.SetGear(1));        //�������� ������
	BOOST_CHECK(testCar.SetSpeed(30));		//����������� �� 30��/�
	BOOST_CHECK(testCar.SetGear(2));		//�������� �������� ������
	BOOST_CHECK(testCar.SetSpeed(50));		//����������� �� 50��/�
	BOOST_CHECK(testCar.SetGear(5));		//�������� �����
	BOOST_CHECK(testCar.SetSpeed(150));		//����������� �� 150��/�
	BOOST_CHECK(testCar.GetSpeed() == 150);	//������� �������� = 150��/�
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 1); //����������� �������� - ������

	BOOST_CHECK(testCar.SetSpeed(91));		//�������� �� 91��/�
	BOOST_CHECK(!testCar.SetGear(4));		//�������� ������������ �� ��������� - �������
	BOOST_CHECK(testCar.SetSpeed(90));		//�������� �� 90��/�
	BOOST_CHECK(testCar.SetGear(4));		//������������� �� ���������

	BOOST_CHECK(testCar.SetSpeed(61));		//�������� �� 61��/�
	BOOST_CHECK(!testCar.SetGear(3));		//�������� ������������ �� ������ - �������
	BOOST_CHECK(testCar.SetSpeed(60));		//�������� �� 60��/�
	BOOST_CHECK(testCar.SetGear(3));		//������������� �� ������

	BOOST_CHECK(testCar.SetSpeed(51));		//�������� �� 51��/�
	BOOST_CHECK(!testCar.SetGear(2));		//�������� ������������ �� ������ - �������
	BOOST_CHECK(testCar.SetSpeed(50));		//�������� �� 50��/�
	BOOST_CHECK(testCar.SetGear(2));		//������������� �� ������

	BOOST_CHECK(testCar.SetSpeed(31));		//�������� �� 31��/�
	BOOST_CHECK(!testCar.SetGear(1));		//�������� ������������ �� ������ - �������
	BOOST_CHECK(testCar.SetSpeed(30));		//�������� �� 30��/�
	BOOST_CHECK(testCar.SetGear(1));		//������������� �� ������

	BOOST_CHECK(testCar.SetSpeed(0));		//�������� �� 0��/�
	BOOST_CHECK(testCar.SetGear(0));		//������������� � ��������
	BOOST_CHECK(testCar.TurnOffEngine());	//��������� ���������
}



BOOST_AUTO_TEST_SUITE_END()