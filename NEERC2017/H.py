fin = open("input.txt", "r")
fout = open("output.txt", "w")

n = fin.readline()

n = int(n)

count = 8

for i in range(2,10):
	if (i > n):
		break
	count *= 9

for i in range(10, n+1):
	count *= 10

fout.write(str(count))		
