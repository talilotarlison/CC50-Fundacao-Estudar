import sys

if len(sys.argv) != 2:
    print("Usage: python ex25.py <name>")
    sys.exit(1)

print("Hello", sys.argv[1])
print("Hello world")