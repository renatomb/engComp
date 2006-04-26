!del f_rk.m
funcao=input('Entre com a funcao: ','s');
fid = fopen('f_rk.m','w');
fprintf(fid,'function retorno=f_rk(x,y)\n');
fprintf(fid,'retorno=%s;\n',funcao);
fclose(fid);
