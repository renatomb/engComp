LIBRARY ieee;
USE ieee.std_logic_1164.all;
Entity porta_and is
	port (c,d,e: in std_logic;
	      o: out std_logic);
end entity;
Architecture behavioral of porta_and is
	begin
		o <= c and (d and e);
        end architecture;
LIBRARY ieee;
USE ieee.std_logic_1164.all;
Entity DEMUX is
	port (a,ctr1,ctr2: in std_logic;
	      s1,s2,s3 : out std_logic);
end entity;
Architecture structural of DEMUX is
	component  porta_and
		port (c,d,e: in std_logic;
		      o: out std_logic);
	end component;
	signal sinal_int1, sinal_int2:std_logic;
Begin
	sinal_int1 <= not ctr1;
	sinal_int2 <= not ctr2;
	and1:porta_and
		port map (c =>a, d => sinal_int1, e => sinal_int2, o => s1);
	and2: porta_and
		port map (c =>a,  d => sinal_int1, e=>ctr2,   o => s2);
	and3: porta_and
		port map (c =>a, d =>ctr1, e=>sinal_int2, o => s3);
end architecture;

