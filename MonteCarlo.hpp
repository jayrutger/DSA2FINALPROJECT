#ifndef MONTECARLO_H
#define MONTECARLO_H

#include <string>
#include <iostream>
#include <sstream>

class MonteCarlo{


	private:
		int numOfBatch;
		int numItems;
		int percentBadBatches;
		int percentBadness;

	public:
		MonteCarlo(std::string numOfBatch,std::string numItems, std::string percentBadBatches, std::string percentBadness);
void PrintBatches();




};


#endif
