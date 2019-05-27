#ifndef __ios
#define __ios
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <Eigen/Dense>
#endif

#include <interactive_init.h>

void print_test()
{
	std::cout<<"Linking test succeded!"<<'\n';	
}
	
//Draw the domain, it will be replace by something more sofisticated in the future
Draw_domain::Draw_domain()
{
	//Definizione del sistema e input (+input sanitasing):
	
	std::cout<<"Choose the domain width and height (just integers). "<<'\n';
	for (;;) 
	{
		std::cout<<"x: ";
	        std::cin >> width;
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	        if (std::cin.fail()) 
		{
	        	std::cerr << "Not a valid input." << std::endl;
	        	std::cin.clear();
	        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        	continue;
	        }
	
	        if (width < 1 || width > 10000)
	       	{
	       		 std::cerr << "Sorry, the number is out of range." << std::endl;
	           	 continue;
	        }
		//Valid entry
		std::cout<<"x = "<<width<<'\n';
	        break;
    	}
	
	
	for (;;)
       	{
		std::cout<<"y: ";
	        std::cin >> height;
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	        if (std::cin.fail()) {
	        	std::cerr << "Not a valid input." << std::endl;
	        	std::cin.clear();
	        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	         	continue;
	        }
	
	        if (height < 1 || height > 10000)
	       	{
	        	std::cerr << "Sorry, the number is out of range." << std::endl;
	        	continue;
	        }
		//Valid entry
		std::cout<<"y = "<<height<<'\n';
	        break;
    	}
	if ( height < 100 && width <60)
	{
		std::cout<<'\n'<<"This is your domain:"<<std::endl;
		for (int j=0; j<height+2; j++)
		{
			if(j==0 || j==height+1)
			{
				std::cout<<'\n'<<"  ";
				for (int i=0; i<width; i++)
				{
				std::cout<<"- ";	
	
				}
				std::cout<<" ";
			}
			else
			{
				std::cout<<'\n'
					 <<"| ";
				for (int i=0; i<2*(width); i++)
				{
					std::cout<<" ";
				}
				std::cout<<"|";
				
			}
	
		}
		std::cout<<'\n';
	}
	else
	{
		std::cout<<"\n#####################################################################"<<std::endl;
		std::cout<<"# Your domain is too big to be drawn, still good to compute though. #"<<std::endl;
		std::cout<<"#####################################################################\n"<<std::endl;
	}

}
		



//Choose bundary conditions, will be changed as well
define_bc::define_bc()
{
	std::cout<<"Choose the boundary conditions:"<<'\n'
		 <<"      3      "<<'\n'
		 <<"   - - - -   "<<'\n'
		 <<"  |       |  "<<'\n'
		 <<"4 |       | 2"<<'\n'
		 <<"  |       |  "<<'\n'
		 <<"   - - - -   "<<'\n'
		 <<"      1      "<<'\n'
	 	 <<"Inlet-->10"<<'\n'
	 	 <<"Outlet-->11"<<'\n'
	 	 <<"Wall-->12"<<'\n';

	//Test the validity of each boundary conditions, if invalid it throws an exception and will prompt the user to insert a new one
	int j = 0;
	for (auto i : boundary_values)
	{
		std::cout<<"Condition n°"<<j+1<<": ";
		std::cin>>boundary_values[j];
		if (test_bc == std::find(std::begin(accepted_boundary_values), std::end(accepted_boundary_values), boundary_values[j]) || std::cin.fail() )
		{
    			std::cin.clear();
		        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw std::runtime_error("Invalid Boundary Condition");
		}
    		std::cin.clear();
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		j++;
	}
}

