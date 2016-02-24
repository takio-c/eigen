#include <math.h>
#include <iostream>
#include <eigen3/Eigen/Geometry>

using Eigen::Quaterniond;
using Eigen::Vector3d;

#define COUNT 10000
#define OHM (2.0*M_PI/COUNT)

int main()
{
	Quaterniond q, w;
	Vector3d v(1, 1, 1);
	v.normalize();
	q = Eigen::AngleAxisd( 0.0f, Vector3d::UnitZ() );
	w = Eigen::AngleAxisd( OHM, v );
	for(int i = 0; i < COUNT; i++){
		v = Vector3d::UnitX();
		v = q.matrix() * v;
		std::cout << v(0) << " ";
		std::cout << v(1) << " ";
		std::cout << v(2) << " ";
		std::cout << std::endl;
		q = q + w * q;
		q.normalize();
	}
}

