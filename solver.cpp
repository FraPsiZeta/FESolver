#include <iostream>
#include <cmath>
#include <vector>


//Draw the domain, it will be replace by something more sofisticated in the future
struct Draw_domain
{
	Draw_domain(int height, int width)
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

};

struct define_bc
{
	
	int boundary_values[4];
	
	define_bc()
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
		 	 <<"Wall-->12"<<'\n'
		 	 <<"Condition n°1: ";
		std::cin>>boundary_values[0];
		std::cout<<"Condition n°2: ";
		std::cin>>boundary_values[1];
		std::cout<<"Condition n°3: ";
		std::cin>>boundary_values[2];
		std::cout<<"Condition n°4: ";
		std::cin>>boundary_values[3];
	}
};

class Mesh
{
private:
	int num_elements;




};

int main()
{

//Definizione del sistema e input:
int width, height;

std::cout<<"Choose the domain width and height. "<<'\n';
std::cout<<"x: ";
std::cin>>width;
std::cout<<"y: ";
std::cin>>height;

Draw_domain rect(height,width);

define_bc conditions;



return 0;
}
