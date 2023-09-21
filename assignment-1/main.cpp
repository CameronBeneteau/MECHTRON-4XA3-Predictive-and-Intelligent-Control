#include "LTI.h"

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cmath>

using namespace std;

void testLTI(void)
{
   double V = 50;
   double alpha = 45 * M_PI / 180; // radians
   double g = -9.81;
   double h = 0.001;                             // step size
   double maxTime = 2 * V * sin(alpha) / abs(g); // seconds

   int n = 4;

   // SISO
   Eigen::MatrixXd A(n, n);
   Eigen::MatrixXd B(n, 1);
   Eigen::MatrixXd C(n, n);
   Eigen::MatrixXd k(n, 1);

   Eigen::VectorXd x(n);
   Eigen::VectorXd u(1);

   A << 1, h, 0, 0, 0, 1, 0, 0, 0, 0, 1, h, 0, 0, 0, 1;
   B << 0, 0, 0, 0;
   C << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;
   k << 0, 0, 0.5 * g * h * h, g * h;

   x << 0, V * cos(alpha), 0, V * sin(alpha);
   u << 1;

   std::cout << "A: \n"
             << A << std::endl;
   std::cout << "B: \n"
             << B << std::endl;
   std::cout << "C: \n"
             << C << std::endl;

   // Construct the system
   LTISystem lti(A, B, C, k);
   lti.init(x);

   Eigen::IOFormat fmt(8, 0, ", ", "\t", "", "", "", "");
   std::ofstream myFile;
   myFile.open("OUT");

   for (int i = 0; i <= maxTime / h; i++)
   {
      lti.update(u);
      myFile << i * h << "\t" << lti.output().format(fmt) << std::endl;
   };

   myFile.close();
}

int main(void)
{
   testLTI();
   return (0);
}
