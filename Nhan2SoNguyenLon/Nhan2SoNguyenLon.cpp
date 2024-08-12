#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

class Big_Int {
public:
    std::string value;

    Big_Int(std::string val = "") : value(val) {}

    int sign() const {
        if (value[0] == '-') return -1;
        return 1;
    }

    Big_Int abs() const {
        if (value[0] == '-') return Big_Int(value.substr(1));
        return *this;
    }

    Big_Int operator*(const Big_Int& other) const {
        std::string result = multiply(value, other.value);
        return Big_Int(result);
    }

    Big_Int operator-(const Big_Int& other) const {
        std::string result = subtract(value, other.value);
        return Big_Int(result);
    }

    Big_Int operator+(const Big_Int& other) const {
        std::string result = add(value, other.value);
        return Big_Int(result);
    }

private:
    static std::string multiply(const std::string& num1, const std::string& num2) {
        return std::to_string(std::stoll(num1) * std::stoll(num2));
    }

    static std::string subtract(const std::string& num1, const std::string& num2) {

        return std::to_string(std::stoll(num1) - std::stoll(num2));
    }

    static std::string add(const std::string& num1, const std::string& num2) {

        return std::to_string(std::stoll(num1) + std::stoll(num2));
    }
};

Big_Int left(const Big_Int& X, int n) {
    return Big_Int(X.value.substr(0, n));
}

Big_Int right(const Big_Int& X, int n) {
    return Big_Int(X.value.substr(X.value.size() - n));
}

Big_Int Big_Number_Multi(const Big_Int& X, const Big_Int& Y, int n) {
    Big_Int m1, m2, m3, A, B, C, D;
    int s; 
    s = X.sign() * Y.sign(); 

    Big_Int absX = X.abs();
    Big_Int absY = Y.abs();

    if (n == 1)
        return Big_Int(std::to_string(std::stoi(absX.value) * std::stoi(absY.value) * s));
    else {
        A = left(absX, n / 2); 
        B = right(absX, n / 2);
        C = left(absY, n / 2);
        D = right(absY, n / 2); 

        m1 = Big_Number_Multi(A, C, n / 2);
        m2 = Big_Number_Multi(A - B, D - C, n / 2);
        m3 = Big_Number_Multi(B, D, n / 2);

        std::string pow10_n = std::string(n, '0');
        std::string pow10_n2 = std::string(n / 2, '0');

        Big_Int result = Big_Int(m1.value + pow10_n) +
            Big_Int((m1 + m2 + m3).value + pow10_n2) +
            m3;
        result.value = (s == -1 ? "-" : "") + result.value;

        return result;
    }
}

int main() {
    Big_Int X("12345678");
    Big_Int Y("87654321");

    int n = std::max(X.value.size(), Y.value.size());

    Big_Int result = Big_Number_Multi(X, Y, n);
    std::cout << "Product: " << result.value << std::endl;

    return 0;
}
