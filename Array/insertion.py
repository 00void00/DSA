import array as arr
l = [1,4,3,2]
a = arr.array('i',l)
for i in range (0,len(a)):
    print (a[i], end =" ")

print("\nafter insertion", end="\n")
a.insert(2,7)
for i in range (0,len(a)):
    print (a[i], end =" ")

print("\nafter slicing", end="\n")
s=a[:3]
print(s, end=" ")

