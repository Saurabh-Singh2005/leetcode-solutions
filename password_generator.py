"""
Password Generator
CodSoft - Python Programming Internship (Task 3)
"""

import random
import string


def generate_password(length=12, use_upper=True, use_digits=True, use_symbols=True):
    if length < 4:
        raise ValueError("Length should be at least 4 for a reasonably strong password.")

    pool = list(string.ascii_lowercase)
    if use_upper:
        pool += list(string.ascii_uppercase)
    if use_digits:
        pool += list(string.digits)
    if use_symbols:
        pool += list("!@#$%^&*()_-+=?")

    return "".join(random.choice(pool) for _ in range(length))


def main():
    print("Password Generator")
    try:
        length = int(input("Enter desired password length: "))
    except ValueError:
        print("Please enter a valid number.")
        return

    use_upper = input("Include uppercase letters? (y/n): ").lower().startswith("y")
    use_digits = input("Include digits? (y/n): ").lower().startswith("y")
    use_symbols = input("Include symbols? (y/n): ").lower().startswith("y")

    try:
        password = generate_password(length, use_upper, use_digits, use_symbols)
        print(f"\nGenerated Password: {password}")
    except ValueError as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
