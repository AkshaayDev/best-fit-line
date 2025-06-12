#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

// (x,y) sample points
std::vector<std::pair<double, double>> points = {
	{0, 0},
	{50, 2},
	{100, 3.2},
	{150, 5},
	{200, 6.9},
	{250, 8.5},
	{300, 9.8},
};

// Approximate the dataset with y = mx + c
double m = 0; // Gradient
double c = 0; // y-Intercept
double learningRate = 0.00000001;
int iterations = 10000000;

double MSE(double m, double c) { // Mean Squared Error
	double sum = 0;
	for (int i = 0; i < points.size(); i++) {
		double x = points[i].first;
		double y = points[i].second;
		sum += std::pow((m * x + c) - y, 2);
	}
	return sum / points.size();
}

int main() {
	// Gradient descent
	for (int i = 0; i < iterations; i++) {
		double dm = 0; // Partial derivative of MSE with respect to slope(m)
		double dc = 0; // Partial derivative of MSE with respect to intercept(c)

		for (int j = 0; j < points.size(); j++) {
			double x = points[j].first;
			double y = points[j].second;
			double error = (m * x + c) - y;
			dm += 2 * error * x;
			dc += 2 * error;
		}
		dm /= points.size();
		dc /= points.size();
		m -= learningRate * dm;
		c -= learningRate * dc;
	}

	std::cout << "Points: ";
	for (int i = 0; i < points.size(); i++) {
		std::cout << "(" << points[i].first << "," << points[i].second << ")";
		if (i != points.size() - 1) { std::cout << ","; }
		else { std::cout << std::endl; }
	}
	std::cout << "Slope = " << m << std::endl;
	std::cout << "y-Intercept = " << c << std::endl;
	std::cout << "Mean Squared Error = " << MSE(m, c) << std::endl;
}
