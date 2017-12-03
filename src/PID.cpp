#include <iostream>
#include "PID.h"

using namespace std;

// TODO: Complete the PID class.

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_init, double Kd_init, double Ki_init) {
	Kp = Kp_init;
	Kd = Kd_init;
	Ki = Ki_init;

	p_error = 0.0;
	i_error = 0.0;
	d_error = 0.0;

	cte = 0.0;
	total_error = 0.0;
}

void PID::UpdateError(double new_cte) {
	// if(new_cte * cte < 0) total_error /= 10;
	total_error += cte;
	cte = new_cte;
}

double PID::TotalError() {
	cout << "Total Error: " << total_error << endl;
	return total_error;
}
