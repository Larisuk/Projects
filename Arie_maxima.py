#Într-o zonă rezidențială se află o pădure foarte frumoasă, de forma unui dreptunghi. Un investitor isteț s-a gândit să-și construiască o vilă chiar în pădure,
#dar, fiind un ecologist convins, nu ar vrea să taie niciun copac. Din acest motiv, el ar vrea să afle zona dreptunghiulară din pădure cu suprafață maximă și
#în care nu este niciun copac. Investitorul are o hartă a întregii zone, în care sunt date coordonatele dreptunghiului corespunzător pădurii, precum și
#coordonatele tuturor copacilor din ea.
x = open("copaci.in", "r")
stanga_jos = [int(element) for element in x.readline().split(" ")]
dreapta_sus = [int(element) for element in x.readline().split(" ")]
nrcop = int(x.readline())
copaci = []

for line in x:
    nou = line.split(" ")
    copaci.append((int(nou[0]), int(nou[1])), )
print(copaci[0],copaci[1])
def plantare(left, down, right, up, copaci):
    global max_s
    global st_j
    global dr_s
    ok = True
    for element in copaci:
        if element[1] > down and element[1] < up and element[0] > left and element[0] < right:
            print(plantare(left, down, element[0], up, copaci))
            plantare(left, element[1], right, up, copaci)
            print(plantare(left, down, right, element[1], copaci))
            print(plantare(element[0], down, right, up, copaci))
            ok=False
    if ok:
        sup = (right - left) * (up - down)
        if max_s < sup:
            max_s = sup
            st_j=(left,down)
            dr_s=(right,up)
max_s = 0
plantare(stanga_jos[0], stanga_jos[1], dreapta_sus[0], dreapta_sus[1], copaci)
print(max_s)
print(st_j,dr_s)
