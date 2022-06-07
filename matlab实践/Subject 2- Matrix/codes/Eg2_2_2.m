A = magic(7);
D1 = diag(A);
B = flipud(A);
% 实现对矩阵A的上下翻转，将原来的副对角元素变换成主对角元素
D2 = diag(B);
sum(D1)
sum(D2)