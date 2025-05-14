#include "utils.h"
#include <algorithm>
#include <regex>

// Convert a string to upper case
std::string toUpperCase(const std::string& input) {
    std::string output = input;
    std::transform(output.begin(), output.end(), output.begin(), ::toupper);
    return output;
}

// Basic email validation function
bool isValidEmail(const std::string& email) {
    const std::regex pattern(R"(^[\w\.-]+@[\w\.-]+\.\w+$)");
    return std::regex_match(email, pattern);
}