#pragma once

#include <string>
#include <vector>


enum class SortKey
{
	Name = 0,
	Patronymic = 1,
	PhoneNumber = 2
};

struct PersonData
{
public:

	std::string Name;
	std::string Patronymic;
	std::string PhoneNumber;
};


/**
 * Менеджер массива персон
 *	- Имеет массив персон
 *	- Получает данные о персонах из файла путём десериализации и добавлением по штучно
 *	- Имеет метод сортировки персон, параметр для сортировки выбирается по ключу
 *	- Даёт пользователю возможность доступа по индексу для точечного корректирования персон
 */
class Manager
{
protected:
	
	std::vector<PersonData> PersoesArray;

public:

	Manager(){}

	/**
	 * Десериализация файла принятого параметром
	 *	- Path: принимает путь к файлу
	 *	-! Метод принимает файл с порядком: имя, фамилия, номер 
	 */
	void Deserialization(const std::string& Path);

	/**
	 * Сериализация данных в файл путь к которому передан параметром
	 *	- Path: путь к файлу для сериализации
	 */
	void Serialization(const std::string& Path);

	/**
	 * Добавляем элемент персоны в массив менеджера
	 *	- PerconValue: объект персоны
	 */
	void EmplacePerson(PersonData PerconValue);

	/**
	 * Сортировка данных пузырьком
	 *	- SortKey: в зависимости от этого ключа будет выбран тип сортировки 
	 */
	void Sort(SortKey SortKey);


	size_t GetSize() const { return PersoesArray.size(); }

	PersonData& operator[](int index) { return PersoesArray[index]; }
};

