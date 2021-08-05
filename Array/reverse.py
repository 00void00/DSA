import array as arr
l = [1,4,3,2]
a = arr.array('i',l)
for i in range (0,len(a)):
    print (a[i], end =" ")

print("\nafter reversing", end="\n")
s=a[::-1]
print(s, end=" ")

print("reversing without slicing")
a.reverse()
print(a)

