import pandas as pd
import sys
import sqlite3

if len(sys.argv) == 2:
    query = f"SELECT name, birth FROM students WHERE house = '{sys.argv[1]}' ORDER BY last, first"
    df = pd.read_sql_query(query, "sqlite:///students.db")
    df['birth'] = df['birth'].apply(lambda x: str(x))

    result = df['name'] + ', born ' + df['birth']
    for item in result:
        print(item)

else:
    print('Invalid')
