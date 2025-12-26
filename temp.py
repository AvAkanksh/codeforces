
Q,K,V

[1] [2] [3] [1] [2] [3]

embedding -> Rd


(QK'/sqrt(d))*V
 
X -> n*d

MLP -> Q, K, V
import torch
import torch.nn as nn
import numpy 
class SelfAttension():
    def __init__(self):
        super().__init__()

    def forward(self, X):
        N,d = X.shape
        W_q = numpy.rand(d,d);
        W_k = numpy.rand(d,d);
        W_v = numpy.rand(d,d);

        q = X@W_q; 
        k = X@W_k; # Nxd
        v = X@W_v;

        A = []
        for i in range(N):
            query = q[i] # R_d
            z_total = [] # R_N
            for j in range(N):
                z = query.dot(k[j]) # 1x1
                z_total.append(z)
            A.append(z_total)

        # A -> NxN
        



        
        