import math

# This program takes n points in a plane as input and returns the closest pair of points. The algorithm is based on divide 
# and conquer paradigm. In this program, it is assumed that no two points have same x coordinates of same y coordinates (If not
# we can enforce this by slight rotation of plane)


# Function to find distance between two points
def dist(P1,P2):
	x1,y1=P1
	x2,y2=P2
	return math.sqrt((x2-x1)**2 + (y2-y1)**2)


# This is trivial method to find distance between two points. We definitely will not divide plane when there will be only two or three
# vertices in a plane. So, in such cases distance will be found using brute force method
def brute_force(a):
	m=10**10
	for i in range(len(a)):
		for j in range(i+1,len(a)):
			m=min(dist(a[i],a[j]),m)
	return m


# This function finds the closest pair of points such that both the points lies in different parts of plane
# that is divided in two parts
def stripClosest(strip,d):
	m=d
	strip.sort(key=lambda t:t[1])
	
	for i in range(len(strip)):
		for j in range(i+1,len(strip)):
			if strip[j][1]-strip[i][1]<m:
				m= min(m,dist(strip[i],strip[j]))
	return m


# This function divides whole plane in two parts P1 and P2 and finds shortest distance pair in both the planes 
# recursively, then it checks if the pair of shortest distance is such that one point lies in P1 and another lies 
# in P2. If this is the case, then it updates the minimum distance pair, otherwise it simply outputs the shortest 
# distance pair found in any one part.
def closest(a):
	if len(a)<=3:
		return brute_force(a)
	
	m=len(a)/2
	dl=closest(a[:m+1])
	dr=closest(a[m+1:])
	mp=a[m]
	d=min(dl,dr)
	
	strip=[]
	
	for i in a:
		x,y=i
		if abs(x-mp[0])<d:
			strip.append(i)
	return min(d,stripClosest(strip,d))


print("Enter number of vertices in a plane")
n=input()

#Empty array of size n
a=[None]*n

# Taking vertices in input, (x,y) are the coordinates of points
print("Enter vertices in the form of (x,y) coordinates")
for _ in range(n):
	x,y=map(int,raw_input().split())
	a[_]=(x,y)


#sort the input array according to x coordinate
a.sort()
print closest(a)
