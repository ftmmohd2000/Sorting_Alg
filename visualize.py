import matplotlib.pyplot as plt

def readFrom(fptr):
    if fptr.mode == "r":
        mydata = fptr.read()
        mydata = mydata.split()
    i = 0
    sizes = []
    sortVals = [[],[],[],[],[],[]]
    for a in mydata:
        ref = i%7
        if not ref:
            sizes.append(a)
        else:
            sortVals[ref-1].append(a)
        i += 1
    return sortVals + [sizes]

def main():
    fptr = open("timing.txt","r")

    mydata = readFrom(fptr)

    plt.plot(mydata[-1],mydata[2], color = "r",label = "Insertion Sort")
    plt.plot(mydata[-1],mydata[5], color = "r",label = "Quick Sort")
    plt.xlabel("Number of elements")
    plt.ylabel("Time taken in seconds")
    plt.title("Sort Timings")
    exes = [a for a in mydata[-1] if a%2 == 1]
    valexes = [(500 + 1000*a) for a in mydata[-1] if a%2 == 1]
    plt.xticks(exes,valexes)
    plt.legend()
    plt.autoscale()
    plt.show()

main()

if "__name__" == "__main__":
    main()