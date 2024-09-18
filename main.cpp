#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

std::vector<std::pair<double, double>> points = {
	{0, 0},
	{50, 2},
	{100, 3.2},
	{150, 5},
	{200, 6.9},
	{250, 8.5},
	{300, 9.8},
};
double intercept = 0;
double slope = 0;
double learningRate = 0.00000001;
int iterations = 10000000;

double MSE(double intercept, double slope) {
	double sum = 0;
	for (int i = 0; i < points.size(); i++) {
		double x = points[i].first;
		double y = points[i].second;
		sum += std::pow(y - (intercept + slope * x), 2);
	}
	return sum / points.size();
}
int main() {
	// Gradient descent
	for (int i = 0; i < iterations; i++) {
		double interceptGradient = 0;
		// Partial derivative of MSE with respect to intercept
		double slopeGradient = 0;
		// Partial derivative of MSE with respect to slope

		for (int j = 0; j < points.size(); j++) {
			double x = points[j].first;
			double y = points[j].second;
			double error = y - (intercept + slope * x);
			interceptGradient -= 2 * error;
			slopeGradient -= 2 * error * x;
		}
		interceptGradient /= points.size();
		slopeGradient /= points.size();

		intercept -= learningRate * interceptGradient;
		slope -= learningRate * slopeGradient;
	}

	for (int i = 0; i < points.size(); i++) {
		std::cout << "(" << points[i].first << "," << points[i].second << ")";
		if (i != points.size() - 1) { std::cout << ","; }
		else { std::cout << std::endl; }
	}
	std::cout << "Slope = " << slope << std::endl;
	std::cout << "y-intercept = " << intercept << std::endl;
	std::cout << "Mean Squared Error = " << MSE(intercept, slope) << std::endl;
}
