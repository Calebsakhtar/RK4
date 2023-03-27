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

	// Initialise the lists
	std::vector<double> m_ts; // Times to evaluate the integration at
	std::vector<Eigen::VectorXd> m_solutions; // Integration results at times m_ts

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

	// Perform the integration using the RK4 method.
	// See https://www.sciencedirect.com/topics/mathematics/runge-kutta-method#:~:text=Runge%E2%80%93Kutta%20method%20is%20an,high%20order%20derivatives%20of%20functions.
	void integrate(vector_function func);

	// Write results to a file
	bool print_results() const;
};

// template <typename T>
// template <typename T, size_t Size> using Vector = Eigen::Matrix<T, Size, 1>;

// // Store the function to be solved as a pointer in a variable
// Eigen::VectorXd(*m_func)(Eigen::VectorXd, double);

#endif