def main():
    sentence = input("Greeting: ")
    if "Hello" in sentence:
        print("$0")
        return
    elif sentence[0].lower() == 'h':
        print("$20")
        return
    else:
        print("$100")
        return

main()