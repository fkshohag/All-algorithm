def logestWord(words):
    word_dict = {}
    for word in words:
        h = word.split()
        for i in h:
            if i in word_dict:
                word_dict[i] +=1
            else:
                word_dict[i] = 1
    return max(word_dict, key=word_dict.get)

logestWord(["Echo", "Alexa", "Kindle", "Echo Show", "Amazon"])