def get_int(prompt: str) -> int:
    """
    Prompt the user for an integer and return it.
    """
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Invalid input. Please enter an integer.")

def main():
    """
    Main function to run the program.
    """
    # Get the number of iterations from the user
    x = get_int("Enter the number of iterations: ")
    y = get_int("Enter the number of iterations: ")
    n = x + y
 
    print(f"Some numbers is {n} !")

 main()