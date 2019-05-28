#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <Eigen/Dense>

#include <interactive_init.h>


class Element
{
private:
	int dof;




};

int main()
{

	
	Draw_domain rect;
	
	bool loop=true;
	while(loop)
	{
		loop=false;
		try{
		define_bc conditions; } catch (std::runtime_error err){
			std::cout<<err.what()<<"\nWant to try again? y or n"<<std::endl;
			char c;
			std::cin>> c;
	            	std::cin.clear();
	            	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if(!std::cin || c == 'n')
			{
				std::cout<<"Quitting..."<<'\n';
				return -1;
			}
	       		loop = true;	
		}
	}
	//Test matrix Eigen	
	Eigen::MatrixXd m(2,2);
	m(0,0) = 3;
	m(1,0) = 2.5;
 	m(0,1) = -1;
     	m(1,1) = m(1,0) + m(0,1);
 	std::cout << m << std::endl;
	

	print_test();	
	return 0;	
}
