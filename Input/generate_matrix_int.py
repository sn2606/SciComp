import numpy as np

# 32 x 32 matrix
a = np.random.randint(0, 100, size = (32, 32))
a = np.matrix(a)

with open('32x32_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')

a = np.random.randint(0, 100, size = (32, 32))
a = np.matrix(a)

with open('32x32_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')


# 64 x 64 matrix
a = np.random.randint(0, 100, size = (64, 64))
a = np.matrix(a)

with open('64x64_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')

a = np.random.randint(0, 100, size = (64, 64))
a = np.matrix(a)

with open('64x64_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')


# 128 x 128 matrix
a = np.random.randint(0, 100, size = (128, 128))
a = np.matrix(a)

with open('128x128_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')

a = np.random.randint(0, 100, size = (128, 128))
a = np.matrix(a)

with open('128x128_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')


# 256 x 256 matrix
a = np.random.randint(0, 100, size = (256, 256))
a = np.matrix(a)

with open('256x256_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')

a = np.random.randint(0, 100, size = (256, 256))
a = np.matrix(a)

with open('256x256_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')


# 512 x 512 matrix
a = np.random.randint(0, 100, size = (512, 512))
a = np.matrix(a)

with open('512x512_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')

a = np.random.randint(0, 100, size = (512, 512))
a = np.matrix(a)

with open('512x512_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')


# 1024 x 1024 matrix
a = np.random.randint(0, 100, size = (1024, 1024))
a = np.matrix(a)

with open('1024x1024_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')

a = np.random.randint(0, 100, size = (1024, 1024))
a = np.matrix(a)

with open('1024x1024_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')


# 2048 x 2048 matrix
a = np.random.randint(0, 100, size = (2048, 2048))
a = np.matrix(a)

with open('2048x2048_1.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')

a = np.random.randint(0, 100, size = (2048, 2048))
a = np.matrix(a)

with open('2048x2048_2.txt','wb') as f:
    for line in a:
        np.savetxt(f, line, fmt='%d')