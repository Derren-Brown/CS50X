import sys
import random
from pyfiglet import Figlet

figlet = Figlet()
lst = figlet.getFonts()
if len(sys.argv) == 1:
    figlet.setFont(font = lst[random.randrange(len(lst))])
elif len(sys.argv) == 3:
    if sys.argv[1] == '-f' or sys.argv[1] == '-font':
        figlet.setFont(font = sys.argv[2])
    else:
        print("Invalid usage")
        sys.exit(1)
else:
    print("Invalid usage")
    sys.exit(1)
s = input("Input: ")
print("Output: ")
print(figlet.renderText(s))