# Știind că 1 ianuarie 1702 a picat într-o zi de duminică, să se citească de la tastatură o dată mai
# recentă, și să se spună în ce zi a săptămânii cade aceasta.

an = int(input("an="))
luna = int(input("luna="))
ziua = int(input("ziua="))
sum = 0
inaintarea_zilei = 0
dictionar = {1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30, 7: 31, 8: 31, 9: 30, 10: 31, 11: 30, 12: 31}
day_of_the_week = {1: "Luni", 2: "Marti", 3: "Miercuri", 4: "Joi", 5: "Vineri", 6: "Sambata", 7: "Duminica"}

for i in range(1970, an):
    inaintarea_zilei += 1
    if i % 1000 == 0:
        sum += 366
        inaintarea_zilei += 1

    elif i % 100 != 0 and i % 4 == 0:
        sum += 366
        inaintarea_zilei += 1

    else:
        sum += 365

print(inaintarea_zilei)
unknown_day = -1
copie_luna = luna - 1

while copie_luna:
    unknown_day += dictionar[copie_luna]
    copie_luna -= 1

unknown_day = unknown_day + ziua

if unknown_day % 7 == 0:
    stabilire_data = 4
elif (unknown_day % 7 + 4) > 7:
    stabilire_data = unknown_day % 7 - 3
else:
    stabilire_data = unknown_day % 7 + 4

ok = False
luna -= 1

if (an % 1000 == 0 or (an % 100 != 0 and an % 4 == 0)):
    ok = True

if ok == True:
    sum += 1

while luna:
    sum = sum + dictionar[luna]
    luna -= 1

sum += ziua
zi_finala = stabilire_data + inaintarea_zilei % 7

if zi_finala > 7:
    zi_finala = zi_finala - 7

print("Numarul de zile care a trecut de la data reper la data introdusa este:", sum - 1)
print("Ziua saptamanii este:", day_of_the_week[zi_finala])
