def pascal(p,q):
	if q > p:
		return 0
	elif (q == 0 or q == p):
		return 1
	else:
		pascal(p-1,q-1) +pascal(p-1,q)
