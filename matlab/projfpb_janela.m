clear
clc
disp('Projeto de filtro passa-baixas')
disp('  ')
wp = input('Entre com a frequencia da faixa de passagem, wp: ');
ws = input('Entre com a frequencia da faixa de rejeiçao, ws: ');
disp('  ')
disp('Escolha da janela')
disp('  ')
disp('Opçoes')
disp('  ')
disp('1 - Retangular')
disp('  ')
disp('2 - Hanning')
disp('  ')
disp('3 - Hamming')
disp('  ')
disp('4 - BLackman')
disp('  ')
opcao = input('Entre com a janela desejada: ');

ftr = ws - wp;
wc = (wp+ws)/2;

if opcao == 1
    N = ceil(1.8*pi/ftr);
    hd = ideal_lp(wc,N);
    w = (rectwin(N))';
elseif opcao == 2
    N = ceil(6.2*pi/ftr);
    hd = ideal_lp(wc,N);
    w = (hann(N))';
elseif opcao == 3
    N = ceil(6.6*pi/ftr);
    hd = ideal_lp(wc,N);
    w = (hamming(N))';
elseif opcao == 4
    N = ceil(11*pi/ftr);
    hd = ideal_lp(wc,N);
    w = (blackman(N))';
end

h = hd .* w;
[db,mag,fase,grd,w] = freqz_m(h,[1]);
dw = 2*pi/1000;
Rp = -(min(db(1:1:wp/dw+1)));
As = -round(max(db(ws/dw+1:1:501)));
clc
disp('  ')
disp('Saida de dados')
disp('  ')
text1= [' dp = ' num2str(Rp)];
disp(text1)
disp('  ')
text2= [' As = ' num2str(As) ' dB'];
disp(text2)
disp('  ')
text3 = [' N = ' num2str(N)];
disp(text3)
disp('  ')
