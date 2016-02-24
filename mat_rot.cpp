#include <math.h>
#include <iostream>
#include <eigen3/Eigen/Dense>

using Eigen::Matrix3d;
using Eigen::Vector3d;

#define COUNT 10000
#define OHM (2.0*M_PI/COUNT)

int main()
{
	Matrix3d m;
	Vector3d v;
#if 1
	m <<	0.0,	OHM,	-OHM,
			-OHM,	0.0,	OHM,
			OHM,	-OHM,	0.0;
#else
	m <<	0.0,	OHM,	0.0,
			-OHM,	0.0,	0.0,
			0.0,	0.0,	0.0;
#endif
	v <<	1.0,	0.0,	0.0;
	for(int i = 0; i < COUNT; i++){
		std::cout << v(0) << " ";
		std::cout << v(1) << " ";
		std::cout << v(2) << " ";
		std::cout << std::endl;
		v = v + m * v;
//		v.normalize();
	}
}

