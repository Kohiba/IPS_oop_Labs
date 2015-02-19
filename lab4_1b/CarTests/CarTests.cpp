// CarTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Car\ClassCar.h"

/*
	Изначально созданная машина 
		выключен двигатель
		передача - нейтраль
		направление движения - покой
		скорость = 0

	Машина с заведенным двигателем
		направление движения - покой
		передача - нейтраль
		скорость = 0
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
	BOOST_CHECK(testCar.SetGear(1));	 //с нейтрали на первую получилось
	BOOST_CHECK(!testCar.SetGear(2));	 //с первой на вторую неполучилось
	BOOST_CHECK(testCar.SetGear(-1));	 //с первой на заднюю получилось
	BOOST_CHECK(testCar.SetGear(1));	 //с задней на первую получилось
}

BOOST_AUTO_TEST_CASE(CheckShiftingBackNeutralFirstWithTheChangeInVelocity)
{
	CCar testCar;
	BOOST_CHECK(testCar.TurnOnEngine());  //двигатель заведен
	BOOST_CHECK(!testCar.SetSpeed(10));	  //попытка разогнатся на нейтрали - неудачна
	BOOST_CHECK(testCar.SetGear(-1));	  //включаем заднюю передачу
	BOOST_CHECK(testCar.GetSpeed() == 0); //проверяем скорость = 0
	BOOST_CHECK(testCar.GetDirectionOfMotion() == -1); //проверяем направление движения - назад
	BOOST_CHECK(testCar.SetSpeed(5));	  //увеличиваем скорость до 5км/ч
	BOOST_CHECK(testCar.SetSpeed(20));	  //увеличиваем скорость до 20км/ч
	BOOST_CHECK(!testCar.TurnOffEngine()); //пытаемся выключить двигатель неудача
	BOOST_CHECK(!testCar.SetSpeed(25));	  //попытка увеличить скорость до 25км/ч неудачна
	BOOST_CHECK(testCar.GetSpeed() == 20);//проверяем текущую скорость = 20км/ч
	BOOST_CHECK(!testCar.SetGear(1));	  //попытка включить первую не остановившись = неудачна
	BOOST_CHECK(testCar.SetSpeed(0));	  //снижаем скорость до 0км/ч
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 0); //проверяем направление движения - стоим
	BOOST_CHECK(testCar.SetGear(1));	  //включаем первую скорость
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 1); //проверяем направление движения - вперед
	BOOST_CHECK(testCar.GetSpeed() == 0); //проверям скорость = 0км/ч
	BOOST_CHECK(testCar.SetSpeed(5));	  //увеличиваем скорость до 5км/ч
	BOOST_CHECK(testCar.SetSpeed(30));	  //увеличиваем скорость до 30км/ч
	BOOST_CHECK(!testCar.SetSpeed(35));	  //попытка увеличить скорость до 35км/ч неудачна
	BOOST_CHECK(!testCar.SetGear(-1));	  //попытка включить заднюю передачу неудачна
	BOOST_CHECK(!testCar.TurnOffEngine()); //пытаемся выключить двигатель неудача
	BOOST_CHECK(testCar.GetSpeed() == 30); //проверям скорость = 30км/ч
	BOOST_CHECK(testCar.SetSpeed(0));	  //снижаем скорость до 0км/ч
	BOOST_CHECK(testCar.SetGear(-1));	  //включаем заднюю передачу
	BOOST_CHECK(testCar.SetSpeed(5));	  //увеличиваем скорость до 5км/ч
	BOOST_CHECK(testCar.SetGear(0));	  //включаем нейтраль
	BOOST_CHECK(testCar.GetSpeed() == 5); //проверям скорость = 5км/ч
	BOOST_CHECK(testCar.GetDirectionOfMotion() == -1); //проверяем направление движения - назад
	BOOST_CHECK(!testCar.TurnOffEngine()); //пытаемся выключить двигатель неудача
	BOOST_CHECK(testCar.SetSpeed(0));	  //останавливаемся
	BOOST_CHECK(testCar.TurnOffEngine()); //выключаем двигатель
}

BOOST_AUTO_TEST_CASE(CheckShiftingFromTheFirstToTheFifth)
{
	CCar testCar;
	BOOST_CHECK(testCar.TurnOnEngine());    //заводим двигатель
	BOOST_CHECK(testCar.SetGear(1));        //включаем первую
	BOOST_CHECK(testCar.SetSpeed(15));		//разгоняемся до 15км/ч
	BOOST_CHECK(!testCar.SetGear(2));		//пытаемся включить вторую - неудача
	BOOST_CHECK(testCar.SetSpeed(20));		//разгоняемся до 20км/ч
	BOOST_CHECK(testCar.SetGear(2));		//включаем вторую
	BOOST_CHECK(testCar.SetSpeed(29));		//разгоняемся до 29км/ч
	BOOST_CHECK(!testCar.SetGear(3));		//пытаемся включить третью - неудача
	BOOST_CHECK(testCar.SetSpeed(30));		//разгоняемся до 30км/ч
	BOOST_CHECK(testCar.SetGear(3));		//включаем третью
	BOOST_CHECK(testCar.SetSpeed(39));		//разгоняемся до 39км/ч
	BOOST_CHECK(!testCar.SetGear(4));		//пытаемся включить четвертую - неудача
	BOOST_CHECK(testCar.SetSpeed(40));		//разгоняемся до 40км/ч
	BOOST_CHECK(testCar.SetGear(4));		//включаем четвертую
	BOOST_CHECK(testCar.SetSpeed(49));		//разгоняемся до 49км/ч
	BOOST_CHECK(!testCar.SetGear(5));		//пытаемся включить пятую - неудача
	BOOST_CHECK(testCar.SetSpeed(50));		//разгоняемся до 50км/ч
	BOOST_CHECK(testCar.SetGear(5));		//включаем пятую
	BOOST_CHECK(testCar.SetSpeed(150));		//разгоняемся до 150км/ч
	BOOST_CHECK(!testCar.SetSpeed(151));	//пытаемся разогнатся до 151км/ч - неудача
	BOOST_CHECK(testCar.SetGear(0));		//переключаемся на нейтраль
	BOOST_CHECK(testCar.GetSpeed() == 150);	//текущая скорость = 150км/ч
	BOOST_CHECK(testCar.SetSpeed(100));		//снижаем скорость до 100км/ч
	BOOST_CHECK(!testCar.SetSpeed(101));	//пытаемся разогнатся на нейтрали - неудача
	BOOST_CHECK(testCar.SetSpeed(1));		//снижаем скорость до 1 км/ч
 	BOOST_CHECK(!testCar.TurnOffEngine());	//пытаемся выключить двигатель не остановившись - неудача
	BOOST_CHECK(testCar.SetSpeed(0));		//останавливаемся
	BOOST_CHECK(testCar.TurnOffEngine());	//выключаем двигатель
}
BOOST_AUTO_TEST_CASE(CheckShiftingFromFifthToFirst)
{
	CCar testCar;
	BOOST_CHECK(testCar.TurnOnEngine());    //заводим двигатель
	BOOST_CHECK(testCar.SetGear(1));        //включаем первую
	BOOST_CHECK(testCar.SetSpeed(30));		//разгоняемся до 30км/ч
	BOOST_CHECK(testCar.SetGear(2));		//пытаемся включить вторую
	BOOST_CHECK(testCar.SetSpeed(50));		//разгоняемся до 50км/ч
	BOOST_CHECK(testCar.SetGear(5));		//включаем пятую
	BOOST_CHECK(testCar.SetSpeed(150));		//разгоняемся до 150км/ч
	BOOST_CHECK(testCar.GetSpeed() == 150);	//текущая скорость = 150км/ч
	BOOST_CHECK(testCar.GetDirectionOfMotion() == 1); //направление движения - вперед

	BOOST_CHECK(testCar.SetSpeed(91));		//тормозим до 91км/ч
	BOOST_CHECK(!testCar.SetGear(4));		//пытаемся переключится на четвертую - неудача
	BOOST_CHECK(testCar.SetSpeed(90));		//тормозим до 90км/ч
	BOOST_CHECK(testCar.SetGear(4));		//переключаемся на четвертую

	BOOST_CHECK(testCar.SetSpeed(61));		//тормозим до 61км/ч
	BOOST_CHECK(!testCar.SetGear(3));		//пытаемся переключится на третью - неудача
	BOOST_CHECK(testCar.SetSpeed(60));		//тормозим до 60км/ч
	BOOST_CHECK(testCar.SetGear(3));		//переключаемся на третью

	BOOST_CHECK(testCar.SetSpeed(51));		//тормозим до 51км/ч
	BOOST_CHECK(!testCar.SetGear(2));		//пытаемся переключится на вторую - неудача
	BOOST_CHECK(testCar.SetSpeed(50));		//тормозим до 50км/ч
	BOOST_CHECK(testCar.SetGear(2));		//переключаемся на вторую

	BOOST_CHECK(testCar.SetSpeed(31));		//тормозим до 31км/ч
	BOOST_CHECK(!testCar.SetGear(1));		//пытаемся переключится на первую - неудача
	BOOST_CHECK(testCar.SetSpeed(30));		//тормозим до 30км/ч
	BOOST_CHECK(testCar.SetGear(1));		//переключаемся на первую

	BOOST_CHECK(testCar.SetSpeed(0));		//тормозим до 0км/ч
	BOOST_CHECK(testCar.SetGear(0));		//переключаемся в нейтраль
	BOOST_CHECK(testCar.TurnOffEngine());	//выключаем двигатель
}



BOOST_AUTO_TEST_SUITE_END()