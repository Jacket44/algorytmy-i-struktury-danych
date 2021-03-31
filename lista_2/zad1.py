#!/usr/bin/python

import sys, operator


def insertionsort(tab, order):

    if order == ">=":
        order = operator.lt
    elif order == "<=":
        order = operator.gt
    else:
        print("Unknown order, wtf")
        return 0

    swaps = 0
    compares = 0

    for index in range(1, len(tab)):
        current = tab[index]
        position = index
        while position > 0 and order(tab[position - 1], current):
            print("Comparing ", tab[position -1], " with ", current, file=sys.stderr)
            print("Swaping   ", tab[position], " with ", tab[position -1], file=sys.stderr)
            #compares += 1
            #swaps += 1
            tab[position] = tab[position - 1]
            position -= 1
        print("Comparing ", tab[position -1], " with ", current, file=sys.stderr)
        #compares += 1
        tab[position] = current
        print(tab)
    return swaps, compares

def merge_sort():
    return "Merge sort!"

def quick_sort():
    return "Quick sort!"


def main ():
    args = sys.argv[1:]

    n = int(input("Enter amount of array elements:"))
    tab = list(map(int,input("\nEnter the numbers : ").strip().split()))[:n]

    if len(args) == 4 and args[0] == '--type' and args[2] == "--comp":
        if args[1] == "insert":
            insertionsort(tab, args[3])
        elif args[1] == "merge":
            print(merge_sort())
        elif args[1] == "quick":
            print(quick_sort())
        else:
            print("Invalid sorting method choosen.")
            return 0

if __name__ == "__main__":
    main()
