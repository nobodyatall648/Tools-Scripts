#!/usr/bin/python3 

import requests
from bs4 import BeautifulSoup
import sys

if(len(sys.argv) != 3):	
	print("format: python3 urlExpander.py <mode> <short url>", end='\n\n')	
	print("Mode:")
	print("1) bit.ly")
	print("2) others")
	sys.exit(0)

shortURL = sys.argv[2]
mode = int(sys.argv[1])

if(mode == 1):
	#bit.ly exposed the real website location in the HTTP header 
	rsl = requests.head(shortURL)
	expandUrl = rsl.headers['Location']
	print("Expand URL: " + expandUrl)
elif(mode == 2):
	#use expander website	
	expanderLink = "http://urlexpander.net"
	data = {
		"url" : shortURL
	}
	rsl = requests.post(expanderLink, data=data)	
	soup = BeautifulSoup(rsl.text, 'html.parser')
	retLinks = soup.findAll("a", {"class": "result-a"})
	expandUrl = str(retLinks[1]).split()[2].replace('href=', '').replace('"', '')	
	print("Expand URL: " + expandUrl)
else:
	print("Please Select the Correct Mode.")


