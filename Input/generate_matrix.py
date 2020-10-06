import numpy as np

# 30 x 30 matrix
d = np.random.rand(30, 30)
dd = np.random.randint(1, 300, size = (30, 30))

d = np.add(d, dd)
d = np.matrix(d)

with open('30x30_1.txt','wb') as f:
    for line in d:
        np.savetxt(f, line, fmt='%.5f')

# 30 x 30 matrix
d = np.random.rand(30, 30)
dd = np.random.randint(1, 300, size = (30, 30))

d = np.add(d, dd)
d = np.matrix(d)

with open('30x30_2.txt','wb') as f:
    for line in d:
        np.savetxt(f, line, fmt='%.5f')




# 50 x 50 matrix
e = np.random.rand(50, 50)
ee = np.random.randint(1, 300, size = (50, 50))

e = np.add(e, ee)
e = np.matrix(e)

with open('50x50_1.txt','wb') as f:
    for line in e:
        np.savetxt(f, line, fmt='%.5f')

# 50 x 50 matrix
e = np.random.rand(50, 50)
ee = np.random.randint(1, 300, size = (50, 50))

e = np.add(e, ee)
e = np.matrix(e)

with open('50x50_2.txt','wb') as f:
    for line in e:
        np.savetxt(f, line, fmt='%.5f')




# 100 x 100 matrix
a = np.random.rand(100, 100)
aa = np.random.randint(1, 10, size = (100, 100))

a = np.add(a, aa)
a = np.matrix(a)

with open('100x100_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.5f')

# 100 x 100 matrix
a = np.random.rand(100, 100)
aa = np.random.randint(1, 10, size = (100, 100))

a = np.add(a, aa)
a = np.matrix(a)

with open('100x100_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.5f')



# 150 x 150 matrix
a = np.random.rand(150, 150)
aa = np.random.randint(1, 300, size = (150, 150))

a = np.add(a, aa)
a = np.matrix(a)

with open('150x150_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.5f')

# 150 x 150 matrix
a = np.random.rand(150, 150)
aa = np.random.randint(1, 300, size = (150, 150))

a = np.add(a, aa)
a = np.matrix(a)

with open('150x150_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.5f')




# 200 x 200 matrix
a = np.random.rand(200, 200)
aa = np.random.randint(1, 300, size = (200, 200))

a = np.add(a, aa)
a = np.matrix(a)

with open('200x200_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.5f')

# 200 x 200 matrix
a = np.random.rand(200, 200)
aa = np.random.randint(1, 300, size = (200, 200))

a = np.add(a, aa)
a = np.matrix(a)

with open('200x200_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.5f')




# 250 x 250 matrix
a = np.random.rand(250, 250)
aa = np.random.randint(1, 300, size = (250, 250))

a = np.add(a, aa)
a = np.matrix(a)

with open('250x250_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.5f')

# 250 x 250 matrix
a = np.random.rand(250, 250)
aa = np.random.randint(1, 300, size = (250, 250))

a = np.add(a, aa)
a = np.matrix(a)

with open('250x250_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.5f')




# 500 x 500 matrix
a = np.random.rand(500, 500)
aa = np.random.randint(0, 20, size = (500, 500))

a = np.add(a, aa)
a = np.matrix(a)

with open('500x500.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.4f')

# 1000 x 1000 matrix
a = np.random.rand(1000, 1000)
aa = np.random.randint(0, 20, size = (1000, 1000))

a = np.add(a, aa)
a = np.matrix(a)

with open('1000x1000.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.4f')

# 500 x 500 matrix
a = np.random.rand(500, 500)
aa = np.random.randint(0, 20, size = (500, 500))

a = np.add(a, aa)
a = np.matrix(a)

with open('500x500_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.4f')

# 1000 x 1000 matrix
a = np.random.rand(1000, 1000)
aa = np.random.randint(0, 20, size = (1000, 1000))

a = np.add(a, aa)
a = np.matrix(a)

with open('1000x1000_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%.4f')



# # 100 x 100 matrix
# a = np.random.rand(100, 100)
# aa = np.random.randint(1, 300, size = (100, 100))

# a = np.add(a, aa)
# a = np.matrix(a)

# with open('100x100_1.txt','wb') as f:
#     for line in a:
#         np.savetxt(f, line, fmt='%.5f')

# # 100 x 100 matrix
# a = np.random.rand(100, 100)
# aa = np.random.randint(1, 300, size = (100, 100))

# a = np.add(a, aa)
# a = np.matrix(a)

# with open('100x100_2.txt','wb') as f:
#     for line in a:
#         np.savetxt(f, line, fmt='%.5f')

# 40 x 90 matrix
b = np.random.rand(40, 90)
bb = np.random.randint(1, 300, size = (40, 90))

b = b + bb
b = np.matrix(b)

with open('40x90_1.txt','wb') as f:
    for line in b:
        np.savetxt(f, line, fmt='%.5f')



# 90 x 40 matrix
c = np.random.rand(90, 40)
cc = np.random.randint(1, 300, size = (90, 40))

c = c + cc
c = np.matrix(c)

with open('90x40_1.txt','wb') as f:
    for line in c:
        np.savetxt(f, line, fmt='%.5f')



# 90 x 160 matrix
f = np.random.rand(90, 160)
ff = np.random.randint(1, 300, size = (90, 160))

f = np.add(f, ff)
f = np.matrix(f)

with open('90x160_1.txt','wb') as x:
    for line in f:
        np.savetxt(x, line, fmt='%.5f')