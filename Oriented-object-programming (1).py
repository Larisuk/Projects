class Dog(object):
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def speak(self):
        print("Hi,i am",self.name,"and i am",self.age)

class Cat(Dog):
    def __init__(self,name,age,color):
        super().__init__(name,age)
        self.color=color

tim=Dog('Tim',54)
tim.speak()
ornaldo=Cat('orlando',45,'blue')
ornaldo.speak()

class Points():
    def __init__(self,x=0,y=0):
        self.x=x
        self.y=y
        self.coords=(self.x,self.y)
    def move(self,x,y):
        self.x+=x
        self.y+=y
    def __add__ (self,p):
        return Points(self.x+p.x,self.y+p.y)
    def length(self):
        import math
        return math.sqrt(self.x**2+self.y**2)
    def __str__(self):
        return "("+str(self.x)+","+str(self.y)+")"
p1=Points(3,4)
p2=Points(6,1)
print (p1+p2)
class Dog:
    dogs=[]
    xc=5
    def __init__(self,name):
        self.name=name
        gos.dog.append(self)
    @classmethod
    def num_dogs(cls):
        return len(cls.dogs)
    @staticmethod
    def bark(n):                    #used as a function
        for _ in range(n):
            print("bark!")