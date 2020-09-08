import csv

leng = 0
val = {}
lip = []
dip = []
pp = []

with open("logs1.csv") as csvfile:
    readCSV = csv.reader(csvfile, delimiter=",")
    for row in readCSV:
        lip.append(row[0])
        dip.append(row[1])
        pp.append(row[2])
    val = {"LIP": lip, "DIP": dip, "PP": pp}
    print(lip[0], dip[0], pp[0])
    for row in readCSV:
        print(row[0]+row[1]+row[2])
    LIP_inp = str(input("Enter the LIP")
	for _ in range(len(lip)):
		if LIP_inp == lip[_]:
			print(lip[_] + "  " + dip[_] + "  " + pp[_])
    DIP_inp = str(input("Enter the DIP")
	for _ in range(len(dip)):
		if DIP_inp == dip[_]:
			print(lip[_] + "  " + dip[_] + "  " + pp[_])

            #Combination of LIP, DIP. -LIP,Port Number, -DIP,Port Number, -LIP,DIP,Port Number