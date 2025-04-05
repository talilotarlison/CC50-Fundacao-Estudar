words = set() # Create an empty set to store the words

def check(word):
    if word.lower() in words # Return True if the word is in the set
        return True
    else:
        return False

def load(dictionary):
    # Open the dictionary file and read each line
    with open(dictionary, "r") as file:
        for line in file:
            words.add(line.rstrip()) # Add each word to the set
    close(file) # Close the file
    return True # Return True if successful

def size():
    return len(words) # Return the number of words in the set

def unload():
    return True # Return True if successful


