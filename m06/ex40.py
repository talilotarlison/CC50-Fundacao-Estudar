import speech_recognition

recognizer = speech_recognition.Recognizer()
with speech_recognition.Microphone() as source:
    print("Please say something:")
    audio = recognizer.listen(source)
    try:
        text = recognizer.recognize_google(audio, language="en-US")
        print("You said:", text)
    except speech_recognition.UnknownValueError:
        print("Sorry, I could not understand what you said.")
    except speech_recognition.RequestError as e:
        print(f"Could not request results; {e}")

if "hello" in text.lower():
    print("Hello! How can I assist you today?")
elif "how are you" in text.lower():
    print("I'm just a program, but I'm doing well! How about you?")
elif "goodbye" in text.lower():
    print("Goodbye! Have a great day!")
else:
    print("I'm not sure how to respond to that.")