import pandas as pd
import sys
import numpy as np
import re

if len(sys.argv) != 3:
    print('Invalid')

if len(sys.argv) == 3:
    try:
        df = pd.read_csv(sys.argv[1]).to_numpy().tolist()
        text = list(pd.read_csv(sys.argv[2]))[0]
        dna = list(pd.read_csv(sys.argv[1]))[1:]

        count_dna = []
        for sequence in dna:
            res = max(re.findall('((?:' + re.escape(sequence) + ')*)', text), key=len)
            count = res.count(sequence)
            count_dna.append(count)

        for sublist in df:
            if sublist[1:] == count_dna:
                result = sublist[0]

        try:
            if result:
                print(result)

        except NameError:
            print('No Match')

    except FileNotFoundError:
        print('File not Found.')
