function retorno=erro(vreal,vesp)
% Esta funcao calcula o erro percentual.
% Sintaxe: erro(valor real, valor esperado).
try
   erro=((vreal-vesp)/vesp)*100;
   disp(['Erro percentual: ' num2str(erro) '%']);
catch
   disp('Nao foi possivel calcular o erro percentual. Favor usar: Erro(V-Real,V-Esperado)');
end
