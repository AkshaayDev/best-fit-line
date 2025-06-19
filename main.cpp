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
double N = points.size();

// Model the dataset with y = mx + c
double m = 0; // Gradient
double c = 0; // y-Intercept
double learningRate = 0.00000001;
int iterations = 10000000;

// Predict the y-value for a given x-value using the parameters
double predict(double x) {
	return m * x + c;
}

// Mean Squared Error
double MSE() {
	double sum = 0;
	for (const auto& [X, Y] : points) {
		sum += std::pow(predict(X) - Y, 2);
	}
	return sum / N;
}

// Gradient descent to approximate the slope and y-intercept
void gradientDescent() {
	for (int i = 0; i < iterations; i++) {
		double dm = 0; // Partial derivative of MSE with respect to slope(m)
		double dc = 0; // Partial derivative of MSE with respect to intercept(c)

		for (const auto& [X, Y] : points) {
			double error = predict(X) - Y;
			dm += 2 * error * X;
			dc += 2 * error;
		}
		dm /= N;
		dc /= N;
		m -= learningRate * dm;
		c -= learningRate * dc;
	}
}

// Calculate the expected slope and y-intercept
void linearRegression() {
	double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
	for (const auto& [X, Y] : points) {
		sumX += X; sumY += Y; sumXY += X*Y; sumX2 += X*X;
	}
	m = (N * sumXY - sumX * sumY) / (N * sumX2 - sumX * sumX);
	c = (sumY - m * sumX) / N;
}

int main() {
	std::cout << "Points: ";
	for (int i = 0; i < N; i++) {
		std::cout << "(" << points[i].first << "," << points[i].second << ")";
		if (i < N-1) { std::cout << ","; }
	}
	std::cout << "\n\n";

	for (int i = 0; i < 2; i++) {
		(i == 0) ? gradientDescent() : linearRegression();
		std::cout << ((i == 0) ? "Predicted" : "Expected") << ":\n";

		std::cout << "Slope = " << m << '\n';
		std::cout << "y-Intercept = " << c << '\n';
		std::cout << "MSE = " << MSE() << "\n\n";
	}
}
