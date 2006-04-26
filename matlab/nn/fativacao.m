function fat=fativacao(id,x_)
%Calcula a funcao de ativacao para o x dado.
%Use: fativacao(id_funcao,valor_x)
switch (id)
case {0}
    fat=x_;
case {1}
    fat=1./(1+exp(-4.*x_));
case {2}
    fat=(1-exp(-4*x_))./(1+exp(-4.*x_));
case {3}
    fat=atan(x_);
end