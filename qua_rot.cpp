#include <math.h>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

using Eigen::Quaterniond;
using Eigen::Vector3d;

#define COUNT 1000
#define OHM (6.0*M_PI/COUNT)

int main()
{
	Quaterniond q, w;
	Vector3d v(1, 1, 1);
	v.normalize();
	q = Eigen::AngleAxisd( 0.0f, Vector3d::UnitZ() );
	for(int i = 0; i < COUNT; i++){
		Vector3d b = q.matrix() * Vector3d::UnitX();
		std::cout << b(0) << " ";
		std::cout << b(1) << " ";
		std::cout << b(2) << " ";
#if 1
		w.x() = w.y() = w.z() = v(0) * sin(0.5 * OHM);
		w.w() = cos(0.5 * OHM);
		q = w * q;
#else
		w.x() = w.y() = w.z() = v(0) * 0.5 * OHM;
		w.w() = 0.0;
		Quaterniond dq = w * q;
		q.x() += dq.x();
		q.y() += dq.y();
		q.z() += dq.z();
		q.w() += dq.w();
		q.normalize();
#endif
		std::cout << std::endl;
	}
}

