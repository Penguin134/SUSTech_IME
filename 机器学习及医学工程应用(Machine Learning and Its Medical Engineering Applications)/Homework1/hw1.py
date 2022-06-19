import numpy as np

# L1 prediction error
def l1_error(x, y, b):
    # Get the transpose of x
    x_t = x.transpose()
    # Calculate the error, the error should be a positive number
    temp = y - np.dot(b, x_t)
    temp = np.abs(temp)
    return np.sum(temp)/len(y)


def mean_squared_error(y_true, y_predicted):
    cost = np.sum((y_true - y_predicted) ** 2) / len(y_true)
    return cost


# Analytical solution
def analytic_sol(x, y):
    # Get the transpose of x
    x_t = x.transpose()
    # Calculate X^TX, as the coefficient of betta
    b = np.dot(x_t, x)
    # Calculate X^Ty, as the coefficient at the opposite of the equation
    c = np.dot(x_t, y)
    return np.linalg.solve(b, c)


# Gradient Descent Function
# Here iterations, learning_rate are hyperparameters that can be tuned
def gradient_descent(x, y, iterations=5000, learning_rate=1e-3):
    # number of samples
    n = x.shape[0]
    # number of features
    f = x.shape[1]
    x_t = x.transpose()
    # Initializing weight, learning rate and iterations
    current_weight = np.zeros(f, dtype=np.float64)
    iterations = iterations
    learning_rate = learning_rate
    # Estimation of optimal parameters
    for i in range(iterations):
        # Making predictions
        y_predicted = np.dot(x, current_weight)
        # Calculationg the current cost
        current_cost = mean_squared_error(y, y_predicted)
        # Calculating the gradients
        weight_derivative = 2/n*(np.dot(np.dot(x_t, x), current_weight) - np.dot(x_t, y))
        # Updating weights
        current_weight = current_weight - learning_rate * weight_derivative
        # Printing the parameters for each 500th iteration
        if (i + 1) % 500 == 0:
            print(f"Iteration {i + 1}: Cost {current_cost}")
    return current_weight


def linear_regression_1(x, y):
    # Get the number of data
    n = int(x.shape[0])
    # Split the data as training : data = 4 : 1
    k = int(0.8 * n)
    # Split x to get the training data
    x_train = x[:k]
    # Split x to get the testing data
    x_test = x[-(n-k):]
    # Split y to get the training label
    y_train = y[:k]
    # Split y to get the testing label
    y_test = y[-(n-k):]
    # Get the analytic solution of betta
    betta = analytic_sol(x_train, y_train)
    # Calculate the loss function
    result = l1_error(x_test, y_test, betta)
    return result


def linear_regression_2(x, y):
    # Get the number of data
    n = int(x.shape[0])
    # Split the data as training : data = 4 : 1
    k = int(0.8 * n)
    # Split x to get the training data
    x_train = x[:k]
    # Split x to get the testing data
    x_test = x[:-(n - k)]
    # Split y to get the training label
    y_train = y[:k]
    # Split y to get the testing label
    y_test = y[:-(n - k)]
    # Using gradient descent to update betta
    betta = gradient_descent(x_train, y_train)
    result = l1_error(x_test, y_test, betta)
    return result


# load the data set
# obtain the feature matrix as a numpy array
data = np.load('x.npy')
# obtain the target variable as a numpy array
target = np.load('y.npy')
# Calculate and print the error of analytic solution algorithm
error1 = linear_regression_1(data, target)
print(error1)
#  Calculate and print the error of gradient descent algorithm
error2 = linear_regression_2(data, target)
print(error2)
