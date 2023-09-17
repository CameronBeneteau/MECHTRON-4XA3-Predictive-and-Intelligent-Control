#include <iostream>
#include <fstream>
#include <cmath>

#include <Eigen/Dense>

Eigen::VectorXd u_func(double t, const Eigen::VectorXd &in)
{
	Eigen::VectorXd out;
	return (out);
}

Eigen::VectorXd m_func(double t, const Eigen::VectorXd &in)
{
	Eigen::VectorXd out;

	double g = -9.81;

	//	Eigen::VectorXd u(1);
	Eigen::MatrixXd A(4, 4);
	Eigen::MatrixXd k(4, 1);
	A << 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0;
	k << 0, 0, 0, g;
	// out=  -in +10*(u-in);
	// out(0)= out(0)+3;
	// out<<3;

	out = A * in + k;
	return (out);
}

Eigen::VectorXd run(double t, const Eigen::VectorXd &in, double h)
{
	Eigen::VectorXd k1, k2, k3, k4;
	k1 = m_func(t, in);
	k2 = m_func(t + h / 2, in + (h / 2) * k1);
	k3 = m_func(t + h / 2, in + (h / 2) * k2);
	k4 = m_func(t + h, in + h * k3);

	return in + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
}

void solve(const Eigen::VectorXd &x0, double h, double time)
{
	Eigen::IOFormat fmt(8, 0, ", ", "\t", "", "", "", "");
	std::ofstream myFile;
	myFile.open("OUT");

	int i;
	double t;
	t = 0;
	Eigen::VectorXd x = x0;

	while (t < time)
	{
		x = run(t, x, h);
		myFile << t << "\t" << x.format(fmt) << std::endl;
		t = t + h;
	}
}

int main(void)
{
	double V = 50;
	double alpha = 45 * M_PI / 180;

	Eigen::VectorXd x(4);
	x << 0, V * cos(alpha), 0, V * sin(alpha);

	solve(x, .01, 8);
}
