import pandas as pd

col_list = ["LIP", "DIP", "PN"]
file = pd.read_csv("./logs1.csv", usecols=col_list)


def source(ip1, file):
    selec = pd.DataFrame(file.loc[file["LIP"] == ip1])
    return selec


def des(ip1, file):
    selec = pd.DataFrame(file.loc[file["DIP"] == ip1])
    return selec


def proto(ip1, file):
    selec = pd.DataFrame(file.loc[file["PN"] == ip1])
    return selec


print("Select an option:")
print("a)1.LIP  ->2.BIP  ->3.PN")
print("b)1.LIP  ->2.BIP")
print("c)LIP")
print("d)BIP")
print("e)PN")
option = str(input())
selec = file
if option == "a":
    sip = str(input())
    dip = str(input())
    pip = str(input())
    selec = source(sip, selec)
    selec = des(dip, selec)
    selec = proto(pip, selec)
    print(selec)
elif option == "b":
    sip = str(input())
    dip = str(input())
    selec = source(sip, selec)
    selec = des(dip, selec)
    print(selec)
elif option == "c":
    sip = str(input())
    selec = source(sip, selec)
    print(selec)
elif option == "d":
    dip = str(input())
    selec = des(dip, selec)
    print(selec)
elif option == "e":
    pip = str(input())
    selec = proto(pip, selec)
    print(selec)
else:
    print("Invalid Option!")