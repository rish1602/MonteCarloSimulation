#ifndef _RANDOM_H
#define _RANDOM_H

#include<vector>

class RandomNumberGenerator
{
                //pure virtual function are written using keyword "virtual" and assigning =0; These functions'll be overridden in child class. Meaning that in base class they dont have any definition and when inherited in child class, their own definition will be written in the child class, thus overriding the function. Thus we have written VIRTUAL FUNCTION in class, making it as ABSRACT BASE CLASS. 

	protected:
		unsigned long init_seed; //initial random seed value
		unsigned long curr_seed;  //current random seed value
		unsigned long num_draws; //dimensions of random number generator

	public:
		RandomNumberGenerator(unsigned long _num_draws, unsigned long _init_seed):
			num_draws(_num_draws), init_seed(_init_seed), curr_seed(_init_seed){}

		virtual unsigned long get_random_seed() const { return curr_seed; }
		virtual void set_random_seed(unsigned long _seed){ curr_seed= _seed; }
		virtual void reset_random_seed(){ curr_seed= init_seed; }
		virtual void set_num_draws(unsigned long _num_draws){num_draws= _num_draws; }

		//function to create random integers,which'll be transformed into uniform integers in range (0,1)
		virtual unsigned long get_random_integer()=0;
		
		//fills a vector with uniform random variables in interval (0,1)
		virtual void get_uniform_draws(std::vector<double>&draws)=0; 
		
		virtual ~RandomNumberGenerator(){} //virtual destructor
		


};

#endif



