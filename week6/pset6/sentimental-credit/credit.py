# TODO
def main():
    card = input("Number: ")
    if len(card) == 15:
        if card[0] == "3" and (card[1] == "4" or card[1] == "7"):
            card = str(card)
        else:
            print("INVALID")
            return 1
    elif len(card) == 13:
        if card[0] != "4":
            print("INVALID")
            return 1
    elif len(card) == 16:
        if card[0] == "5":
            if card[1] < "1" or card[1] > "5":
                print("INVALID")
                return 1
        elif card[0] != "4":
            print("INVALID")
            return 1
    else:
        print("INVALID")
        return 1
    ret = verify(card)
    if ret == True:
        if card[0] == "3":
            print("AMEX")
        elif card[0] == "4":
            print("VISA")
        else:
            print("MASTERCARD")
    else:
        print("INVALID")


def verify(card):
    sum = 0
    for i in range(len(card) - 1, 0, -2):
        digit1 = int(card[i])
        digit2 = int(card[i - 1])
        digit2 = digit2 * 2
        modify = str(digit2)
        if digit2 > 9:
            digit2 = int(modify[0]) + int(modify[1])
        sum += digit1 + digit2
    if i == 2:
        digit1 = int(card[0])
        sum += digit1
    if sum % 10 == 0:
        return True
    else:
        return False


if __name__ == "__main__":
    main()
