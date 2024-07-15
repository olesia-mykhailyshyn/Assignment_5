#pragma once
#include <unordered_map>
#include <string>

class Globals {
public:
    static std::unordered_map<std::string, double> variables;

    static void setVariable(const std::string& name, double value);
    static double getVariable(const std::string& name);
    static bool isVariableDefined(const std::string& name);
};
