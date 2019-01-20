def findalltriplets(listofinput):
    listofinput.sort()
    listoftriplet=[]
    print(listofinput)
    for a in range(len(listofinput)-1):
        l = a+1
        r = len(listofinput)-1
        while (l<r):
            if listofinput[a]+listofinput[l]+listofinput[r] == 0:
                listoftriplet.append([listofinput[a],listofinput[l],listofinput[r]])
                l=l+1
                r=r-1

            elif listofinput[a]+listofinput[l]+listofinput[r] <  0:
                l=l+1
                print(l)
            elif listofinput[a]+listofinput[l]+listofinput[r] >  0:
                r=r-1
                print(r)

    return listoftriplet

print(findalltriplets([0,-1,2,-3,1]))