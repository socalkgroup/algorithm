import unittest
from sets import Set

def getlongestconsecurtivnum(inputarray): 
    s = Set()
    maxvalue = 0
    for element in inputarray:
        s.add(element)
    
    for element in inputarray: 
        tmpvalue = 0  
        i=0
        if (element-1) not in s :  
            while ((element + i) in s ):
                tmpvalue = tmpvalue +1 
                i=i+1 

            if tmpvalue > maxvalue: 
               maxvalue = tmpvalue

    return  maxvalue

class TestStringMethods(unittest.TestCase):

    def test_first(self):
        self.assertEqual(getlongestconsecurtivnum([1,2]), 2)
    def test_second(self):
        self.assertEqual(getlongestconsecurtivnum([100,200,300,301,1,2,302]), 3)

    def test_three(self):
        self.assertEqual(getlongestconsecurtivnum([5,4,3,2,1]), 5)


if __name__ == '__main__':
    unittest.main()