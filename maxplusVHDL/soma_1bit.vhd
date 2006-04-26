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
