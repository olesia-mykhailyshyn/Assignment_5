#pragma once
#include <string>
#include <vector>
#include <stack>

class Counting {
public:
    std::string countingPostfix(const std::vector<std::string>& notation);
private:
    void handleFunctions(const std::string& token, std::stack<double>& stack, double& result);
};
