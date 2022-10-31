#pragma once

#include "ManagerData.h"

/*
 *  Создадим класс менеджер которой будет хронить, сортировать пользователей и являться внешним API
 *  В файле с менеджером создадим структуру в публичной области которым будет пользоваться менеджер
 *      так как струтктура будет публичная пользователь сможет заводить сових персон самостоятельно 
 *      
 *	Функционал менеджера будет включать:
 *		- Де\сериализацию данных из\в файл, методы будет получать путь на файл далее работая с ним.
 *		- Сортировка получанных данных, метод сортировки будет получать enum для выбора по каким данным производить сортировку
 *
 *	Как дополнительный функционал добавим следующие методы:
 *		- Возможность добавить персону, так как пользователь имеет доступ к структуре
 *			он может создать структуру и добавить её в массив менеджера, если потребуется дополнить массив.
 *		- Оператор [], при потребности в корректировке даст пользователю возможность изменять элементы в массиве 
 *
 */


int main()
{
	using namespace std;
	

	Manager test_manager;

	test_manager.Deserialization("C:\\test.txt");

	PersonData tem_pers;
	tem_pers.Name = "Ivan";
	tem_pers.Patronymic = "Gorin";
	tem_pers.PhoneNumber = "88005553535";
	
	test_manager.EmplacePerson(tem_pers);

	if(test_manager.GetSize() > 1)
	{
		test_manager[1].Name = "Masha";
	}
	
	
	test_manager.Sort(SortKey::Name);
	
	test_manager.Serialization("D:\\testname.txt");

	test_manager.Sort(SortKey::Patronymic);

	test_manager.Serialization("D:\\testpatronymic.txt");

	test_manager.Sort(SortKey::PhoneNumber);

	test_manager.Serialization("D:\\testphonenumber.txt");

}
