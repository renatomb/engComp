clear all
A=input('Entre com a matriz a ser escalonada ');
B=eye(size(A));
for i=1:size(A,1)
   pivo=A(i,i);
   A(i,:)=A(i,:)/pivo;
   B(i,:)=B(i,:)/pivo;
	for j=[1:i-1 i+1:size(A,1)]
     pivo2=A(j,i);
     A(j,:)=A(j,:)-pivo2*A(i,:);
     B(j,:)=B(j,:)-pivo2*B(i,:);
   end
end
disp('Inversa da matriz fornecida:');
disp(B);