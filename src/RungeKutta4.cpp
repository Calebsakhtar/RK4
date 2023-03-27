#include "../headers/RK4.h"

int main() {

	Eigen::VectorXd kf = Eigen::VectorXd::Constant(1, 1, 0);
	kf.resize(10);

	return 0;
}