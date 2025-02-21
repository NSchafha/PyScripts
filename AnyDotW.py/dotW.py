import argparse

parser = argparse.ArgumentParser()
parser.add_argument("month")
parser.add_argument("day")
parser.add_argument("year")
args = parser.parse_args()

months = {
    "Jan" : 13, "Feb" : 14, "Mar" : 3, "Apr" : 4, "May" : 5, "Jun" : 6, 
    "Jul" : 7, "Aug" : 8, "Sep" : 9, "Oct" : 10, "Nov" : 11, "Dec" : 12
}

day = int(args.day)

month = months[args.month]
monthPart = 13 * (month + 1) // 5

year = int(args.year)
year = year - 1 if month > 12 else year
yearPart = year + (year // 4) - (year // 100) + (year // 400)

dotW = int((day + monthPart + yearPart) % 7)

weekdays = ["Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"]


print(f"Day of the week for {args.month} {day}, {args.year} is: {weekdays[dotW]}")