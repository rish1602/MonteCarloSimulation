#ifndef _LINEAR_CONGRUENTIAL_GENERATOR_CPP_
#define _LINEAR_CONGRUENTIAL_GENERATOR_CPP_

#include "lin_con_gen.h"

// Park Miller Algorithm is a Linear Congruential Generator LCG with general formula-
// Xn+1 = ( a.Xn ) mod m
// where m=prime number,  a=constant or a element of higher multiplicative order, X0= initial seed=1, Xn= current seed
// The above is a recursive equation
// Park Miller suggested parameter m=2147483647  and a=16807


// Schrage introduced another version where in above equation
// ( a.Xn )mod m = g(Xn) + m.h(Xn)
// where g(Xn) = a( Xn mod q) - r( Xn div q)
// here q= m div a = 2147483647 / 16807
// here r= m mod a = 2147483647 % 16807
// if r>q then h(Xn) can be either 0 or 1   => if g(Xn)<0 then h(Xn)=1    ans  => if g(Xn)>0 then h(Xn)=0




//define Park & Miller algorithm constants
const unsigned long a=16807;  //7^5= 16807
const unsigned long m=2147483647;  //2^31-1  i.e. a prime number

//define Schrage's algorithm constants
const unsigned long q=127773; //m div a or m/a
const unsigned long r=2836; //m mod a 


LinearCongruentialGenerator::LinearCongruentialGenerator(unsigned long _num_draws, unsigned long _init_seed):
RandomNumberGenerator(_num_draws, _init_seed)
{
	if(_init_seed==0)
	{
	   init_seed=1; curr_seed=1; //if initial seed set 0, we set initial seed & current seed 1 as LCG doesn't work with seed 0
	}

	max_multiplier= 1.0/(1.0 + (m-1)); //max_multiplier is percomputed value for converting random unsigned long to any number between 0 & 1

}

//obtain a random unsigned long integer
unsigned long LinearCongruentialGenerator::get_random_integer()
{
	unsigned long k=0;
	k= curr_seed/q;
	curr_seed= a*( curr_seed - k*q) - r*k;  //here g(Xn) is eaual to curr_seed 

	if(curr_seed < 0) curr_seed+=m; 

	return curr_seed; 
}


//create a vector draws where each element is between (0,1)
void LinearCongruentialGenerator::get_uniform_draws(std::vector<double>&draws)
{
	for(unsigned long i=0; i<num_draws; ++i)
	{
		draws[i]= get_random_integer()*max_multiplier; 
	}
}

#endif






























