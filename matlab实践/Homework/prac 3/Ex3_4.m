A = [1,-1,2,3;5,1,-4,2;3,0,5,2;11,15,10,9];
V1 = diag(A);
Up1 =triu(A); % 上三角
Down1 = tril(A); % 下三角
R1 = rank(A);
N1 = norm(A);
C1 = cond(A);
T1 = trace(A);
B = [0.43,43,2;-8.9,4,21];
V2 = diag(B);
Up2 = triu(B);
Down2 = tril(B);
R2 = rank(B);
N2 = norm(B);
C2 = cond(B);
% T2 = trace(B); can not be complished, because it is not a phalanx

