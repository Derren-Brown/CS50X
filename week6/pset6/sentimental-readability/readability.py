def count_letters(text):
    sum = 0
    for char in text:
        if char.isalpha():
            sum += 1
    return sum


def count_words(text):
    val = 1
    for char in text:
        if char == " ":
            val += 1
    return val


def count_sentences(text):
    val = 0
    for char in text:
        if char == "." or char == "?" or char == "!":
            val += 1
    return val


text = input("Text: ")
letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

L = 100.0 * letters / words
S = 100.0 * sentences / words
index = 0.0588 * L - 0.296 * S - 15.8
gra = round(index)

if gra < 1:
    print("Before Grade 1")
elif gra >= 16:
    print("Grade 16+")
else:
    print("Grade", gra)
