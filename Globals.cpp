#include "Globals.h"

std::unordered_map<std::string, double> Globals::variables;

void Globals::setVariable(const std::string& name, double value) {
    variables[name] = value;
}

double Globals::getVariable(const std::string& name) {
    return variables[name];
}

bool Globals::isVariableDefined(const std::string& name) {
    return variables.find(name) != variables.end();
}
