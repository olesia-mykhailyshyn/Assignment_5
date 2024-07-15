import subprocess
from colorama import init, Fore, Style

init(autoreset=True)


def run_echo(input_data):
    exe_path = 'C:\\KSE\\Programming_paradigms\\Assignment_5\\cmake-build-debug\\Assignment_5.exe'
    process = subprocess.Popen(
        [exe_path],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    stdout, stderr = process.communicate(input_data)
    return stdout.strip(), stderr.strip()


def extract_information(output):
    result = ""
    for line in output.split('\n'):
        if "Final Result:" in line:
            result = line.replace("Final Result: ", "").strip()
    return result


def test_echo():
    tests = [
        {"input": "2-2\n", "expected_output": "0.000000"},
        {"input": "2--2\n", "expected_output": "4.000000"},
        {"input": "sin(0)\n", "expected_output": "0.000000"},
        {"input": "cos(0)\n", "expected_output": "1.000000"},
        {"input": "2*(3+4)\n", "expected_output": "14.000000"},
        {"input": "(2+3)*(4+5)\n", "expected_output": "45.000000"},
        #{"input": "2*(3+4\n", "expected_output": "Error: Mismatched parentheses"},
        {"input": "sin(90)+cos(0)\n", "expected_output": "1.893997"},
        {"input": "(2+3*(4-1))/5\n", "expected_output": "2.200000"},
        {"input": "sin(3.14159/2)\n", "expected_output": "1.000000"},
        {"input": "2^ 3\n", "expected_output": "8.000000"},
        {"input": "max(2, 3)\n", "expected_output": "3.000000"},
        {"input": "min(2, 3)\n", "expected_output": "2.000000"},
        {"input": "abs(-3)\n", "expected_output": "3.000000"},
        {"input": "(2^10 + (9 + 6^2)) ^ 3\n", "expected_output": "1221611509.000000"},
        {"input": "sin(sin(3)*cos(3))\n", "expected_output": "-0.139254"},
        {"input": "max(min(3 * 2, 2), 2)\n", "expected_output": "2.000000"},
        {"input": "3+4*2\n", "expected_output": "11.000000"},
        {"input": "10/2-3\n", "expected_output": "2.000000"},
        {"input": "cos(45)+sin(45)\n", "expected_output": "1.376226"},
        {"input": "min(5, 3, 2)\n", "expected_output": "2.000000"},
        {"input": "max(1, 2, 3)\n", "expected_output": "3.000000"},
        {"input": "abs(-4)+2\n", "expected_output": "6.000000"},
        {"input": "(3+4)*2\n", "expected_output": "14.000000"},
        {"input": "2^3+5\n", "expected_output": "13.000000"},
        {"input": "abs(-5)+abs(3)\n", "expected_output": "8.000000"},
        {"input": "(2+3)*(4-1)\n", "expected_output": "15.000000"},
        {"input": "sin(60)+cos(30)\n", "expected_output": "-0.150559"},
        {"input": "3*4-2\n", "expected_output": "10.000000"},
        {"input": "max(2, 3, 4)\n", "expected_output": "4.000000"},
        {"input": "min(5, 3, 2, 1)\n", "expected_output": "1.000000"},
        {"input": "min(max(2, 3), max(4, 1))\n", "expected_output": "3.000000"},
        {"input": "min(max(2, 3), 4) - 5\n", "expected_output": "-1.000000"},
        #{"input": "abs(-5)+min(abs(-1),0)\n", "expected_output": "5.000000"}

        # Function calls
        # {"input": "def add(a, b) {a + b}\nadd(1, 1)\n", "expected_output": "2.000000"},
        # {"input": "def sub(a, b) {a - b}\nsub(5, 3)\n", "expected_output": "2.000000"},
        # {"input": "def mul(a, b) {a * b}\nmul(4, 5)\n", "expected_output": "20.000000"},
        # {"input": "def div(a, b) {a / b}\ndiv(10, 2)\n", "expected_output": "5.000000"},
        # {"input": "def complex(a, b) {sin(a) + cos(b)}\ncomplex(0, 0)\n", "expected_output": "1.000000"},
        # # Variable saving and reusing
        {"input": "var a = pow(2, 4)\na + 3\n", "expected_output": "19.000000"},
        # {"input": "var a = max(min(3 * 2, 2), 2)\na + 3\n", "expected_output": "5.000000"},
        # # Extra points examples
        # {"input": "var a = max(min(3 * 2, 2), 2)\na + 3\n5\n", "expected_output": "5.000000"},
        # {"input": "def myfunc(a, b) { min(a, b) + max(a, b) }\nmyfunc(3, 4)\n", "expected_output": "7.000000"},
    ]

    for test in tests:
        input_data = test["input"]
        expected_output = test["expected_output"]

        output, error = run_echo(input_data)
        result = extract_information(output)

        if error:
            print(f"{Fore.RED}Test failed for input:\n{input_data.strip()}")
            print(f"\nError:\n{error}\n")
        elif result != expected_output:
            print(f"{Fore.RED}Test failed for input:\n{input_data.strip()}")
            print(f"Result: {result}")
            print(f"Expected Result: {expected_output}{Style.RESET_ALL}")
        else:
            print(f"{Fore.GREEN}Test passed for input:\n{input_data.strip()}")
            print(f"Result: {result}")
            print(f"Expected Result: {expected_output}{Style.RESET_ALL}")

        print("\n" + "="*50 + "\n")


if __name__ == "__main__":
    test_echo()