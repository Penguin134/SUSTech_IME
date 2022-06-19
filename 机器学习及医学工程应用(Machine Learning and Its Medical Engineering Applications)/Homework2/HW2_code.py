import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from cvxopt import matrix, solvers
from sklearn import svm

'''
Please install the package first
complete the code and add relevant comments
y is equal to d in slides, C is equal to lambda in slides.
'''


def custom_svm_fit(x, y, C):
    # slove alpha
    n_samples, n_features = x.shape
    #
    K = np.zeros((n_samples, n_samples))
    for i in range(n_samples):
        for j in range(n_samples):
            K[i, j] = (1 + np.dot(x[i], x[j])) ** 2
    #
    P = matrix(np.outer(y, y) * K)
    #
    q = matrix(np.zeros(n_samples)-1)
    #
    tmp1 = np.diag(np.ones(n_samples) * -1)
    tmp2 = np.identity(n_samples)
    G = matrix(np.vstack((tmp1, tmp2)))
    #
    tmp3 = np.zeros(n_samples)
    tmp4 = np.ones(n_samples) * C
    h = matrix(np.hstack((tmp3, tmp4)))
    #
    A = matrix(y, (1, n_samples), 'd')
    b = matrix(0.0)
    #
    solution = solvers.qp(P, q, G, h, A, b)
    #
    alphas = np.ravel(solution['x'])  # calculate w and b
    w = np.multiply(x, alphas * y)
    b = y[0] - sum(alphas * y * K[0])
    # _____
    print(w, b)
    return w, b


# Please describe this function
def plot_data(x, y):
    x_min = 4
    x_max = 7
    y_min = 2
    y_max = 5
    colors = ["steelblue", "orange"]
    plt.figure(figsize=(8, 8))
    plt.scatter(x[:, 0], x[:, 1], c=y.ravel(), alpha=0.5,
                cmap=matplotlib.colors.ListedColormap(colors), edgecolors="black")
    plt.xlim(x_min, x_max)
    plt.ylim(y_min, y_max)
    plt.show()


# Please describe this function
def plot_result(x, y, w, b):
    x_min = 4
    x_max = 7
    y_min = 2

    y_max = 5
    xx = np.linspace(x_min, x_max)
    a = -w[0] / w[1]
    yy = a * xx - (b) / w[1]
    margin = 1 / np.sqrt(np.sum(w ** 2))
    yy_neg = yy - np.sqrt(1 + a ** 2) * margin
    yy_pos = yy + np.sqrt(1 + a ** 2) * margin
    plt.figure(figsize=(8, 8))
    plt.plot(xx, yy, "b-")
    plt.plot(xx, yy_neg, "m--")
    plt.plot(xx, yy_pos, "m--")
    colors = ["steelblue", "orange"]
    plt.scatter(x[:, 0], x[:, 1], c=y.ravel(), alpha=0.5,
                cmap=matplotlib.colors.ListedColormap(colors), edgecolors="black")
    plt.xlim(x_min, x_max)
    plt.ylim(y_min, y_max)
    plt.show()


if __name__ == "__main__":
    hw2_x = np.load('hw2_x.npy')
    hw2_y = np.load('hw2_y.npy')
    #
    plot_data(hw2_x, hw2_y)
    #
    w, b = custom_svm_fit(hw2_x, hw2_y, C=10)
    print("W:", w)
    print("b:", b)
    plot_result(hw2_x, hw2_y, w, b)
    #

    clf = svm.SVC(kernel="linear", C=10)
    clf.fit(hw2_x, hw2_y.ravel())
    w = clf.coef_[0]
    b = clf.intercept_
    print("W:", w)
    print("b:", b)
    print("Finished")
