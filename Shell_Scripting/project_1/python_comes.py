import os
import sys
import subprocess
import filecmp

x = sys.argv[1]
x = x[:-4]
# print(x)

# os.system("g++", x, "-o /home/swapno/bin/cpp/compiled.out")
# subprocess.run(["echo","g++", x, "-o ~/bin/cpp/compiled"])

# subprocess.run(["g++", x, "-o ~/bin/cpp/compiled"])
home = os.path.expanduser('~')
in_out = home +'/bin/cpp/' + x+ '/'
input_file = in_out + 'input.txt'
output_file = in_out + 'output.txt'
result_file = in_out + 'result.txt'

print(home)

# print(type(os.path.isdir(in_out)))
# print(os.path.isdir(in_out))
# os.system('echo '+ str(os.path.isdir(in_out)))
# print(os.path.isfile(in_out))

if (os.path.isdir(in_out) == False) :
    # subprocess.run(["rm -f", "~/bin/cpp/x"])
    os.system('mkdir '+ in_out)
    print("Enter Input : (Press ctrl+C to Exit)")
    os.system("touch " + input_file)
    os.system("cat "+ '> '+ input_file)
    # os.system("cat "+  input_file)
    print("Enter Correct Answer :")
    os.system("touch "+ result_file)
    os.system("cat "+ '> '+ result_file)
    




os.system("g++ "+ x + ".cpp -o ~/bin/cpp/" + x+ "/"+x)
# subprocess.run(["g++", "--version"])

print()
 
os.system(in_out+x+'<'+input_file+'>'+output_file)
result = filecmp.cmp(output_file, result_file, shallow=False)
if(result == True) :
    print("Correct!!")
else :
    print("Wrong!!")
    f1 = open(result_file, "r")
    f2 = open(output_file, "r")
    i = 0
    for line1 in f1:
        i += 1
        for line2 in f2:
            if line1 != line2 :
                print("Line ", i, ":")
                print("\tFile 1:", line1, end='')
                print("\tFile 2:", line2, end='')
    f1.close()
    f2.close()
