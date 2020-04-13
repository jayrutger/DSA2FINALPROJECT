#include "MCPartTwo.hpp"

MCPartTwo::MCPartTwo()
{

	std::ifstream file("readings.txt");

//	std::vector <std::string> line;
	std::vector <std::string> firsthalf;
	//std::vector <int> numOccurences;

	std::string l;	

	int i=0;

	while(std::getline(file,l))
	{
		line.push_back(l);
	/*	if(i==0)
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
		//std::cout << line.at(i) << std::endl;	
	*/	//std::cout << line.at(i) << std::endl;
		i++;
	}
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
//			std::cout << line.at(i) << std::endl;
		}
		
			std::cout << line.at(i) << std::endl;
		

	}


//	std::cout << line.at(3);

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

		std::cout << firstNum << std::endl;	
		//std::cout << secondNum << std::endl;//with colon
		
		secondNum.erase(secondNum.end()-1);


		int num1 = std::stoi(firstNum);
		int num2 = std::stoi(secondNum);

		std::cout << secondNum << std::endl;
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

	std::cout << finalSum << std::endl;

}
