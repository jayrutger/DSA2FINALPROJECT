#ifndef MCPARTTWO_H
#define MCPARTTWO_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <vector>
#include <numeric>

class MCPartTwo{


	private:
		int numSimulatedDays;
		int numCategories;
		std::vector <std::string> line;
		std::vector <int> numOccurences;
		std::vector <int> begRange;	
		std::vector <int> endRange;


	public:
		MCPartTwo();
		void GetValues();
		void RunAnalyticalModel();










};

#endif
