words = input("say something: ").lower()

if "hello" in words:
    print("Hello! How can I assist you today?")
elif "how are you" in words:
    print("I'm just a program, but I'm doing well! How about you?")
elif "goodbye" in words:
    print("Goodbye! Have a great day!")
else:
    print("I'm not sure how to respond to that.")