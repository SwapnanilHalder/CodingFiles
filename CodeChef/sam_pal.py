str = input()

def isPalindrome(st):
    if(st == st[::-1]) :
        # print("trial : ", st)
        return True
    return False


def soln (str ):
    for i in range(0, len(str)-2):
        if(isPalindrome(str[0:i+1])) :
            for j in range(i+1, len(str) - 1):
                if ( isPalindrome( str[i+1:j+1 ] )):
                        if(isPalindrome(str[j+1:])):
                            # print("Final : ")
                            print(str[0:i+1])
                            print(str[i+1:j+1])
                            print(str[j+1 : ])
                            return 100      


if(soln(str) != 100):
    print("Impossible")
