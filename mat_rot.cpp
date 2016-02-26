#include <math.h>
#include <iostream>
#include <eigen3/Eigen/Dense>

using Eigen::Matrix3d;
using Eigen::Vector3d;

#define COUNT 1000
#define OHM (6.0*M_PI/COUNT)

int main()
{
	Matrix3d m;
	Vector3d v, axis;
	axis << 1.0, 1.0, 1.0;
	axis.normalize();
#if 1
	m <<	0.0,			axis(2)*OHM,	-axis(1)*OHM,
			-axis(2)*OHM,	0.0,			axis(0)*OHM,
			axis(1)*OHM,	-axis(0)*OHM,	0.0;
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
		v.normalize();
	}
}

