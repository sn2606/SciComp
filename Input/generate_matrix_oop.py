import numpy as np

class Generate:
    def __init__(self, file_name, n, k):
        self.file_name = file_name
        self.n         = n
        self.dim       = (n, k)

    def new_matrix_int(self):
        a = np.matrix(np.random.randint(0, 100, size = (self.n, self.n)))
        with open(self.file_name, 'wb') as f:
            for line in a:
                np.savetxt(f, line, fmt='%d')

    def new_matrix_float(self):
        a = np.random.randint(0, 10, size = (self.n, self.n))
        aa = np.random.rand(self.n, self.n)
        a = np.matrix(np.add(a, aa))
        with open(self.file_name, 'wb') as f:
            for line in a:
                np.savetxt(f, line, fmt='%.4f')

    def new_matrix_dim(self):
        a = np.random.randint(0, 10, size = (self.dim[0], self.dim[1]))
        aa = np.random.rand(self.dim[0], self.dim[1])
        a = np.matrix(np.add(a, aa))
        with open(self.file_name, 'wb') as f:
            for line in a:
                np.savetxt(f, line, fmt='%.4f')

Generate('80x80.txt', 80, 80).new_matrix_int()
Generate('40x40_3.txt', 40, 40).new_matrix_float()
Generate('100x2.txt', 100, 2).new_matrix_dim()