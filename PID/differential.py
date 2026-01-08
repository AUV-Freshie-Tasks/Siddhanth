class differential:
    def __init__(self, Kd):
        self.errorl = 0.0
        self.Kd = Kd
    
    def diff(self, error, dt):
        if dt == 0.0:
            return 0.0
        
        drv = (error - self.errorl)/dt
        self.errorl = error
        return self.Kd*drv
