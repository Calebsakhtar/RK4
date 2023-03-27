#include <math.h>
#include "../headers/RK4.h"

std::vector<double> linspace(const double start_val, const double end_val,
	const size_t num_pts) {
	std::vector<double> results = {start_val};
	const double increment = (end_val - start_val) / static_cast<double>(num_pts - 1);

	for (size_t i = 1; i < num_pts; i++) {
		results.push_back(results[i - 1] + increment);
	}

	return results;
}

Eigen::VectorXd f(double t, Eigen::VectorXd x) {
	Eigen::Matrix2d A;
	A << 1, 2,
		 3, 4;

	return A * x;
}

int main() {
	Eigen::Vector2d y0;
	y0 << 7, 22;

	std::vector<double> times = linspace(0, 10, 201);
	
	RK4Solver solver(times, y0);

	solver.integrate(f);
	solver.print_results();

	return 0;
}