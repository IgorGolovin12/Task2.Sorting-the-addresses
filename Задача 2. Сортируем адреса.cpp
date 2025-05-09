#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

class Address
{
private:
	std::string __city;
	std::string __street;
	int __house;
	int __flat;
public:
	Address(std::string city, std::string street, int house, int flat)
	{
		__city = city;
		__street = street;
		__house = house;
		__flat = flat;
	}
	Address()
	{
		__city = "city";
		__street = "street";
		__house = 0;
		__flat = 0;
	}
	std::string get_output_address(Address arr[], int count)
	{
		std::string addres = arr[count].__city + ", " + arr[count].__street + ", " + std::to_string(arr[count].__house) + ", " + std::to_string(arr[count].__flat);
		return addres;
	}
	void sort(Address* arr, int count)
	{
		bool swapped;
		do
		{
			swapped = false;
			for (int counter = 1; counter < count; counter++)
			{
				if (arr[counter - 1].__city > arr[counter].__city)
				{
					Address temp = arr[counter - 1];
					arr[counter - 1] = arr[counter];
					arr[counter] = temp;
					swapped = true;
				}
			}
		} while (swapped);
	}
};

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
			arr[counter] = { city, street, house, flat };
		}
		in_address.close();
		arr->sort(arr, quantity);
		std::ofstream out_address("out.txt");
		if (out_address.is_open())
		{
			out_address << quantity << std::endl;
			for (int counter = 0; counter < quantity; counter++)
			{
				out_address << arr->get_output_address(arr, counter) << std::endl;
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