def pi(n):
	p = 10 ** (n + 10)
	a = p * 16 // 5
	b = p * 4 // -239
	f = a + b
	p = f
	j = 3              
	while abs(f):
		a //= -25
		b //= -57121
		f = (a + b) // j
		p += f
		j += 2
	return p // 10**10

print(pi(100000))
