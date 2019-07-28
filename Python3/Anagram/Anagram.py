def reverse(anagram):
    return anagram[::-1]

def test_reverse():
    assert reverse('abc') == 'cba'
    assert reverse('tenders') == 'srednet'
    assert reverse('@23tg') == 'gt32@'
    assert reverse('% %*$#%&GdfTY') == 'YTfdG&%#$*% %'
    print('Tests passed')

if __name__ == 'main':
    anagram = input("Enter a string of text: ")
    print(anagram)
    anagram = reverse(anagram)
    print(f"({anagram})")
    # for python <3.6
    #print("({})".format(anagram_new))

