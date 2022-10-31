/*
 * @Author: Phillweston 2436559745@qq.com
 * @Date: 2022-10-29 16:36:03
 * @LastEditors: Phillweston
 * @LastEditTime: 2022-10-31 17:40:21
 * @FilePath: \Numerical-Optimization-in-Robots\Line-search_Steepest_Gradient_Descent_with_Armijo_Condition.cpp
 * @Description: 
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

class LineSearchSteepestGradientDescentWithArmijoCondition
{
public:
    vector<double> RosenbrockGradient(vector<double>& x) {
        int x_size = x.size();
        vector<double> x_middle, x_head, x_tail;
        // Initialize the gradient vector with the same size of the x
        vector<double> grad(x_size);
        x_middle.insert(x_middle.end(), x.begin() + 1, x.end() - 1);
        x_head.insert(x_head.end(), x.begin(), x.begin() - 2);
        x_tail.insert(x_tail.end(), x.end() + 2, x.end());
        
        // Gradient vector calculation
        grad[0] = 400 * x[0] * (x[0] * x[0] - x[1]) + 2 * (x[0] - 1);
        grad[x_size - 1] = 200 * (x[x_size - 1] - x[x_size - 2] * x[x_size - 2]);

        for (int i = 1; i < x_size - 1; i++) {
            grad[i] = 200 * (x[i] - x[i - 1] * x[i - 1]) - 400 * x[i] * (x[i + 1] - x[i] * x[i]) + 2 * (x[i] - 1);
        }

        return grad;
    }

    double RosenbrockFunction(vector<double>& x) {
        int x_size = x.size();
        double f = 0;
        for (int i = 0; i < x_size - 1; i++) {
            f += 100 * (x[i + 1] - x[i] * x[i]) * (x[i + 1] - x[i] * x[i]) + (x[i] - 1) * (x[i] - 1);
        }
        return f;
    }

    double Armijo(vector<double>& x, vector<double>& grad) {
        double c = 0.02;
        double tau = 1.0;
        double alpha = tau;
        int x_size = x.size();
        vector<double> x_new(x_size);

        for (int i = 0; i < this->dimension; i++) {
            x_new[i] = x[i] - alpha * grad[i];
        }

        while (this->RosenbrockFunction(x_new) > this->RosenbrockFunction(x) - c * alpha * this->grad_dot(grad)) {
            tau *= 0.4;
            for (int j = 0; j < this->dimension; j++) {
                x_new[j] = x[j] - tau * grad[j];
            }
            alpha = tau;
        }

        return alpha;
    }
private:
    int dimension;
    double grad_dot(vector<double>& x) {
        int x_size = x.size();
        double grad_dot = 0;
        for (int i = 0; i < x_size; i++) {
            grad_dot += x[i] * x[i];
        }
        return grad_dot;
    }
};

int main(int argc, char* argv[]) {
    // TODO: Main function here
    vector<double> x;
    vector<double> grad;

}
