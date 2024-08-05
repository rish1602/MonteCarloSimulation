#ifndef _LIN_CON_GEN_H_
#define _LIN_CON_GEN_H_

#include "random.h"

class LinearCongruentialGenerator:public RandomNumberGenerator
{
	private:
		double max_multiplier;

	public:
		LinearCongruentialGenerator(unsigned long _num_draws, unsigned long _init_seed=1);
		
		//function to create random integers,which'll be transformed into uniform integers in range (0,1)
		virtual unsigned long get_random_integer();

		//fills a vector with uniform random variables in interval (0,1)
		virtual void get_uniform_draws(std::vector<double>&draws);

		//virtual destructor
		virtual ~LinearCongruentialGenerator(){}

};

#endif
