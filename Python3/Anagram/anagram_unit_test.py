import unittest

from Anagram import reverse

class test_reverse(unittest.TestCase):
    def test_alphabet(self):
        self.assertEqual(reverse('abc'), 'cba')
        self.assertEqual(reverse('tenders'), 'srednet')  

    def test_special_char(self):
        self.assertEqual(reverse('% %*$#%&GdfTY'), 'YTfdG&%#$*% %')

    def test_mixed(self):
        self.assertEqual(reverse('@23tg'), 'gt32@')
    def test_fail(self):
        self.assertEqual(reverse('hahaha'), 'lalala')
if __name__ == '__main__':
    unittest.main()