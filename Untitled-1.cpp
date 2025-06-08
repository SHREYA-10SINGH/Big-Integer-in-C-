#include <iostream>
#include <string>
#include <algorithm>

class BigInteger {
private:
    std::string number; // To store the big integer as a string

public:
    // Constructor to initialize BigInteger from a string
    BigInteger(const std::string& num) : number(num) {
        // Remove leading zeros
        number.erase(0, std::min(number.find_first_not_of('0'), number.size() - 1));
    }

    // Addition operator overload
    BigInteger operator+(const BigInteger& other) const {
        std::string num1 = number;
        std::string num2 = other.number;

        // Ensure num1 is the longer one
        if (num1.length() < num2.length()) {
            std::swap(num1, num2);
        }

        std::string result;
        int carry = 0;
        int n1 = num1.length();
        int n2 = num2.length();

        // Add from the end
        for (int i = 0; i < n1; ++i) {
            int digit1 = num1[n1 - 1 - i] - '0';
            int digit2 = (i < n2) ? num2[n2 - 1 - i] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        if (carry) {
            result.push_back(carry + '0');
        }

        // Reverse the result to get the correct order
        std::reverse(result.begin(), result.end());
        return BigInteger(result);
    }

    // Output operator overload
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& bigInt) {
        os << bigInt.number;
        return os;
    }

    // Getter for the number (optional)
    std::string getNumber() const {
        return number;
    }
};

int main() {
    // Create two BigInteger objects
    BigInteger num1("123456789012345678901234567890");
    BigInteger num2("987654321098765432109876543210");
    
    // Add the two BigInteger objects
    BigInteger sum = num1 + num2;
    
    // Output the result
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
