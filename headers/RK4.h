#ifndef RK4_H
#define RK4_H

#include <vector>
#include "../eigen/Eigen/Dense"

typedef Eigen::VectorXd (*vector_function)(double, Eigen::VectorXd);

class RK4Solver {
	size_t m_vecsize = 0; // Size of the vectors
	size_t m_timesize = 0; // Size of the time vector
	double m_h = 0; // Current step size
	bool m_integrated = false;

	// Initialise the initial and intermediate points
	// See link for more details: 
	Eigen::VectorXd m_y0;
	Eigen::VectorXd m_k1;
	Eigen::VectorXd m_k2;
	Eigen::VectorXd m_k3;
	Eigen::VectorXd m_k4;

	// Store the time vector
	std::vector<double> m_ts;

public:
	// Default Empty Constructor
	RK4Solver(){};

	// Default Constructor
	RK4Solver(std::vector<double>& t_vector, Eigen::VectorXd y0) {
		m_y0 = y0; 
		m_ts = t_vector;
		m_vecsize = m_y0.size();
		m_timesize = m_ts.size();

		// Initialize the intermediate points
		m_k1 = Eigen::VectorXd::Zero(m_vecsize);
		m_k2 = Eigen::VectorXd::Zero(m_vecsize);
		m_k3 = Eigen::VectorXd::Zero(m_vecsize);
		m_k4 = Eigen::VectorXd::Zero(m_vecsize);
	}

	// Perform integration with RK4
	std::vector<Eigen::VectorXd> integrate(vector_function func);
};

// template <typename T>
// template <typename T, size_t Size> using Vector = Eigen::Matrix<T, Size, 1>;

// // Store the function to be solved as a pointer in a variable
// Eigen::VectorXd(*m_func)(Eigen::VectorXd, double);

#endif