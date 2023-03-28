#include <math.h>
#include "../headers/RK4.h"

Eigen::VectorXd f(const double t, const Eigen::VectorXd& x) {
	Eigen::Matrix2d A;
	A << 1, 2,
		 3, 4;

	return A * x;
}

int main() {
	Eigen::Vector2d y0;
	y0 << 7, 22;

	std::vector<double> times = MathTools::linspace(0, 10, 201);
	
	RK4Solver solver(times, y0);

	solver.integrate(f);
	solver.print_results();

	return 0;
}