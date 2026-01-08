class prop:
    def __init__(self, kp):
        self.kp = kp
    
    def propt(self, error):
        return self.kp*error
