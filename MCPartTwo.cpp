#include "MCPartTwo.hpp"

MCPartTwo::MCPartTwo()
{

	std::ifstream file("readings.txt");

//	std::vector <std::string> firsthalf;

	std::string l;	

	int i=0;

	while(std::getline(file,l))
	{
		line.push_back(l);
		i++;
	}
	this->numSimulatedDays = std::stoi(line.at(0));
	this->numCategories = std::stoi(line.at(1));
	for(int i=0;i<line.size();i++)
	{	
		if(i==0)
		{
			std::cout << "Simulated Days: ";
		}
		else if(i==1)
		{
			std::cout << "Number of categories: ";
		}
		else if(i==2)
		{
			std::cout << "Ranges and occurrences in each range: " << std::endl;
		}
		else if(i==line.size()-1)
		{
			std::cout << "Units of measurement: ";
		}
		
			std::cout << line.at(i) << std::endl;
		

	}


	for(int i=2;i<line.size()-1;i++)
	{
		std::string word;
		std::string word2;
		std::string firstNum;
		std::string secondNum;

		std::istringstream ss(line.at(i));//Gets whole line from file

		ss >> word >> word2; // 0-2000 and 15

		std::istringstream ss2(word);

		std::getline(ss2,firstNum,'-');
		std::getline(ss2,secondNum,'-');

		//std::cout << firstNum << std::endl;	
		//std::cout << secondNum << std::endl;//with colon
		
		secondNum.erase(secondNum.end()-1);


		int num1 = std::stoi(firstNum);
		int num2 = std::stoi(secondNum);

		//std::cout << secondNum << std::endl;
		this->begRange.push_back(num1);
		this->endRange.push_back(num2);

		int myint1 = std::stoi(word2);//JUST CHANGED TO WORD2
		this->numOccurences.push_back(myint1);	
			
	}
}


void MCPartTwo::RunAnalyticalModel()
{
	std::vector <double> percentages;
	double sum = accumulate(numOccurences.begin(),numOccurences.end(),0);

	double finalSum=0;

	for(int i=0;i<this->numOccurences.size();i++)
	{
		double perc = numOccurences.at(i)/sum;

		percentages.push_back(perc);

		finalSum += (((begRange.at(i) + endRange.at(i))/2) * perc);
	}

	int leftSum;
	int rightSum;
	for(int i=0;i<begRange.size();i++)
	{
		if(finalSum >= begRange.at(i) && finalSum <= endRange.at(i))
		{
			leftSum = begRange.at(i);
			rightSum = endRange.at(i);
		}	
	

	}

	std::cout << "Analytical model:" << finalSum <<  ". Expected value in the " << leftSum << "-" << rightSum << "/" << line.at(line.size()-1) << " range." << std::endl;

}


void MCPartTwo::RunSimulationModel()
{

	std::vector <int> totalSumForRange;
	std::vector <int> numTimes;

	for(int i=0;i<this->numCategories;i++)
	{
		totalSumForRange.push_back(0);
		simulationIncrements.push_back(0);
		numTimes.push_back(0);
	}

		for(int i=0; i<this->numSimulatedDays;i++)
		{	
			int numSoFar=0;
			for(int j=0;j<this->numCategories;j++)
			{
				int num1 = std::rand() % 100;
				numSoFar += numOccurences.at(j);
				if(j==0)//0-2000
				{
					if(num1 >= 0 && num1 < numSoFar)
					{
						this->simulationIncrements.at(j)++;
						int num2 = std::rand() % (endRange.at(j) - begRange.at(j)) + begRange.at(j);
						totalSumForRange.at(j) += num2;
						numTimes.at(j) += 1;
					}
				}
				else//all other ranges after 0-2000
				{
					if(num1 < numSoFar)
					{
						
						this->simulationIncrements.at(j)++;		
						int num3 = std::rand() % (endRange.at(j) - begRange.at(j)) + begRange.at(j);
						totalSumForRange.at(j) += num3;			
						numTimes.at(j) += 1;
					}
				}
			}
			

		}

		std::cout << "Should be between 0 and 2000: " <<  ((1.00*totalSumForRange.at(0))/numTimes.at(0)) << std::endl;
		
		for(int i=0;i<this->numCategories;i++)
		{	
			std::cout << ((1.00*totalSumForRange.at(i))/numTimes.at(i)) << std::endl;
		}






}
