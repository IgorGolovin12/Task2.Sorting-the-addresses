#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

class Address
{
private:
	std::string city__;
	std::string street__;
	int house__;
	int flat__;
public:
	Address(std::string city, std::string street, int house, int flat)
	{
		city__ = city;
		street__ = street;
		house__ = house;
		flat__ = flat;
	}
	Address()
	{
		city__ = "city";
		street__ = "street";
		house__ = 0;
		flat__ = 0;
	}
	std::string get_output_address() const
	{
		std::string addres = city__ + ", " + street__ + ", " + std::to_string(house__) + ", " + std::to_string(flat__);
		return addres;
	}
	friend void sort(Address* arr, int count);
};

	void sort(Address* arr, int count)
	{
		bool swapped;
		do
		{
			swapped = false;
			for (int counter = 1; counter < count; counter++)
			{
				if (arr[counter - 1].city__ > arr[counter].city__)
				{
					Address temp = arr[counter - 1];
					arr[counter - 1] = arr[counter];
					arr[counter] = temp;
					swapped = true;
				}
			}
		} while (swapped);
	}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream in_address("in.txt");
	if (in_address.is_open())
	{
		int quantity;
		in_address >> quantity;
		Address* arr = new Address[quantity];
		for (int counter = 0; counter < quantity; counter++)
		{
			std::string city, street;
			int house, flat;
			in_address >> city;
			in_address >> street;
			in_address >> house;
			in_address >> flat;
			arr[counter] = Address { city, street, house, flat };
		}
		in_address.close();
		sort(arr, quantity);
		std::ofstream out_address("out.txt");
		if (out_address.is_open())
		{
			out_address << quantity << std::endl;
			for (int counter = 0; counter < quantity; counter++)
			{
				out_address << arr[counter].get_output_address() << std::endl;
			}
		}
		else
		{
			std::cout << "Не удалось открыть файл!";
		}
		out_address.close();
		delete[] arr;
	}
	else
	{
		std::cout << "Не удалось открыть файл!";
	}
	return EXIT_SUCCESS;
}