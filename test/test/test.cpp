#include <iostream>
#include <string>

std::string add_with_commas(std::string num1, std::string num2) {
    // split the input strings into parts based on the commas
    std::vector<std::string> num1_parts;
    std:vector<std::string> num2_parts;
    size_t pos = 0;
    while ((pos = num1.find(',')) != std::string::npos) {
        num1_parts.push_back(num1.substr(0, pos));
        num1.erase(0, pos + 1);
    }
    num1_parts.push_back(num1);
    pos = 0;
    while ((pos = num2.find(',')) != std::string::npos) {
        num2_parts.push_back(num2.substr(0, pos));
        num2.erase(0, pos + 1);
    }
    num2_parts.push_back(num2);

    // remove any leading zeros from the parts
    for (auto& part : num1_parts) {
        part.erase(0, part.find_first_not_of('0'));
    }
    for (auto& part : num2_parts) {
        part.erase(0, part.find_first_not_of('0'));
    }

    // pad the shorter list of parts with zeros so they're the same length
    if (num1_parts.size() > num2_parts.size()) {
        num2_parts.insert(num2_parts.begin(), num1_parts.size() - num2_parts.size(), "0");
    }
    else if (num1_parts.size() < num2_parts.size()) {
        num1_parts.insert(num1_parts.begin(), num2_parts.size() - num1_parts.size(), "0");
    }

    // add each pair of parts together and keep track of the carry
    std::vector<std::string> result_parts;
    int carry = 0;
    for (int i = num1_parts.size() - 1; i >= 0; i--) {
        int p1 = std::stoi(num1_parts[i]);
        int p2 = std::stoi(num2_parts[i]);
        int res = p1 + p2 + carry;
        carry = res / 1000;
        result_parts.insert(result_parts.begin(), std::to_string(res % 1000));
    }

    // handle any remaining carry at the front of the list
    if (carry != 0) {
        result_parts.insert(result_parts.begin(), std::to_string(carry));
    }

    // join the result parts with commas and return the final string
    std::string result;
    for (int i = 0; i < result_parts.size(); i++) {
        result += result_parts[i];
        if (i < result_parts.size() - 1) {
            result += ",";
        }
    }
    return result;
}

int main() {
    std::cout << add_with_commas("1,000", "500") << std::endl;  // should output "1,500"
    return 0;
}