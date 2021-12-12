import os
import sys
import subprocess
import filecmp

flag = ""
# print(sys.argv)
if(len(sys.argv) == 3) :
    flag = sys.argv[2]
    # print(flag)

file_name_exnt = sys.argv[1]
file_name = file_name_exnt[:-4] # removing last .cpp part
path = file_name_exnt
if(file_name_exnt.__contains__('/')):
    # for i in range(len(path)-1, -1, -1) :
    #     # print("path[i] : ", path[i])
    #     if (path[i] == '/'):
    #         file_name = path[(i+1):]
    #         break
    file_name = os.path.basename(file_name)
    file_name_exnt = os.path.basename(file_name_exnt)

else :
    path = os.path.abspath(os.getcwd()) + '/' + file_name_exnt

print(path)
print(file_name_exnt)
print(file_name)


# print("Path : " + path)

# print("Started")

# print(len(path))

# print(os.path.abspath(os.getcwd()))


# print(path)
# print(file_name)

# os.system("g++", file_name, "-o /home/swapno/bin/cpp/compiled.out")
# subprocess.run(["echo","g++", file_name, "-o ~/bin/cpp/compiled"])

# subprocess.run(["g++", file_name, "-o ~/bin/cpp/compiled"])
home = os.path.expanduser('~')
in_out = home +'/bin/cpp/' + file_name+ '/'
input_file = in_out + 'input.txt'
output_file = in_out + 'output.txt'
result_file = in_out + 'result.txt'

# print(home)

# print(type(os.path.isdir(in_out)))
# print(os.path.isdir(in_out))
# os.system('echo '+ str(os.path.isdir(in_out)))
# print(os.path.isfile(in_out))

if (flag == "new") :
    os.system("rm -rf " + "~/bin/cpp/"+file_name)

if (flag == 'add') :
    print("Enter Extra Input : (Press ctrl+d to Exit)")
    os.system("cat "+ '>> '+ input_file)
    print("Enter Extra Correct Answer : (Press Enter to register the line of answer) ")
    os.system("cat "+ '>> '+ result_file)

if(flag == 'del') :
    os.system("rm -f " + "~/bin/cpp/file_name")



if (os.path.isdir(in_out) == False) :
    # subprocess.run(["rm -f", "~/bin/cpp/file_name"])
    os.system('mkdir '+ in_out)
    print("Enter Input : (Press ctrl+d to Exit)")
    os.system("touch " + input_file)
    os.system("cat "+ '> '+ input_file)
    # os.system("cat "+  input_file)
    print("Enter Correct Answer : (Press Enter to register the line of answer) ")
    os.system("touch "+ result_file)
    os.system("cat "+ '> '+ result_file)
    


os.system("g++ "+ path + " -o ~/bin/cpp/" + file_name+ "/"+file_name)
# subprocess.run(["g++", "--version"])

print()
 
os.system(in_out+file_name+'<'+input_file+'>'+output_file)
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
