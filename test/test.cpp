#define CATCH_CONFIG_MAIN

#include "catch/catch.hpp"
//#include "../Calculations.hpp"
#include "../Customer.hpp"
#include "../Simulation.hpp"

//#include <string>
#include <vector>

/*******************************************************************
 Student Name:JAMES RUTGER
 File Name: Test.cpp
 Assignment: Project 2 - Priority Queue

 Data Structures and Algorithms 2
 Dr.John Coffey

 Class Description:

*****************************************************************/

TEST_CASE ("Runway Simulation")
{
//	const int n = 2000;//n
	//int M = 10;

//	Customer array[n];

	//int serverAvailableCount=10;

//	for(int i=0;i<n;i++)
//	{
//		Customer = new Customer array[i];
//	}

//	while(!pq.empty())
//	{

//		if(moreArrivals && pq.size <=M+1)
//		{
//			//add to pq
//			}
			
//	}


//	Customer* obj = new Customer(0.1,-1,-1,nullptr);
//	Customer* obj1 = new Customer(0.2,-1,-1,nullptr);
//	Customer* obj2 = new Customer(0.3,-1,-1,nullptr);
//	Customer* obj3 = new Customer(0.4,-1,-1,nullptr);

   	//std::priority_queue <Customer*, std::vector<Customer*>, Customer> pq; 

	//std::queue <Customer*> fifo;
	
//	pq.push(obj2);
//	pq.push(obj3);
//	pq.push(obj);	
//	pq.push(obj1);

	// One by one extract items from min heap 
    /*	while (pq.empty() == false) 
    	{ 
        	Point p = pq.top(); 
        	cout << "(" << p.getX() << ", " << p.getY() << ")"; 
        	cout << endl; 
        	pq.pop(); 
    	} 
*/

//	Customer* popped1 =  pq.top();
//	float topNum = popped1->arrivalTime;
//	REQUIRE(topNum == 0.1f);

//	pq.pop();
	
//	Customer * popped2 =  pq.top();
//	float topNum1 = popped2->arrivalTime;
//	REQUIRE(topNum1 == 0.2f);

//	pq.pop();

//	Customer * popped3 = pq.top();
//	float topNum2 = popped3->arrivalTime;
//	REQUIRE(topNum2 == 0.3f);


	Simulation sim(1000,2,3,2);

	sim.RunSimulation();

	std::cout << sim.GetServiceWaitProbability()  << "\n";

	std::cout << sim.GetAvgTimeInSystem();
	


}
