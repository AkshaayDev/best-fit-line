# best-fit-line📈

## Overview
This script finds the best fit line for a given set of points.
Mathematically, it iteratively calculates the optimal $m$ and $c$ for $y=mx+c$ that best fits each point $(x,y)$

## Explanation

### Cost
The error of a line for a set of points can be expressed as a quantity known as the **cost**, or also known as **loss**.
The cost tells us how "bad" a function is so we have to minimise it.
The cost function used in this case is **Mean Squared Error(MSE)**. 
MSE finds the difference in the predicted y value($\hat{y}_i$) and the actual y value($y_i$) of a point, squares that difference and finds the mean of these squares for each point.
Mathematically, for a dataset $(x_1,y_1),(x_2,y_2),...,(x_n,y_n)$:

$$ MSE = \frac{1}{n} \sum_{i=1}^{n} (\hat{y}_i - y_i)^2 $$

where $\hat{y}_i = mx_i + c$

### Gradient Descent
Our goal here is to minimise MSE. To do this, we use a technique known as **gradient descent**.
#### 🧠Analogy: Ball Rolling Down A Hill
Imagine a ball rolling down a smooth hill.
The ball will always roll downhill into the direction of steepest descent.
If the hill rises in one direction, the ball goes in the opposite direction.
The steeper the hill, the faster the ball rolls down.
In the end, the ball will reach a **local minimum**, a point lower than the neighbouring points.

Now, imagine that the ball is a point in a 3-dimensional space $(m,c,MSE)$, where $MSE$ is the height in this space.
We have to make this point "roll" down to some local minimum where $MSE$ is minimised.
Here's how:

If $\frac{\partial MSE}{\partial m}$ is the slope in the $m$ axis, move the point in the opposite direction by $\frac{\partial MSE}{\partial m}$.
Similarly, if $\frac{\partial MSE}{\partial c}$ is the slope in the $c$ axis, move the point in the opposite direction by $\frac{\partial MSE}{\partial c}$.
Mathematically, the update formula for gradient descent is:

$$ m \leftarrow m - \alpha \cdot \frac{\partial MSE}{\partial m} $$
$$ c \leftarrow c - \alpha \cdot \frac{\partial MSE}{\partial c} $$

where:
- $\alpha$ is the **learning rate**,
- $\frac{\partial MSE}{\partial m}$ is the **partial derivative** of MSE with respect to m,
- $\frac{\partial MSE}{\partial c}$ is the **partial derivative** of MSE with respect to c.

Here, the learning rate tells the ball how far to make each step.
If the learning rate is too small, the point will take forever to converge.
If the learning rate is too large, the point will overshoot the local minimum and might even diverge.

### Partial Derivatives
In the equation $\hat{y}_i = mx_i+c$, the partial derivatives of $\hat{y}_i$ with respect to $m$ and $c$ are given by:

$$ \frac{\partial \hat{y}_i}{\partial m} = x_i $$
$$ \frac{\partial \hat{y}_i}{\partial c} = 1 $$

And the partial derivative of $MSE$ with respect to $\hat{y}_i$ is given by:

$$ \frac{\partial MSE}{\partial \hat{y}_i} = 2(\hat{y}_i-y_i) $$

So using the chain rule:

$$ \frac{\partial MSE}{\partial m} = \frac{1}{n} \sum_{i=1}^{n} ( \frac{\partial MSE}{\partial \hat{y}_i} \cdot \frac{\partial \hat{y}_i}{\partial m}) $$

$$ = \frac{1}{n} \sum_{i=1}^{n} 2(\hat{y}_i-y_i)x_i $$

$$ \frac{\partial MSE}{\partial c} = \frac{1}{n} \sum_{i=1}^{n} (\frac{\partial MSE}{\partial \hat{y}_i} \cdot \frac{\partial \hat{y}_i}{\partial c}) $$

$$ = \frac{1}{n} \sum_{i=1}^{n} 2(\hat{y}_i-y_i) $$

Now that we have these derivatives, we can substitute them into the gradient descent update formula.
This will update $m$ and $c$ accordingly to minimise $MSE$, giving us the parameters to the best fit line.

## Usage
Change the `points` vector to your dataset and experiment with `learningRate` and `iterations` to get the optimal solution.

## License
This project is unlicensed.
You are free to use, modify, distribute or do anything else **without any restrictions**.

## ❌No Contributions
This is a personal project and I do not accept contributions.
Please do not submit pull requests or open issues.

## 🛠️Development Status
This project is **effectively inactive**.
I likely won't update it anymore.
