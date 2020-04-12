#ifndef MONTECARLO_H
#define MONTECARLO_H

//#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>

class MonteCarlo{


	private:
		int numOfBatch;
		int numItems;
		int percentBadBatches;
		int percentBadness;

	public:
		MonteCarlo(std::string numOfBatch,std::string numItems, std::string percentBadBatches, std::string percentBadness);
		void PrintBatches();
		void DeleteBatches();
		void CheckBatches();



};


#endif
