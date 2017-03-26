# Implement the algorithm for the closest pair problem in your favourite language.
# INPUT: Given n points in a plane.
# 		1.122 % 1
#		10 % 10.12
#		1222.3 % 33
#		22.44 % 55.222
#
# OUTPUT: the pair with the least Euclidean distance

def getdata_from_file(filename = "points.txt"):
	result = []
	with open(filename) as f:
		for line in f:
			lines = line.split("%")
			result.append((float(lines[0]),float(lines[1])))
	return result 

# index = 0 sorted by x
# index = 1 sorted by y
def sort_by_index(pointslist, index = 0):
	return sorted(pointslist, key = lambda x: x[index])

def get_euclidean_distance2(p1, p2):
 	return abs(p1[1] - p2[1])**2 + abs(p1[0] - p2[0])**2

def get_dmrange_points(s, l, dm, index = 0):
	return [i for i in s if abs(i[index] - l) <= dm]
			
def Cpair2(points):
	# divide to 2 set
	if len(points) < 2:
		return 0x7FFFFFFFFFFFFFFFL
	elif len(points) == 2:
		return get_euclidean_distance2(points[0], points[1])
	elif len(points) == 3:

		return min(get_euclidean_distance2(points[0], points[1]),\
					get_euclidean_distance2(points[0], points[2]),\
					get_euclidean_distance2(points[1], points[2]))
	elif len(points) > 3:
		# get the median number of points_x_index
		m = points[len(points)/2][0]

		# divide the points set to 2 part
		S1, S2 = filter(lambda x: x[0] <= m, points), filter(lambda x: x[0] > m, points)
	
		cd_1 = cd_2 = 0x7FFFFFFFFFFFFFFFL
		if len(S1) != len(points) and len(S2) != len(points):
			cd_1, cd_2 = Cpair2(S1), Cpair2(S2)
		dm = min(cd_1, cd_2)

		P1, P2 =  sorted(get_dmrange_points(S1, m, dm), key = lambda x: x[1]) , \
				sorted(get_dmrange_points(S2, m, dm), key = lambda x: x[1])

		## There are some tip to promote performance by update dm immediately if find some smaller dm
		euclidist = []
		for point in P1:
			#Y = get_dmrange_points(P2, l = point[1], dm = dm, index = 1)
			for point2 in P2:
				euclidist.append(get_euclidean_distance2(point,point2))
		if euclidist:
			return min(dm, min(euclidist))
		else:
			return dm



import sys
from optparse import OptionParser


def main():
	parser = OptionParser(usage="""\
            Option for use code style check.

            Usage: %prog [options]

            Client request user documents
            """)
	parser.add_option('-i', '--input', metavar="FILE",
                     help="INPUT: Given n points in a plane", default = "points.txt")

	opts, args = parser.parse_args()
	if not opts.input:
		parser.print_help()
		sys.exit(1)

	result = sort_by_index(pointslist = getdata_from_file(filename = opts.input),index = 1)
	mindistance = Cpair2(result)**0.5
	print "min distance in pairs is: %s" % mindistance
  	

if __name__ == '__main__':
	main()

	

	