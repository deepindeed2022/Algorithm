def find_target_sum(l):
	assert len(l) >= 2
	# l = sorted(l)
	length = len(l)
	for i in xrange(length):
		val = target - l[i]
		for j in xrange(i+1, length):
			if l[j] == val:
				return (i, j)
	return None
