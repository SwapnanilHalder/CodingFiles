import re

def result(arg):
    if (arg == 0):
        print("The 8086 instruction in Syntactically Incorrect.")
        exit(0)
    print("The 8086 instruction in Syntactically Correct.")
    exit(0)

def lexar(a) :
    operator = ['add', 'sub']
    bit8 = ['al', 'bl', 'cl', 'dl', 'ah', 'bh', 'ch', 'dh']
    bit16 = ['ax', 'bx', 'cx', 'dx']
    if a in operator:
        return 'operator'
    if a in bit8:
        return 'bit8'
    if a in bit16:
        return 'bit16'
    if type(a) is int:
        return 'integer'
    return 'wrong'

def parser(arr):
    first = lexar(arr[0])
    second = lexar(arr[1])
    third = lexar(arr[2])
    print("The tokens are : " , [first, second, third])
    if first != 'operator' :
        result(0)
    if (second != 'bit8' and second != 'bit16') :
        result(0)
    if(third != second and third != 'integer') :
        result(0)
    if(third == second) :
        result(1)
    if(third == 'integer') :
        if(second == 'bit8') :
            if(arr[2] >= -256 and arr[2] <= 255) :
                result(1)
            else :
                result(0)
        if(second == 'bit16'):
            if(arr[2] >= -65536 and arr[2] <= 65535) :
                result(1)
            else :
                result(0)

    result(1)

x = input("Type the 8086 Assembly Instruction and press ENTER. :\n")
x = x.lower()

arr = re.split(',| ', x)
for p in arr:
    if p == '' :
        arr.remove('')
if(len(arr) != 3) :
    print("The 8086 instruction in Syntactically Incorrect.")
if(arr[2][-1].isnumeric() or arr[2][-1] == 'd') :
    try:
        arr[2] = int(arr[2])
    except:
        arr[2] = arr[2]
elif(arr[2][-1] == 'h' and arr[2][0].isnumeric()) :
    try:
        arr[2] = int(arr[2][:-1], 16)
    except:
        arr[2] = arr[2]
elif(arr[2][-1] == 'o') :
    try:
        arr[2] = int(arr[2][:-1], 8)
    except:
        arr[2] = arr[2]
elif(arr[2][-1] == 'b') :
    try:
        arr[2] = int(arr[2][:-1], 2)
    except:
        arr[2] = arr[2]

print("The arguments passed : " , arr)

parser(arr)
