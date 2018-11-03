#!/usr/bin/python

import serial
import string
import MySQLdb as mdb
import pprint

db = mdb.connect('localhost' , 'pi' , 'password' , 'weather' )
				#host       	uname  #password 	#db'
cur = db.cursor() 

arduinoPort = '/dev/ttyACM0' #check in the /dev folder the Arduino Serial Port
ser = serial.Serial()

ser.setPort(arduinoPort) #boundRate 9600 automatically set
ser.setTimeout(2)

try:
	ser.open()
except: 
	print('Port Error!')

else:
	for i in range (50):
		ardString = ser.readline()
		#print(ardString)
		valueMatrix= ardString.split(' ')
		if len(valueMatrix)> 1 :
			pprint.pprint(valueMatrix)
		#pprint.pprint(valueMatrix)
			projectId = valueMatrix[0]
			value = valueMatrix[1]
			#print("value received:"+string+ " interpreted as: project Id = "+projectId+" and value = "+value)
			cur.execute('INSERT INTO ard_project_data (project_id, value) VALUES ("'+projectId+'", "'+value+'")')
			db.commit()

	ser.close()
	print('connection closed')
	db.close()
	print('database closed')
print('end')