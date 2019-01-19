def twosums(listofinput, target):
    dictholder={}
    for i in range(len(listofinput)):
        dictholder[listofinput[i]]=i
    
    for a in listofinput:
        if target-a in dictholder.keys():
            return [dictholder[a],dictholder[target-a]]

print(twosums([2,7,11,15],9))