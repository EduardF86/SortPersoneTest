#pragma once

#include "ManagerData.h"

#include <fstream>
#include <algorithm>


void Manager::Deserialization(const std::string& Path)
{
	std::ifstream file;

	file.open(Path);

	if(!file.is_open())
	{
		return;
	}
	else
	{
		while (!file.eof())
		{
			PersonData tempperson;

			file >> tempperson.Name;
			file >> tempperson.Patronymic;
			file >> tempperson.PhoneNumber;

			if (!(tempperson.Name.empty() && tempperson.PhoneNumber.empty() && tempperson.Patronymic.empty()))
				PersoesArray.emplace_back(std::move(tempperson));
			else
				continue;
		}
	}

	file.close();
}

void Manager::Serialization(const std::string& Path)
{
	std::ofstream file;
	file.open(Path);

	if (!file.is_open())
	{
		return;
	}
	else
	{
		size_t tempsize = PersoesArray.size();
		
		for(int i = 0; i < tempsize; ++i)
		{
			
			file << PersoesArray[i].Name << ' ';
			file << PersoesArray[i].Patronymic << ' ';
			file << PersoesArray[i].PhoneNumber;

			file << '\n';
		}
		
	}

	file.close();
}

void Manager::EmplacePerson(const PersonData PerconValue)
{
	PersoesArray.emplace_back(PerconValue);
}

void Manager::Sort(SortKey SortKey)
{
	switch (SortKey)
	{
		case SortKey::Name:
		{
			size_t tempsize = PersoesArray.size() - 1;

			for (int i = 0; i <= tempsize; ++i)
			{
				for (int j = tempsize; j > i; --j)
				{
					if (PersoesArray[j - 1].Name > PersoesArray[j].Name)
					{
						PersonData temper = PersoesArray[j];
						PersoesArray[j] = PersoesArray[j - 1];
						PersoesArray[j - 1] = temper;
					}
				}
			}

			return;
		}

		case SortKey::Patronymic:
		{
			size_t tempsize = PersoesArray.size() - 1;

			for (int i = 0; i <= tempsize; ++i)
			{
				for (int j = tempsize; j > i; --j)
				{
					if (PersoesArray[j - 1].Patronymic > PersoesArray[j].Patronymic)
					{
						PersonData temper = PersoesArray[j];
						PersoesArray[j] = PersoesArray[j - 1];
						PersoesArray[j - 1] = temper;
					}
				}
			}

			return;
		}

		case SortKey::PhoneNumber:
		{
			size_t tempsize = PersoesArray.size() - 1;

			for (int i = 0; i <= tempsize; ++i)
			{
				for (int j = tempsize; j > i; --j)
				{
					if (PersoesArray[j - 1].PhoneNumber > PersoesArray[j].PhoneNumber)
					{
						PersonData temper = PersoesArray[j];
						PersoesArray[j] = PersoesArray[j - 1];
						PersoesArray[j - 1] = temper;
					}
				}
			}

			return;
		}

		default:
			return;
	}
}
