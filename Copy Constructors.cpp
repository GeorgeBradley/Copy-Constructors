// Copy Constructors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class Product 
{

public:

	std::string sProductName;
	double dProductPrice;
	int iProductQuantitySold;

	Product() //Normal default constructor which delegates to the delegating constructor

		:Product("",0.0, 0)
	{
		std::cout << "Default constructor called\n";
	}
	Product(std::string sInit, double dInit, int iInit)//Three argument delegating constructor
		:sProductName(sInit), dProductPrice(dInit), iProductQuantitySold(iInit)
	{
		std::cout << "Three argument constructor called\n";
	}
	//Shallow Copy constructor
	Product(const Product& objSource)
		:Product(objSource.sProductName, objSource.dProductPrice, objSource.iProductQuantitySold)
	{
		std::cout << "Shallow copy constructor called\n";
	}
	~Product() //Destructor
	{
		std::cout << "Destructor called\n";
	}
};

void Display_Product(Product objProduct)
{
	std::cout << objProduct.sProductName << std::endl;
	std::cout << objProduct.dProductPrice << std::endl;
	std::cout << objProduct.iProductQuantitySold << std::endl;
}

int main()
{
	Product objInstance1;//This will call the default constructor
	Product objInstance2("Chair", 100.00, 90); //This will call the three argument constructor
	Product objInstance3 = objInstance1; //This will call the shallow copy constructor
	Display_Product(objInstance3);
}