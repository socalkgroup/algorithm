def lis(listofinput):
    lis=[]
    lis.insert(0,1)
    maxvalue=0

    for i in range(len(listofinput)):
            lis.insert(i,1)
            for j in range(0,i):
                    if listofinput[j]<listofinput[i]:
                            lis[i]=max(lis[i],lis[j]+1)
                            if lis[i] > maxvalue:
                                    maxvalue = lis[i]

    return maxvalue        


print(lis([2,50,3,10,7,40,80]))