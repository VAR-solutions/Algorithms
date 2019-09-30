
def interpolation_search(list, key):
	lo = 0
	hi = len(list) - 1
	while(lo <= hi and key >= list[lo] and key <= list[hi]):
		pos = lo + (((hi - lo)/(list[hi]-list[lo]))*(key - list[lo]))
		if(list[pos]==x):
			return pos
		elif(list[pos] < x):
			lo = pos + 1
		else:
			hi = pos - 1
	return -1
