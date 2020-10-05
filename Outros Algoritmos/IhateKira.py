import telepot,time
import re

bot = telepot.Bot('Your token here')
old_id = 1

while 1:
	old_id = old_id + 1
	x = bot.getUpdates(offset = old_id)
	if len(x) == 0:
		break
	for m in x:
		old_id = m['update_id']
print('comecei')
while 1:
	old_id = old_id + 1
	x = bot.getUpdates(offset = old_id)
	last_upd = 0
	for m in x:
		old_id = m['update_id']
		print(m)
		print('---')
		if 'message' in m:
			if m['message']['chat']['type'] == 'supergroup' or m['message']['chat']['type'] == 'group':
				if 'text' in m['message']:
					text = m['message']['text']
					text = text.lower()
					x = text.find('death note')
					if x != -1:
						bot.sendMessage(m['message']['chat']['id'],'Seu nome foi adicionado, ' + m['message']['from']['first_name'])
					print(text)
					x = ''
					for c in text:
						if c == ' ':
							continue
						if c == '1':
							c = 'i'
						if c == '4':
							c = 'a'
						if c == '@':
							c = 'a'
						x = x + c
					x = re.search('k+i+r+a+',x)
					if x:
						bot.sendMessage(m['message']['chat']['id'],'L >> Kira')
