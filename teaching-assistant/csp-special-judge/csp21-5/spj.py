#!/usr/bin/python3
from ast import main
import sys

out_list = {}

file_in = open(sys.argv[1], "r")
file_u = open(sys.argv[2], "r")
file_a = open(sys.argv[3], "r")


def main():
    maxloss = 0
    while True:
        line_u = file_u.readline()
        line_a = file_a.readline()
        if not line_a and not line_u:
            if maxloss < 1e-9:
                exit(4)
            else:
                exit(6)

        if not line_a:
            exit(6)

        if not line_u:
            exit(6)

        n = len(line_u.strip().split(" "))
        m = len(line_a.strip().split(" "))

        if n != m:
            exit(6)

        for i in range(n):
            u = float(line_u.strip().split(" ")[i])
            a = float(line_a.strip().split(" ")[i])
            
            if abs(a) <= 1:
                if abs(u - a) > maxloss:
                    maxloss = abs(u - a)
            else:
                if abs(a) > 1 and abs(u - a) / abs(a) > maxloss:
                    maxloss = abs(u - a) / abs(a)


if __name__ == "__main__":
    main()
