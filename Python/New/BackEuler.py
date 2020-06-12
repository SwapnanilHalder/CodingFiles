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
yval.append(1) #int(input("Initial value y(0):  "))

uplimit = float(input("Target point y(x):  "))
steps = int(input("No. of steps to take :  "))
interval = uplimit/steps

values = {h:interval, x:0, y:yval[0]}
x_ = 0
i=0
while(x_ != uplimit):
    yprev = yval[i]
    yupgr = yprev
    x_ += interval
    values[x] = x_
    while(abs(yupgr-yprev)==0 or abs(yupgr-yprev)>0.0001):
        values[y] = yupgr
        yprev = yupgr
        yupgr = yprev - (F_y.evalf(subs = values) - yval[i])/F_.evalf(subs = values)
    print("y(" ,x_,") = ", yupgr)
    yval.append(float(yupgr))
    i += 1 