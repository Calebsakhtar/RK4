#include "../headers/RK4.h"

void RK4Solver::integrate(vector_function func) {
	// Perform the integration using the RK4 method.
	// See https://www.sciencedirect.com/topics/mathematics/runge-kutta-method#:~:text=Runge%E2%80%93Kutta%20method%20is%20an,high%20order%20derivatives%20of%20functions.

	// Clear the solution vector and initialize it
	m_solutions.clear();
	m_solutions.push_back(m_y0);

	// Perform the RK4 integration at each time
	for (size_t i = 1; i < m_timesize; i++) {
		m_h = m_ts[i] - m_ts[i - 1];
		m_k1 = m_h * func(m_ts[i - 1], m_solutions[i - 1]);
		m_k2 = m_h * func(m_ts[i - 1] + 0.5 * m_h, m_solutions[i - 1] + 0.5 * m_k1);
		m_k3 = m_h * func(m_ts[i - 1] + 0.5 * m_h, m_solutions[i - 1] + 0.5 * m_k2);
		m_k4 = m_h * func(m_ts[i - 1] + m_h, m_solutions[i - 1] + m_k3);
		m_solutions.push_back(m_solutions[i - 1] + (m_k1 + 2 * m_k2 + 2 * m_k3 + m_k4) / 6);
	}
	
	m_integrated = true;
}

// Print out the outcome
bool RK4Solver::print_results() const {


	// If the integration has not been performed, do not print anything.
	if (m_integrated == false) { return false; }
	

}
