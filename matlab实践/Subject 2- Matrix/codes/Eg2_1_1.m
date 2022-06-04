A = fix ( 10 + ( 99-10+1 ) * rand ( 5 ) )
B = 0.6+sqrt(0.1)*randn(5);
C = eye(5);
(A+B)*C == C*A+B*C