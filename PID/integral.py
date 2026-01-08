class integral:
    def __init__(self, ki):
        self.ki = ki
        self.int = 0.0
    
    def ingt(self, error, dt):
        self.int += error*dt
        return self.ki*self.int
    
