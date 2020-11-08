import pandas as pd
import sys
from sqlalchemy import create_engine

if len(sys.argv) == 2:
    db = create_engine("sqlite:///students.db")
    df = pd.read_csv(sys.argv[1])
    split_names = df['name'].str.split()

    df['first'] = (split_names.iloc[:]).apply(lambda x: x[0])
    df['middle'] = split_names.iloc[:].apply(lambda x: x[1] if len(x) == 3 else None)
    df['last'] = split_names.iloc[:].apply(lambda x: x[-1])

    df.to_sql('students', con=db, if_exists='replace')

else:
    print('Error')
