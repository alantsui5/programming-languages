#headers
import sqlite3

    

#interface
db_name=input("Input name of database: ")

#Open db
conn = sqlite3.connect(db_name)
cursor = conn.cursor()

#Options Interface
print('1.Display')
print('2.Add entry')
print('3. Delete entry')
print('4. Exit')
option = input('please select your action: ')

# table initialize
try
cursor.execute('''CREATE TABLE ts( id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, origin text, new text, country text, )''')

#when option = 1 display table
#display table
for row in cursor.execute('select * from table')