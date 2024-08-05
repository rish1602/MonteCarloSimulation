# MonteCarloSimulation
In this project I've used Monte Carlo simulation to generate random numbers. For this I used PARK MILLER algorithm &amp; SCHRAGE algorithm

=>	Relying on the rand function provided with the C++ standard is unreliable. Not only is rand implementation specific, because it varies across multiple vendor compilers, but we are 
    unaware of the efficiency of each implementation. This leads to difficulties in cross-platform testing as we cannot guarantee reproducibility.

=>	**Simple C++ example for generating random numbers is**

#include<iostream>
#include<cstdlib>
#include<ctime>

int main()
{
    srand(time(0));   //this seeds time from 0 because every time a new time is generated which further generates a new random number. If this time was not seeded, then a same set of number would be generated


    int32_t upper_bound= 50, lower_bound=10;   //from here we set the upper and lower boundary and we want the random number to be within these boundary
    
    for(int32_t i=0; i<5; ++i)
    {
        int32_t random_number= rand();   //random number generated from rand() function
        std::cout<<"random number "<<i<<" is: "<<random_number%(upper_bound-lower_bound)<<"\n";
    }
}

=>	So we’ll generate our own random number generator
   ====================================================

=>	So in the project we have made 4 files.

1)	**random.h** – which contains protected data member and virtual member functions
2)	**lin_con_gen.h** - here this file has class which inherits publically from class in random.h
3)	**lin_con_gen.cpp** — here it defines the member functions and initializes constructors declared in class in lin_con_gen.h
4)	**main.cpp** - here is the main function to call constructors and functions of lin_con_gen.cpp
==================================================================================


=>	We will study them step by step, but before that we should know the a few algorithms used for generating random numbers using linear congruence generator LCG-

**Park Miller Algorithm** is a Linear Congruential Generator LCG with general formula-
=>	Xn+1 = ( a.Xn ) mod m
=>	where m=prime number,  a=constant or an element of higher multiplicative order, 
    X0= initial seed with value 1, Xn= current seed
=>	The above is a recursive equation
=>	Park Miller algorithm suggests predefined parameter with value m=2147483647 = 2^31-1  i.e. prime number  and  a=16807 =7^5 


**Schrage** introduced another version of the above Park Miller algorithm
=>	( a.Xn )mod m = g(Xn) + m.h(Xn)
=>	where g(Xn) = a( Xn mod q) - r( Xn div q)
=>	here q= m div a = 2147483647 / 16807
=>	here r= m mod a = 2147483647 % 16807
=>	if r>q then h(Xn) can be either 0 or 1   so,  if g(Xn)<0 then h(Xn)=1     => if g(Xn)>0 then h(Xn)=0

==================================================================================

**So How is the the code work flow**

1)	We start with main.cpp. We define two variables and a vector as follows- 
                       => unsigned long init_seed=1;
	                => unsigned long num_draws=20;
	                => std::vector<double>vec_random_draws(num_draws,0.0);

2) We initialize the object of LinearCongruentialGenerator object with above variables i.e. init_seed and num_draws. LinearCongruentialGenerator(num_draws, init_seed);

3) It goes to file lin_con_gen.h where there is constructor LinearCongruentialGenerator constructor declared. From there it goes to file lin_con_gen.cpp where constructor is defined. It 
   initializes the value as _num_draws=num_draws; _init_seed=init_seed; 

4) Now there is a delegating constructor which calls the constructor RandomGenerator(_nums_draws,_init_seed) in the file random.h. This is called so that the protected variables of 
   random.h i.e. init_seed, curr_seed and num_draws can be initialized as they will be used in lin_con_gen.cpp class, which inherits publically from random.h,  to generate values.

5)	After that in main.cpp, the object of LinearCongruentialGenerator is used to call the random number generating function in lin_con_gen.cpp. This will generate random numbers and 
    convert them in uniform range between (0,1) by multiplying the generated number by max_multiplier. 

6)	The numbers are stored in vector which can be outputted. 


