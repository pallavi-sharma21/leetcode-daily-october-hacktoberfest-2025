def is_valid_parentheses(s):
    """
    Returns True if the string s has valid parentheses, False otherwise.
    """
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}

    for char in s:
        if char in mapping.values():  # if opening bracket
            stack.append(char)
        elif char in mapping.keys():  # if closing bracket
            if not stack or stack[-1] != mapping[char]:
                return False
            stack.pop()
    return not stack


def main():
    print(" Valid Parentheses Checker")
    s = input("Enter a string of parentheses: ")
    if is_valid_parentheses(s):
        print("The string has valid parentheses!")
    else:
        print("The string does NOT have valid parentheses.")


if __name__ == "__main__":
    main()
