-- Porta B1
LIBRARY ieee;
USE ieee.std_logic_1164.all;
Entity porta_b1 is
	port (a,b: in std_logic;
	      d: out std_logic);
end entity;
Architecture behavioral of porta_b1 is
	begin
		d <= a and b;
end architecture;
-- Porta B2
LIBRARY ieee;
USE ieee.std_logic_1164.all;
Entity porta_b2 is
	port (a,b,c: in std_logic;
	      d: out std_logic);
end entity;
Architecture behavioral of porta_b2 is
	begin
		d <= a and (b and c);
end architecture;
-- Porta B3
LIBRARY ieee;
USE ieee.std_logic_1164.all;
Entity porta_b3 is
	port (a,b,c: in std_logic;
	      d: out std_logic);
end entity;
Architecture behavioral of porta_b3 is
	begin
		d <= (a or b) and c;
end architecture;
-- THE Black BOX
LIBRARY ieee;
USE ieee.std_logic_1164.all;
Entity NADJA is 
	port (a,b,a: in std_logic;
	      d: out std_logic);
end entity;
Architecture structural of NADJA is
	component porta_b1
	component porta_b2
	component porta_b3
		port (a,b,c: in std_logic;
		      d: out std_logic);
	end component;
	signal s1, s2, std_logic;
Begin
	and1:porta_b1
		port map (a =>a, b => b, c => c, o => s1);
	and2:porta_b2
		port map (a =>a, b => b, c => c, o => s2)
	and3:porta_b3
		port map (a =>s1, b => b, c => s2, o => saida);
end architecture;

