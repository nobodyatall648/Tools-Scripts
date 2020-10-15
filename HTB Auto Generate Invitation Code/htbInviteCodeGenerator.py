import requests
import base64
import codecs

url = "https://www.hackthebox.eu/api/invite/how/to/generate"

headers = {
	'Content-Type' : 'application/json',
	'User-Agent' : 'curl/7.68.0'
}
rsl = requests.post(url, headers=headers)
howToGen  = rsl.json()

print("\nHow to Generate HTB Invite Code")
print("===============================", end='\n\n')

print('Encrypted Text: ' + howToGen['data']['data'])
print('Encryption Type: ' + howToGen['data']['enctype'])
print('Hint: ' + howToGen['hint'], end='\n\n')

decryptedText = ''
if (howToGen['data']['enctype'] == 'BASE64'):
	decryptedText = base64.b64decode(howToGen['data']['data']).decode()
	print("Decoded Text")
	print("============", end='\n\n')
	print(decryptedText)
elif (howToGen['data']['enctype'] == 'ROT13'):
	decryptedText = codecs.decode(howToGen['data']['data'], "rot13")
	print("Decrypted Text")
	print("==============", end='\n\n')
	print(decryptedText)


url = "https://www.hackthebox.eu/api/invite/generate"

headers = {
	'Content-Type' : 'application/json',
	'User-Agent' : 'curl/7.68.0'
}
rsl = requests.post(url, headers=headers)

inviteGen = rsl.json()
print("\nEncoded Invite Code Generated")
print("=============================", end='\n\n')
print("Encoded Invitation Code: " + inviteGen['data']['code'])

print("\nHTB Invitation Code")
print("===================", end='\n\n')
print("Invite Code: " + base64.b64decode(inviteGen['data']['code']).decode())

