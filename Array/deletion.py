import array as arr
l = [1,4,3,2]
a = arr.array('i',l)
for i in range (0,len(a)):
    print (a[i], end =" ")


print("\nafter deletion", end="\n")
a.pop(2)
for i in range (0,len(a)):
    print (a[i], end =" ")