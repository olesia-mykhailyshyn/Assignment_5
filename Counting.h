#include <string>
#include <vector>
#include <stack>

using namespace std;

class Counting {
public:
    static string countingPostfix(const vector<string>& notation);
private:
    void handleFunctions(const string& token, stack<double>& stack, double& result);
};
