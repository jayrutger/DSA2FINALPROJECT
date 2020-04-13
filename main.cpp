#include <iostream>
#include <fstream>
#include <string>
#include "MonteCarlo.hpp"
#include "MCPartTwo.hpp"

int main(){

	std::srand(time(NULL));
	std::ifstream file("t1.txt");
	std::ifstream file2("t2.txt");
	std::ifstream file3("t3.txt");
	std::ifstream file4("t4.txt");

	std::string line[5];
	std::string line2[5];
	std::string line3[5];
	std::string line4[5];


	
		std::getline(file,line[0]);	
		std::cout <<  "Number of batches of items: " << line[0] << std::endl;

		std::getline(file,line[1]);	
		std::cout <<  "Number of items in each batch: " << line[1] << std::endl;

		std::getline(file,line[2]);	
		std::cout <<  "Percentage of batches containing bad items: " << line[2] << std::endl;

		std::getline(file,line[3]);	
		std::cout <<  "Percentage of items that are bad in a set: " << line[3] << std::endl;
	
		std::getline(file,line[4]);	
		std::cout <<  "Items sampled from each set: " << line[4] << std::endl;
	

	
	MonteCarlo obj1(line[0],line[1],line[2],line[3],line[4]);
	
	obj1.PrintBatches();

	obj1.CheckBatches();




		std::getline(file2,line2[0]);	
		std::cout <<  "Number of batches of items: " << line2[0] << std::endl;

		std::getline(file2,line2[1]);	
		std::cout <<  "Number of items in each batch: " << line2[1] << std::endl;

		std::getline(file2,line2[2]);	
		std::cout <<  "Percentage of batches containing bad items: " << line2[2] << std::endl;

		std::getline(file2,line2[3]);	
		std::cout <<  "Percentage of items that are bad in a set: " << line2[3] << std::endl;
	
		std::getline(file2,line2[4]);	
		std::cout <<  "Items sampled from each set: " << line2[4] << std::endl;


	
	MonteCarlo obj2(line2[0],line2[1],line2[2],line2[3],line2[4]);
	
	obj2.PrintBatches();

	obj2.CheckBatches();


		std::getline(file3,line3[0]);	
		std::cout <<  "Number of batches of items: " << line3[0] << std::endl;

		std::getline(file3,line3[1]);	
		std::cout <<  "Number of items in each batch: " << line3[1] << std::endl;

		std::getline(file3,line3[2]);	
		std::cout <<  "Percentage of batches containing bad items: " << line3[2] << std::endl;

		std::getline(file3,line3[3]);	
		std::cout <<  "Percentage of items that are bad in a set: " << line3[3] << std::endl;
	
		std::getline(file3,line3[4]);	
		std::cout <<  "Items sampled from each set: " << line3[4] << std::endl;



	MonteCarlo obj3(line3[0],line3[1],line3[2],line3[3],line3[4]);
	
	obj3.PrintBatches();

	obj3.CheckBatches();


		std::getline(file4,line4[0]);	
		std::cout <<  "Number of batches of items: " << line4[0] << std::endl;

		std::getline(file4,line4[1]);	
		std::cout <<  "Number of items in each batch: " << line4[1] << std::endl;

		std::getline(file4,line4[2]);	
		std::cout <<  "Percentage of batches containing bad items: " << line4[2] << std::endl;

		std::getline(file4,line4[3]);	
		std::cout <<  "Percentage of items that are bad in a set: " << line4[3] << std::endl;
	
		std::getline(file4,line4[4]);	
		std::cout <<  "Items sampled from each set: " << line4[4] << std::endl;
	

	
	MonteCarlo obj4(line4[0],line4[1],line4[2],line4[3],line4[4]);
	
	obj4.PrintBatches();

	obj4.CheckBatches();

	std::cout << std::endl;


	MCPartTwo bog;
	bog.RunAnalyticalModel();
	bog.RunSimulationModel();

	return 0;
}
