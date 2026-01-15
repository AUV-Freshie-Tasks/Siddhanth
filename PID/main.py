import differential
import prop
import integral

class PID:
    def __init__(self,kp, ki, kd):
        self.prop = prop.prop(kp)
        self.intg = integral.integral(ki)
        self.drv = differential.differential(kd)
    
    def cycle(self, target, current, dt):
        error = target - current
        p = self.prop.propt(error)
        i = self.intg.ingt(error, dt)
        d = self.drv.diff(error, dt)
        return p+i+d
    

kp = 0.1 #0.1
ki = 0.005 #0.005
kd = 0.187
controller1 = PID(kp,ki,kd)

total_time = 10
setpoint = 100
initial_value = 10
dt = 0.1
iters = 100 #keep it totaltime/dt
rf = 0.5 #response factor (kinda like sluggishness)
current = initial_value

def func(inp):
    return 2*inp*inp - 3*inp

for i in range(100):
    out = controller1.cycle(func(setpoint), func(current), dt)
    current += out
    print(f"Current Value: {current:.2f} | Output: {out:.2f}")
