file_name = input("Enter name of a file you wish to see: ")
with open(file_name) as f:
    for line in f:
        print(line,end='')
        line_new = line[-2::-1]
        print('({})'.format(line_new))
#anagram_new = anagram[::-1]
#print(anagram)
#print(f"({anagram_new})")
