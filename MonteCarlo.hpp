#ifndef MONTECARLO_H
#define MONTECARLO_H

//#include <algorithm>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <time.h>

class MonteCarlo{


	private:
		int numOfBatch;
		int numItems;
		int percentBadBatches;
		int percentBadness;
		int numPicked;
		int numTotalBadBatches;


	public:
		MonteCarlo(std::string numOfBatch,std::string numItems, std::string percentBadBatches, std::string percentBadness, std::string numPicked);
		void PrintBatches();
		void DeleteBatches();
		void CheckBatches();



};


#endif
