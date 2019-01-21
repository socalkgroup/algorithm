def getlcs(firststring,secondstring):
    firstlist = list(firststring)
    secondlist = list(secondstring)
    max = 0
    resultsarray=[ [ 0 for i in range(len(secondlist)+1) ] for j in range(len(firstlist)+1) ]
    for i in range(len(firstlist)+1):
        resultsarray[i][0]=0
    
    for i in range(len(secondlist)+1):
        resultsarray[0][i]=0
    
    for i in range(1,len(firstlist)+1):
        for j in range(1,len(secondlist)+1):
            if firstlist[i-1]==secondlist[j-1]:
                resultsarray[i][j]=resultsarray[i-1][j-1]+1
                if  resultsarray[i][j] > max:
                    max = resultsarray[i][j]
    return max

print(getlcs("testhahahah","thahatest"))