import numpy as np

#def __init__(self):
x = [1,2,3,4,5,6] #x coords
y = [1,2,3,4,5,6]
data = [[x_data],[y_data]]
def sig(x):
    if(x>=0):
        return 1/(1+np.exp(-x))
    elif(x<0):
        return np.exp(x)/(1+np.exp(x))

def cfm(m, c): #returns the differentiated form of cost, just multiply with step size
    sum = 0
    for i in range(len(x)):
        sum += (sig(m*x[i] + c) - y[i])*x[i]
    return sum

def cfc(m, c): #same as cfm
    sum = 0
    for i in range(len(x)):
        sum += sig(m*x[i] + c) - y[i]
    return sum

def pred(m, x, c):
    return sig(m*x + c)

mf = 0
cf = 0
m = 1
c = 1
alpha = 0.000001*m
while(abs(m-mf)<alpha and abs(c-cf)<alpha*10):
    mf = m
    m -= cfm(m)*alpha
    c -= cfc(c)*alpha




        