#include "MonteCarlo.hpp"

MonteCarlo::MonteCarlo(std::string numOfBatch, std::string numItems,std::string percentBadBatches, std::string percentBadness, std::string numPicked)
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

	std::stringstream ss5(numPicked);
	int num5;
	ss5 >> num5;
	this->numPicked = num5;	
}

void MonteCarlo::DeleteBatches()
{
/*
	for(int i=0; i<this->numOfBatch; i++)
	{
		std::string fileName = "ds";
		fileName += std::to_string(i);
		fileName += ".txt";
	//	std::cout << fileName << std::endl;

		std::remove(fileName);

		//std::ofstream myFile;
		//myFile.open(fileName);
		//myFile.close();
	}
*/
}

void MonteCarlo::CheckBatches()
{

	int numBadBatchesDetected = 0;
	std::cout << "\nAnalyzing Data Sets:\n";

	for(int i=0; i<this->numOfBatch; i++)
	{

		std::string fileName = "ds";
		fileName += std::to_string(i+1);
		fileName += ".txt";

		std::ifstream ifile(fileName);

		std::string line;
		for(int j=0;j<this->numPicked;j++)
		{
			std::getline(ifile,line);
			if(line == "b")
			{
				std::cout << "batch\t#" << i << " is bad" << std::endl;
				numBadBatchesDetected++;
				break;
			}
		}
	}

	double num = 1.00-(percentBadness/100.0);
	std::cout << "\nBase = " << num << std::endl;
	std::cout << "Exponent = " << numPicked << std::endl;
	std::cout << "P(failure to detect bad batch) = " << pow(num, numPicked) << std::endl;
	std::cout << "Percentage of bad batches actually detected = " << 100*(1.00*numBadBatchesDetected/numTotalBadBatches) << "%" << std::endl;
}


void MonteCarlo::PrintBatches()
{
//	std::string fileName = "ds";
	
	bool isGoodBatch;
	bool isGoodChip;
	int numBad = 0;		
	numTotalBadBatches = 0;
	std::cout << "\nGenerating Data Sets:\n";

	for(int i=0; i<this->numOfBatch; i++)
	{

		std::string fileName = "ds";
		fileName += std::to_string(i+1);
		fileName += ".txt";
		//std::cout << fileName << std::endl;

		isGoodBatch = true;
	


		int num1 = std::rand() % 100;
		if(num1 > 0 && num1 <= percentBadBatches)
		{
			isGoodBatch = false;
			numTotalBadBatches++;
			std::cout << "Create bad set batch #\t" << i;

		}	
		std::ofstream myFile;
		myFile.open(fileName);

		for(int j=0;j<this->numItems;j++)
		{
			isGoodChip = true;

			if(isGoodBatch == true)
			{
				myFile << "g" << std::endl;
			}
			else
			{

				int num2 = std::rand() % 100;
				if(num2 > 0 && num2 <= percentBadness)
				{
					isGoodChip = false;
				}	
	
				if(isGoodChip == true)
				{
					myFile << "g" << std::endl;
				}
				else
				{
					myFile << "b" << std::endl;
					numBad++;
				}
			}
		}
		if(isGoodBatch == false)
		{
			std::cout << "\ttotBad = " << numBad << "\ttotal = " << numItems << "\tBad Percentage: " << percentBadness << std::endl;
		
		}
		myFile.close();
	}


}
