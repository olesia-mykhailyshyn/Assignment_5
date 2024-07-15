#include "Globals.h"

using namespace std;

unordered_map<string, double> Globals::variables;

void Globals::setVariable(const string& name, double value) {
    variables[name] = value;
}

double Globals::getVariable(const string& name) {
    return variables[name];
}

bool Globals::isVariableDefined(const string& name) {
    return variables.find(name) != variables.end();
}