#include <iostream>
#include <cmath>

enum command {
    add, subtract, scale, length, normalize
};

struct vector {
    double x;
    double y;
};

void add_C(double* x1, double* y1) {
    std::cout<<"Enter the coordinates of the second vector (x, y):"<<std::endl;
    double x2,y2;
    std::cin>>x2>>y2;
    *x1+=x2;
    *y1+=y2;
}

void subtract_C (double* x1, double* y1) {
    std::cout << "Enter the coordinates of the second vector (x, y):" << std::endl;
    double x2, y2;
    std::cin >> x2 >> y2;
    *x1 -= x2;
    *y1 -= y2;
}

void scale_C (double* x1, double* y1) {
    std::cout << "Enter a scalar:" << std::endl;
    double a;
    std::cin >> a;
    *x1 *= a;
    *y1 *= a;
}

double length_C (double* x1, double* y1) {
    double v=sqrt((pow(*x1,2)+pow(*y1,2)));
    return v;
}

void normalize_C (double* x1, double* y1) {
    double v=length_C(x1,y1);
    *x1/= v;
    *y1/= v;
}

int main() {
    std::cout<<"Enter the coordinates of the vector (x, y):"<<std::endl;
    vector v;
    std::cin>>v.x>>v.y;

    std::cout<<"Enter the command: \n"
               "0 - addition of two vectors\n"
               "1 - subtraction of two vectors\n"
               "2 - multiplication of a vector by a scalar\n"
               "3 - finding the length of the vector\n"
               "4 - normalization of the vector"<<std::endl;
    int num_command;
    std::cin>>num_command;

    if (num_command==command::add) {
        add_C(&v.x,&v.y);
        std::cout<<"Result of vector addition: "<<v.x<<" "<<v.y;
    }

    if (num_command==command::subtract) {
        subtract_C(&v.x,&v.y);
        std::cout<<"Result of vector subtraction: "<<v.x<<" "<<v.y;
    }

    if (num_command==command::scale) {
        scale_C(&v.x,&v.y);
        std::cout<<"The result of multiplying a vector by a number: "<<v.x<<" "<<v.y;
    }

    if (num_command==command::length) {
        std::cout<<"Vector length: "<<length_C(&v.x,&v.y);
    }

    if (num_command==command::normalize) {
        normalize_C(&v.x,&v.y);
        std::cout<<"The result of vector normalization: "<<v.x<<" "<<v.y;
    }
}
