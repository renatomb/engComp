

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

ENTITY CPU_CONTROLLER IS
	PORT (	CLK,											-- SINAL DO CLOCK DO SISTEMA
			N,Z: IN STD_LOGIC;								-- SINAIS DDE TESTE DA ULA
			AMUX,											-- CONTROLA A ENTRADA ESQUERDA DA ULA
			MBR,											-- CARREGA MBR A PARTIR DO DESLOCADOR
			MAR,											-- CARREGA MAR A PARTIR DO LATCH B
			RD,												-- REQUISITA LEITURA DA MEMÓRIA
			WR,												-- REQUISITA ESCRITA NA MEMÓRIA
			ENC: OUT STD_LOGIC;								-- HABILITA BARRAMENTO C
			ULA,											-- CONTROLA OPERAÇÕES DA ULA
			SH: OUT STD_LOGIC_VECTOR(1 DOWNTO 0);			-- CONTROLA O DESLOCAMENTO DA SAIDA DA ULA
			A, B, C: OUT STD_LOGIC_VECTOR(3 DOWNTO 0));		-- DEFINE POSIÇÕES DOS REGISTRADORES DA MEMÓRIA DE RASCUNHO
END CPU_CONTROLLER;

ARCHITECTURE CPU_STATE_MACHINE OF CPU_CONTROLLER IS
	SIGNAL COND: STD_LOGIC_VECTOR(1 DOWNTO 0);				-- CONTROLA O DESVIO/SEQUENCIAMENTO 
	SIGNAL PRESENT_STATE,									-- O ESTADO ATUAL
		   NEXT_STATE: UNSIGNED(6 DOWNTO 0);				-- SERA P PROXIMO ESTADO NA SUBIDA DO CLOCK
	BEGIN
		
		-- PROCESSA O ESTADO DA MAQUINA
		STATE_COMB: PROCESS (PRESENT_STATE)
			BEGIN
           			CASE PRESENT_STATE IS
					--LINHA 00
					--MAR:=PC; RD;
					WHEN "0000000" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='1';RD<='1';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE      	

					--LINHA 01
					--PC:=PC+1; RD;
					WHEN "0000001" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='1';C<="0000";B<="0110";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 02
					--IR:=MBR; IF N THEN GOTO 28;
					WHEN "0000010" => AMUX<='1'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0011";B<="0000";A<="0000";
							NEXT_STATE <= "0011100";

					--LINHA 03
					--TIR:=LSHIFT(IR+IR); IF N THEN GOTO 19;
					WHEN "0000011" => AMUX<='0'; COND<="01"; ULA<="00";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0011";A<="0011";
							NEXT_STATE <= "0010011";

					--LINHA 04
					--TIR:=LSHIFT(TIR); IF N THEN GOTO 11;
					WHEN "0000100" => AMUX<='0'; COND<="01"; ULA<="10";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0000";A<="0100";
							NEXT_STATE <= "0001011";

					--LINHA 05
					--ALU:=TIR; IF N THEN GOTO 9;
					WHEN "0000101" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0001001";

					--LINHA 06
					--MAR:=IR; RD;
					WHEN "0000110" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='1';RD<='1';WR<='0';ENC<='1';C<="0000";B<="0011";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 07
					--RD;
					WHEN "0000111" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 08
					--AC := MBR; GOTO 0;
					WHEN "0001000" => AMUX<='1'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0001";B<="0000";A<="0000";
							NEXT_STATE <= "0000000";

					--LINHA 09
					--MAR := IR; MBR := AC; WR;
					WHEN "0001001" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='1';
							MAR<='1';RD<='0';WR<='1';ENC<='0';C<="0000";B<="0011";A<="0001";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 10
					--WR; GOTO 0;
					WHEN "0001010" => AMUX<='0'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='1';ENC<='0';C<="0000";B<="0000";A<="0000";
							NEXT_STATE <= "0000000";

					--LINHA 11
					--ALU := TIR; IF N THEN GOTO 15;
					WHEN "0001011" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0001111";

					--LINHA 12
					--MAR:=IR; RD;
					WHEN "0001100" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='1';RD<='1';WR<='0';ENC<='0';C<="0000";B<="0011";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 13					
					--RD;
					WHEN "0001101" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 14					
					--AC := MBR + AC; GOTO 0;
					WHEN "0001110" => AMUX<='1'; COND<="11"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0001";B<="0001";A<="0000";
							NEXT_STATE <= "0000000";

					--LINHA 15					
					--MAR := IR; RD;
					WHEN "0001111" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='1';RD<='1';WR<='0';ENC<='1';C<="0000";B<="0011";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 16					
					--AC := AC + 1; RD;
					WHEN "0010000" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='1';C<="0001";B<="0001";A<="0110";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 17					
					--A := INV (MBR);
					WHEN "0010001" => AMUX<='1'; COND<="00"; ULA<="11";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="0000";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 18					
					--AC := AC + A; GOTO 0;
					WHEN "0010010" => AMUX<='0'; COND<="11"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='1';C<="0001";B<="0001";A<="1010";
							NEXT_STATE <= "0000000";

					--LINHA 19					
					--TIR:=LSHIFT(TIR); IF N THEN GOTO 25;
					WHEN "0010011" => AMUX<='0'; COND<="01"; ULA<="10";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0000";A<="0100";
							NEXT_STATE <= "0011001";

					--LINHA 20
					--ALU := TIR; IF N THEN GOTO 23;
					WHEN "0010100" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0010111";

					--LINHA 21					
					--ALU := AC; IF N THEN GOTO 0;
					WHEN "0010101" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0001";
							NEXT_STATE <= "0000000";

					--LINHA 22					
					--PC := BAND(IR, AMASK); GOTO 0;
					WHEN "0010110" => AMUX<='0'; COND<="11"; ULA<="01";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0000";B<="0011";A<="1000";
							NEXT_STATE <= "0000000";

					--LINHA 23					
					--ALU := AC; IF Z THEN GOTO 22;
					WHEN "0010111" => AMUX<='0'; COND<="10"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0001";
							NEXT_STATE <= "0010110";

					--LINHA 24					
					--GOTO 0;
					WHEN "0011000" => AMUX<='0'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0000";
							NEXT_STATE <= "0000000";

					--LINHA 25					
					--ALU := TIR; IF N THEN GOTO 27;
					WHEN "0011001" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0011011";

					--LINHA 26					
					--PC := BAND (IR, AMASK); GOTO 0;
					WHEN "0011010" => AMUX<='0'; COND<="11"; ULA<="01";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0000";B<="0011";A<="1000";
							NEXT_STATE <= "0000000";

					--LINHA 27					
					--AC := BAND (IR, AMASK); GOTO 0;
					WHEN "0011011" => AMUX<='0'; COND<="11"; ULA<="01";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0001";B<="0011";A<="1000";
							NEXT_STATE <= "0000000";

					--LINHA 28					
					--TIR := LSHIFT (IR + IR); IF N THEN GOTO 40;
					WHEN "0011100" => AMUX<='0'; COND<="01"; ULA<="00";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0011";A<="0011";
							NEXT_STATE <= "0101000";

					--LINHA 29					
					--TIR := LSHIFT (TIR); IF N THEN GOTO 35;
					WHEN "0011101" => AMUX<='0'; COND<="01"; ULA<="10";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0000";A<="0100";
							NEXT_STATE <= "0100011";

					--LINHA 30					
					--ALU := TIR; IF N THEN GOTO 33;
					WHEN "0011110" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0100001";

					--LINHA 31					
					--A := IR + SP;
					WHEN "0011111" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="0010";A<="0011";
							NEXT_STATE <= "0000111";

					--LINHA 32					
					--MAR := A; RD; GOTO 7;
					WHEN "0100000" => AMUX<='1'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0011";B<="0000";A<="0000";
							NEXT_STATE <= "0000111";
					
					--LINHA 33
					--A := IR + SP;
					WHEN "0100001" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="0010";A<="0011";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE
					
					--LINHA 34
					--MAR := A; MBR := AC; WR; GOTO 10;
					WHEN "0100010" => AMUX<='0'; COND<="11"; ULA<="10";SH<="00";MBR<='1';
							MAR<='1';RD<='0';WR<='1';ENC<='0';C<="0000";B<="1010";A<="0001";
							NEXT_STATE <= "0001010";
					
					--LINHA 35
					--ALU := TIR; IF N THEN GOTO 38;
					WHEN "0100011" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0100110";
				
					--LINHA 36
					--A := IR + SP;
					WHEN "0100100" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="0010";A<="0011";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE
			
					--LINHA 37
					--MAR := A; RD; GOTO 13;
					WHEN "0100101" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="0010";A<="0011";
							NEXT_STATE <= "0001101";
					
					--LINHA 38
					--A := IR + SP;
					WHEN "0100110" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="0010";A<="0011";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE
					
					--LINHA 39
					--MAR := A; RD; GOTO 16;
					WHEN "0100111" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="0010";A<="0011";
							NEXT_STATE <= "0001101";
					
					--LINHA 40
					--TIR := LSHIFT (TIR); IF N THEN GOTO 46;
					WHEN "0101000" => AMUX<='0'; COND<="01"; ULA<="10";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0000";A<="0100";
							NEXT_STATE <= "0101110";
					
					--LINHA 41
					--ALU := TIR; IF N THEN GOTO 44;
					WHEN "0101001" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0101100";
					
					--LINHA 42
					--ALU := AC; IF N THEN GOTO 22;
					WHEN "0101010" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0001";
							NEXT_STATE <= "0010110";
					
					--LINHA 43
					--GOTO 0;
					WHEN "0101011" => AMUX<='0'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0000";
							NEXT_STATE <= "0000000";
					
					--LINHA 44
					--ALU := AC; IF Z THEN GOTO 0;
					WHEN "0101100" => AMUX<='0'; COND<="10"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0001";
							NEXT_STATE <= "0000000";
					
					--LINHA 45
					--PC := BAND (IR, AMASK); GOTO 0;
					WHEN "0101101" => AMUX<='0'; COND<="11"; ULA<="01";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0000";B<="0011";A<="1000";
							NEXT_STATE <= "0000000";
					
					--LINHA 46
					--TIR := LSHIFT (TIR); IF N THEN GOTO 50;
					WHEN "0101110" => AMUX<='0'; COND<="01"; ULA<="10";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0000";A<="0100";
							NEXT_STATE <= "0110010";
					
					--LINHA 47
					--SP := SP + (-1);
					WHEN "0101111" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0010";B<="0111";A<="0010";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE
					
					--LINHA 48
					--MAR := SP; MBR := PC; WR;
					WHEN "0110000" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='1';
							MAR<='1';RD<='0';WR<='1';ENC<='0';C<="0000";B<="0010";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE
					
					--LINHA 49
					--PC := BAND (IR + AMASK); WR; GOTO 0;
					WHEN "0110001" => AMUX<='0'; COND<="11"; ULA<="01";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='1';ENC<='1';C<="0000";B<="0011";A<="1000";
							NEXT_STATE <= "0000000";

					--LINHA 50
					--TIR := LSHIFT (TIR); IF N THEN GOTO 65;
					WHEN "0110010" => AMUX<='0'; COND<="01"; ULA<="10";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0000";A<="0100";
							NEXT_STATE <= "1000001";

					--LINHA 51
					--TIR := LSHIFT (TIR); IF N THEN GOTO 59;
					WHEN "0110011" => AMUX<='0'; COND<="01"; ULA<="10";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0000";A<="0100";
							NEXT_STATE <= "0111011";

					--LINHA 52
					--ALU := TIR; IF N THEN GOTO 56;
					WHEN "0110100" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0111000";

					--LINHA 53
					--MAR := AC; RD;
					WHEN "0110101" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='1';RD<='1';WR<='0';ENC<='0';C<="0000";B<="0001";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 54
					--SP := SP + (-1); RD;
					WHEN "0110110" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='1';C<="0010";B<="0111";A<="0010";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 55
					--MAR := SP; WR; GOTO 10";
					WHEN "0110111" => AMUX<='0'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='1';RD<='0';WR<='1';ENC<='0';C<="0000";B<="0010";A<="0000";
							NEXT_STATE <= "0001010";

					--LINHA 56
					--MAR := SP; SP := SP + 1; RD;
					WHEN "0111000" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='1';RD<='1';WR<='0';ENC<='1';C<="0010";B<="0110";A<="0010";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 57
					--RD;
					WHEN "0111001" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 58
					--MAR := AC; WR; GOTO 10";
					WHEN "0111010" => AMUX<='0'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='1';RD<='0';WR<='1';ENC<='0';C<="0000";B<="0001";A<="0000";
							NEXT_STATE <= "0001010";

					--LINHA 59
					--ALU := TIR; IF N THEN GOTO 62;
					WHEN "0111011" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "0111110";

					--LINHA 60
					--SP := SP + (-1);
					WHEN "0111100" =>  AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0010";B<="0111";A<="0010";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 61
					--MAR := SP; MBR := AC; WR; GOTO 10";
					WHEN "0111101" => AMUX<='0'; COND<="11"; ULA<="10";SH<="00";MBR<='1';
							MAR<='1';RD<='0';WR<='1';ENC<='0';C<="0000";B<="0010";A<="0001";
							NEXT_STATE <= "0001010";

					--LINHA 62
					--MAR := SP; SP := SP + 1; RD;
					WHEN "0111110" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='1';RD<='1';WR<='0';ENC<='1';C<="0010";B<="0110";A<="0010";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 63
					--RD;
					WHEN "0111111" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 64
					--AC := MBR; GOTO 0;
					WHEN "1000000" => AMUX<='1'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0001";B<="0000";A<="0000";
							NEXT_STATE <= "0000000";
			
					--LINHA 65
					--TIR := LSHIFT (TIR); IF N THEN GOTO 73;
					WHEN "1000001" => AMUX<='0'; COND<="01"; ULA<="10";SH<="01";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0100";B<="0000";A<="0100";
							NEXT_STATE <= "1001001";

					--LINHA 66
					--ALU := TIR; IF N THEN GOTO 70;
					WHEN "1000010" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "1000110";

					--LINHA 67
					--MAR := SP; SP := SP + 1; RD;
					WHEN "1000011" => AMUX<='0'; COND<="00"; ULA<="00";SH<="00";MBR<='0';
							MAR<='1';RD<='1';WR<='0';ENC<='1';C<="0010";B<="0110";A<="0010";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 68
					--RD;
					WHEN "1000100" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='1';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 69
					--PC := MBR; GOTO 0;
					WHEN "1000101" => AMUX<='1'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0001";B<="0000";A<="0000";
							NEXT_STATE <= "0000000";

					--LINHA 70
					--A := AC;
					WHEN "1000110" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="0000";A<="0001";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 71
					--AC := SP;
					WHEN "1000111" => AMUX<='0'; COND<="00"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0001";B<="0000";A<="0010";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 72
					--SP := A; GOTO 0;
					WHEN "1001000" => AMUX<='0'; COND<="11"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0010";B<="0000";A<="1010";
							NEXT_STATE <= "0000000";

					--LINHA 73
					--ALU := TIR; IF N THEN GOTO 76;
					WHEN "1001001" => AMUX<='0'; COND<="01"; ULA<="10";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='0';C<="0000";B<="0000";A<="0100";
							NEXT_STATE <= "1001100";

					--LINHA 74
					--A := BAND (IR, SMASK);
					WHEN "1001010" => AMUX<='0'; COND<="00"; ULA<="01";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="1001";A<="0011";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 75
					--SP := SP + A; GOTO 0;
					WHEN "1001011" => AMUX<='0'; COND<="11"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="0010";B<="1010";A<="0010";
							NEXT_STATE <= "0000000";

					--LINHA 76
					--A := BAND (IR, SMASK);
					WHEN "1001100" => AMUX<='0'; COND<="00"; ULA<="01";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="1001";A<="0011";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 77
					--A := INV (A);
					WHEN "1001101" => AMUX<='0'; COND<="00"; ULA<="11";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="1010";A<="0000";
							-- NEXT_STATE <= "0000000";	-- DON'T CARE

					--LINHA 78
					--A := A + 1; GOTO 75;
					WHEN "1001110" => AMUX<='0'; COND<="11"; ULA<="00";SH<="00";MBR<='0';
							MAR<='0';RD<='0';WR<='0';ENC<='1';C<="1010";B<="1010";A<="0110";
							NEXT_STATE <= "1001011";
					WHEN OTHERS =>
				END CASE;

	END PROCESS STATE_COMB;

	-- PROCESSA O CLOCK
	STATE_CLOCKED: PROCESS (CLK)
		BEGIN
			IF RISING_EDGE (CLK) THEN
				IF ((N='1' AND COND(0)='1') OR (Z='1' AND COND(1)='1') OR (COND(1)='1' AND COND(0)='1')) THEN
					PRESENT_STATE <= NEXT_STATE;
				ELSE
					PRESENT_STATE <= PRESENT_STATE + 1;
				END IF;
			END IF;
	END PROCESS STATE_CLOCKED;


END CPU_STATE_MACHINE;
