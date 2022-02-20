// Verilator generated library/class.
#include "VM10to1.h"

// Verilator libraries.
#include "verilated.h"
#include "verilated_vcd_c.h" 

// C++ libraries.
#include <stdlib.h>
#include <iostream>

using dut_type = VM10to1;
uint64_t global_time = 0;

void advance_sim(dut_type* top, VerilatedVcdC* trace)
{
	trace->dump(global_time);
	top->eval();
	++global_time; 
}


int main()
{

    // Value generator.
	srand(1234);
	int i = 0;
	int pass=0;
	int fail=0;

	dut_type* top = new dut_type;
    Verilated::traceEverOn(true);
    VerilatedVcdC* trace = new VerilatedVcdC;
    top->trace(trace, 99);
    trace->open("M10to1.vcd");
	
	while(i<100000)
	{
	
		int I0 = rand()%2;
		int I1 = rand()%2;
		int I2 = rand()%2;
		int I3 = rand()%2;
		int I4 = rand()%2;
		int I5 = rand()%2;
		int I6 = rand()%2;
		int I7 = rand()%2;
		int I8 = rand()%2;
		int I9 = rand()%2;

		int S0 = rand()%2;
		int S1 = rand()%2;
		int S2 = rand()%2;
		int S3 = rand()%2;
		

		// Feed data to top.
		top->I0 = I0 & 1;
		top->I1 = I1 & 1;
		top->I2 = I2 & 1;
		top->I3 = I3 & 1;
		top->I4 = I4 & 1;
		top->I5 = I5 & 1;
		top->I6 = I6 & 1;
		top->I7 = I7 & 1;
		top->I8 = I8 & 1;
		top->I9 = I9 & 1;

		top->S0 = S0 & 1;
		top->S1 = S1 & 1;
		top->S2 = S2 & 1;
		top->S3 = S3 & 1;
		

		// Model the behavior of the top.
		int expected_sum =( (I0 & ~S3 & ~S2 & ~S1 & ~S0) | (I1 & ~S3 & ~S2 & ~S1 & S0) | 
    (I2 & ~S3 & ~S2 & S1 & ~S0) | (I3 & ~S3 & ~S2 & S1 & S0) | (I4 & ~S3 & S2 & ~S1 & ~S0) | 
    (I5 & ~S3 & S2 & ~S1 & S0) | (I6 & ~S3 & S2 & S1 & ~S0) | (I7 & ~S3 & S2 & S1 & S0) | 
    (I8 & S3 & ~S2 & ~S1 & ~S0) | (I9 & S3 & ~S2 & ~S1 & S0) );
	
			
		// Simulate/evaluate/progress time.
		advance_sim(top, trace);	
		
		// Compare results.
		int out = ((int)top->out) & 1;


		bool sum_success = (out == expected_sum);

		if (sum_success)
		{
		  pass++;
		}

		else
		{
		  fail++;
		}
		i++;
	}

	trace->close();

	std::cout << "\nPassed amount of tests:" << std::endl;
	std::cout << pass << std::endl;	
	std::cout << "\nFailed amount of tests:" << std::endl;
	std::cout << fail << std::endl;	

}
