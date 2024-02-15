import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases = {}
    previous_cases = {}
    for row in reader:
        if row["state"] in previous_cases.keys():
            pass
        else:
            previous_cases[row["state"]] = []
        lst = previous_cases[row["state"]]
        lst.append(int(row["cases"]))
        if len(lst) > 15:
            lst.pop(0)
    for lst in previous_cases.values():
        for i in range(13, -1, -1):
            lst[i + 1] = lst[i + 1] - lst[i]
        lst.pop(0)
    for key in previous_cases.keys():
        new_cases[key] = previous_cases[key]

    return new_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        sum = 0
        for key in new_cases[state][7:]:
            sum += key
        average2 = sum / 7
        sum = 0
        for key in new_cases[state][0:7]:
            sum += key
        average1 = sum / 7
        rate = 0
        try:
            rate = round((average2 - average1) / average1 * 100)
        except:
            ZeroDivisionError("divided by 0")
        average2 = round(average2)
        print(f"{state} had a 7-day average of {average2} and an increase of {rate}%.")


if __name__ == "__main__":
    main()
