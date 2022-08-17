import numpy as np
from math import *

def sigmoid(x): 
	return 1 / (1 + exp(-x))

def cal(f, s): 
	P = np.random.uniform(-3.0, 3.0, (1, 10000))
	S = np.random.uniform(-3.0, 3.0, (1, 100))
	cheater = np.random.randint(0, 100)
	M = np.zeros((100, 10000))
	
	s.write(str(cheater + 1))
	s.write('\n')
	for i in range(100): 
		for j in range(10000): 
			M[i][j] = sigmoid(S[0][i] - P[0][j])
			
	for i in range(100): 
		if i == cheater: 
			for j in range(10000): 
				cheat = np.random.randint(0, 2)
				if cheat == 0: 
					if M[i][j] >= np.random.uniform(0, 1, size = 1)[0]: 
						f.write('1')#M[i][j] = 1
					else: 
						f.write('0')#M[i][j] = 0 
				else: 
					f.write('1')#M[i][j] = 1
		else: 
			for j in range(10000): 
				if M[i][j] >= np.random.uniform(0, 1, size = 1)[0]: 
					f.write('1')#M[i][j] = 1
				else: 
					f.write('0')#M[i][j] = 0
		f.write('\n')

def gen(): 
	f = open('E.in', 'w')
	s = open('E.ans', 'w')
	f.write('10\n100\n')
	for i in range(10): 
		cal(f, s)
		print('#' + str(i) + ' is OK.')
					
gen()
			
