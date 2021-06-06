import os
import sys
import subprocess

x = sys.argv[1]
x = x[:-4]
print(x)

# os.system("g++", x, "-o /home/swapno/bin/cpp/compiled.out")
subprocess.run(["echo","g++", x, "-o ~/bin/cpp/compiled"])

# subprocess.run(["g++", x, "-o ~/bin/cpp/compiled"])

p = "g++ "+ x + ".cpp -o ~/bin/cpp/" + x

os.system(p)
# subprocess.run(["g++", "--version"])

print()

res = "~/bin/cpp/" + x
os.system(res)