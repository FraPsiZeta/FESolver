#ifndef __ios
#define __ios
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <Eigen/Dense>
#endif

void print_test();

struct Draw_domain
{
public:
	int width, height;
	
	Draw_domain();

};

struct define_bc
{
public:

	int boundary_values[4];
 	int accepted_boundary_values[3] {10, 11, 12};	
	int* test_bc = std::end(accepted_boundary_values);

	define_bc();	
};
