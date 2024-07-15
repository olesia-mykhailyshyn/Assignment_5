#include <unordered_map>
#include <string>

using namespace std;

class Globals {
public:
    static unordered_map<string, double> variables;

    static void setVariable(const string& name, double value);
    static double getVariable(const string& name);
    static bool isVariableDefined(const string& name);
};