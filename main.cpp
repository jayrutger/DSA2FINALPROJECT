#include <iostream>
#include <fstream>
#include <string>
#include "MonteCarlo.hpp"

int main(){

	std::ifstream file("t1.txt");
	std::ifstream file2("t2.txt");
	std::ifstream file3("t3.txt");
	std::ifstream file4("t4.txt");

	std::string line[5];
	std::string line2[5];
	std::string line3[5];
	std::string line4[5];
	for(int i=0; i < 5; i++){

		std::getline(file,line[i]);	
		std::cout << line[i] << std::endl;

	}

	MonteCarlo obj1(line[0],line[1],line[2],line[3]);
	
	obj1.PrintBatches();

	
//	obj1.DeleteBatches();
	
/*
	for(int i=0; i < 5; i++){

		std::getline(file2,line2[i]);	
		std::cout << line2[i] << std::endl;
	}

	MonteCarlo obj2(line2[0],line2[1],line2[2],line2[3]);
	
	for(int i=0; i < 5; i++){

		std::getline(file3,line3[i]);	
		std::cout << line3[i] << std::endl;
	}

	MonteCarlo obj3(line3[0],line3[1],line3[2],line3[3]);
	
	for(int i=0; i < 5; i++){

		std::getline(file4,line4[i]);	
		std::cout << line4[i] << std::endl;
	}

	MonteCarlo obj4(line4[0],line4[1],line4[2],line4[3]);
*/	
	return 0;
}
