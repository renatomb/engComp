LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY porta_and IS
	PORT (
		i1,i2	: in std_logic;
		o1		: out std_logic);
END ENTITY;
ARCHITECTURE behavioral OF porta_and IS
BEGIN
	o1 <= i1 and i2;
END ARCHITECTURE;

LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY porta_xor IS
	PORT (
		i1,i2	: in std_logic;
		o1		: out std_logic);
END ENTITY;
ARCHITECTURE behavioral OF porta_xor IS
BEGIN
	o1 <= i1 xor i2;
END ARCHITECTURE;

LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY porta_or IS
	PORT (
		i1,i2	: in std_logic;
		o1		: out std_logic);
END ENTITY;
ARCHITECTURE behavioral OF porta_or IS
BEGIN
	o1 <= i1 or i2;
END ARCHITECTURE;

LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY soma_1bit is 
	PORT (
		a,b,vem_um	: in std_logic;
		vai_um,soma	: out std_logic);
END soma_1bit;
ARCHITECTURE STRUCTURAL OF soma_1bit IS
	COMPONENT porta_and IS
		PORT (
			i1,i2	: in std_logic;
			o1		: out std_logic);
	END COMPONENT;
	COMPONENT porta_xor IS
		PORT (
			i1,i2	: in std_logic;
			o1		: out std_logic);
	END COMPONENT;
	COMPONENT porta_or IS
		PORT (
			i1,i2	: in std_logic;
			o1		: out std_logic);
	END COMPONENT;
	SIGNAL s1, s2, s3:std_logic;
BEGIN
	xor1:porta_xor
		PORT MAP (i1 =>a, i2 => b, o1 => s1);
	and1:porta_and
		PORT MAP (i1 =>a, i2 => b, o1 => s2);
	xor2:porta_xor
		PORT MAP (i1 => s1, i2 => vem_um, o1 => soma);
	and2:porta_and
		PORT MAP (i1 => s1, i2 => vem_um, o1 => s3);
	or1:porta_or
		PORT MAP (i1 => s2, i2 => s3, o1 => vai_um);
END ARCHITECTURE;

LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY soma_8 is 
	PORT (
		a0,a1,a2,a3,a4,a5,a6,a7,b0,b1,b2,b3,b4,b5,b6,b7,vemum	: in std_logic;
		vaium,s0,s1,s2,s3,s4,s5,s6,s7							: out std_logic);
END soma_8;
ARCHITECTURE STRUCTURAL OF soma_8 IS
	COMPONENT soma_1bit IS
	PORT (
		a,b,vem_um	: in std_logic;
		vai_um,soma	: out std_logic);
	END COMPONENT;
	SIGNAL tp0, tp1, tp2, tp3, tp4, tp5, tp6:std_logic;
BEGIN
	sum0:soma_1bit
		PORT MAP (a => a0, b => b0, vem_um => vemum, vai_um => tp0, soma => s0);
	sum1:soma_1bit
		PORT MAP (a => a1, b => b1, vem_um => tp0, vai_um => tp1, soma => s1);
	sum2:soma_1bit
		PORT MAP (a => a2, b => b2, vem_um => tp1, vai_um => tp2, soma => s2);
	sum3:soma_1bit
		PORT MAP (a => a3, b => b3, vem_um => tp2, vai_um => tp3, soma => s3);
	sum4:soma_1bit
		PORT MAP (a => a4, b => b4, vem_um => tp3, vai_um => tp4, soma => s4);
	sum5:soma_1bit
		PORT MAP (a => a5, b => b5, vem_um => tp4, vai_um => tp5, soma => s5);
	sum6:soma_1bit
		PORT MAP (a => a6, b => b6, vem_um => tp5, vai_um => tp6, soma => s6);
	sum7:soma_1bit
		PORT MAP (a => a7, b => b7, vem_um => tp6, vai_um => vaium, soma => s7);
END ARCHITECTURE;
