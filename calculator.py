"""
Simple Calculator
CodSoft - Python Programming Internship (Task 2)
"""


def calculate(num1, num2, operator):
    if operator == "+":
        return num1 + num2
    elif operator == "-":
        return num1 - num2
    elif operator == "*":
        return num1 * num2
    elif operator == "/":
        if num2 == 0:
            return "Error: division by zero"
        return num1 / num2
    else:
        return "Error: invalid operator"


def main():
    print("Simple Calculator")
    print("Operators supported: +  -  *  /\n")
    try:
        num1 = float(input("Enter first number: "))
        operator = input("Enter operator (+, -, *, /): ").strip()
        num2 = float(input("Enter second number: "))
    except ValueError:
        print("Please enter valid numbers.")
        return

    result = calculate(num1, num2, operator)
    print(f"\n{num1} {operator} {num2} = {result}")


if __name__ == "__main__":
    main()
