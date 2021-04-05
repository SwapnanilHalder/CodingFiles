import subprocess
import sys

def install(package):
    subprocess.check_call([sys.executable, "-m", "pip", "install", package])
install('sympy')
from sympy import *

x = symbols('x') #input("Enter the independent variable:\n")
y = symbols('y') #input("Enter the dependent variable:\n")
h = symbols('h')
f = sympify(input("Enter the function:\n"))
display(f)
F_y = y - h*f
F_ = diff(F_y, y)
print(F_)
yval=[]

downlimit = float(input("Starting point y(x):  "))
yval.append(float(input("Initial value y():  ")))
uplimit = float(input("Target point y(x):  "))
steps = int(input("No. of steps to take :  "))
interval = (uplimit-downlimit) /steps
print("We are taking h(interval) as : ", h)

values = {h:interval, x:0, y:yval[0]}
x_ = downlimit
i=0
print("y(" ,x_,") = ", yval[i])
while(x_ != uplimit):
    yprev = yval[i]
    yupgr = yprev
    x_ += interval
    x_ = round(x_, 3)
    values[x] = x_
    for j in range(15):
        values[y] = yupgr
        yprev = yupgr
        yupgr = yprev - (F_y.evalf(subs = values) - yval[i])/F_.evalf(subs = values)
    print("y(" ,x_,") = ", yupgr)
    yval.append(float(yupgr))
    i += 1 
