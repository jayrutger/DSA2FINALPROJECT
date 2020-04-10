#include "MonteCarlo.hpp"

MonteCarlo::MonteCarlo(std::string numOfBatch, std::string numItems,std::string percentBadBatches, std::string percentBadness)
{
	std::stringstream ss(numOfBatch);
	int num1;
	ss >> num1;
	this->numOfBatch = num1;

	std::stringstream ss2(numItems);
	int num2;
	ss2 >> num2;	
	this->numItems = num2;

	std::stringstream ss3(percentBadBatches);
	int num3;
	ss3 >> num3;	
	this->percentBadBatches = num3;

	std::stringstream ss4(percentBadness);
	int num4;
	ss4 >> num4;
	this->percentBadness = num4;	
}


void MonteCarlo::PrintBatches()
{
//	std::string fileName = "ds";
	
	for(int i=0; i<this->numOfBatch; i++)
	{
		std::string fileName = "ds";
		fileName += std::to_string(i);
		//std::ofstream outfile(fileName);
		std::cout << fileName << std::endl;
	}


}
