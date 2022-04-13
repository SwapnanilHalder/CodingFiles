# This code counts the no. of occurences of each character in a message
# given input by the user  # example of a dictionary data type

import pprint

print('Enter any message where you want to get the characters counted')
message=input()

count={}       # an empty dictionary in the beginning: will store like 'r':12

# where 'r is the character 'r' occuring in the message and 12 is the no. of
# occurences of the letter 'r'

#for character in message:      # you can run for loop in a string,with a letter each time
for character in message.upper(): #if you dont wanna distinguish upper and lowercase letters 
    count.setdefault(character,0) # if a character is being counted for the first time it will start with 0
    count[character]=count[character]+1    # with each count of a character its value/no. of counts increases by 1 

pprint.pprint(count)