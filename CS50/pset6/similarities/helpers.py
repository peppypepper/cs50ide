def lines(a, b):  #compares files based on number of lines in common
    """Return lines in both a and b"""

    #split strings into lines, put them in a list
    lista = a.splitlines()
    listb = b.splitlines()

    #a list contains only common elements from 2 lists
    finallist = list(set(lista).intersection(listb))

    return finallist


def sentences(a, b):  #compares files based on number of sentences in commom
    """Return sentences in both a and b"""
    from nltk.tokenize import sent_tokenize   #turn a string into sentenses and put them in a list

    lista = sent_tokenize(a)
    listb = sent_tokenize(b)

    #compare 2 lists, put all common elemnts into a new list
    finallist = list(set(lista).intersection(listb))


    return finallist


def substrings(a, b, n):  #compares files based on number of substrings of length n in common
    """Return substrings of length n in both a and b"""

    #break a string into substrings length n, put them in a list
    lista = map(''.join, zip(*[iter(a)]*n))
    listb = map(''.join, zip(*[iter(b)]*n))

    #compare 2 lists, put all common elemnts into a new list
    finallist = list(set(lista).intersection(listb))

    return finallist
