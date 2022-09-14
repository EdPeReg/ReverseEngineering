#!/usr/bin/env python3

import random

if __name__ == '__main__':
    key = ""
    ascii_sum = 0

    while True:
        # In the second position we should have @.
        if len(key) == 1:
            key += "@"

        # Get the ascii representation from this ascii printable characters range and add it to our key.
        ascii_letter = random.randint(33,126)
        key += chr(ascii_letter)

        if len(key) == 5:
            ascii_sum += ord(key[2]) + ord(key[3]) + ord(key[4])

            if ascii_sum != 300:
                ascii_sum = 0
                key = ""
            else:
                break

    print(key)
