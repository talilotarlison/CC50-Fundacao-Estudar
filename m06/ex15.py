# get number positeve

def get_positive_int(prompt: str) -> int:
    """
    Prompt the user for a positive integer and return it.
    """
    while True:
        try:
            value = int(input(prompt))
            if value > 0:
                return value
            else:
                print("Please enter a positive integer.")
        except ValueError:
            print("Invalid input. Please enter an integer.")

def main():
    x = get_positive_int("Enter a positive integer for x: ")
    print(f"You entered a positive integer: {x}")