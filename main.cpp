#include<iostream>

#include "lin_con_gen.cpp"

int main(int argc, char **argv)
{
	//set the initial seed and dimentions of Random Number Generator
	unsigned long init_seed=1;
	unsigned long num_draws=20;
	std::vector<double>vec_random_draws(num_draws,0.0);

	LinearCongruentialGenerator lcg(num_draws,init_seed); 
	lcg.get_uniform_draws(vec_random_draws);


	//output the random draws
	for(unsigned long i=0; i<num_draws; ++i)
		std::cout<<vec_random_draws[i]<<"\n";

}
