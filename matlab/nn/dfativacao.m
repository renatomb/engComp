function resultado=dfativacao(id,x_)
switch(id)
    case {0}
        resultado=ones(1,length(x_));
    case {1}
        resultado=4.*exp(-4.*x_)./(1+exp(-8.*x_));
    case {2}
        resultado=8.*exp(-4.*x_)./(1+exp(-4.*x_)).^2;
    case {3}
        resultado=1./(1+x_.^2);
end