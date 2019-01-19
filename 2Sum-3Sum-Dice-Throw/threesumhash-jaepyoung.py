def findtripplet(listofinput):
    listoftriples=[]
    for a in range(len(listofinput)-1):
        tempset=[]
        for b in range(a+1,len(listofinput)):
            if -(listofinput[a]+listofinput[b]) in tempset:
                listoftriples.append([listofinput[a],listofinput[b],-(listofinput[a]+listofinput[b])])
            else:
                tempset.append(listofinput[b])
                #print(tempset)
    return  listoftriples

print(findtripplet([0,-1,2,-3,1]))

