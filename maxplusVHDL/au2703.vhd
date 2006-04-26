--- My basic gates ---
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
ENTITY porta_and3 IS
	PORT (
		i1,i2,i3	: in std_logic;
		o1			: out std_logic);
END ENTITY;
ARCHITECTURE behavioral OF porta_and3 IS
BEGIN
	o1 <= i1 and (i2 and i3);
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
ENTITY porta_or3 IS
	PORT (
		i1,i2,i3	: in std_logic;
		o1			: out std_logic);
END ENTITY;
ARCHITECTURE behavioral OF porta_or3 IS
BEGIN
	o1 <= i1 or (i2 or i3);
END ARCHITECTURE;

LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY porta_not IS
	PORT (
		i1	: in std_logic;
		o1	: out std_logic);
END ENTITY;
ARCHITECTURE behavioral OF porta_not IS
BEGIN
	o1 <= not i1;
END ARCHITECTURE;


--- My black box number one ---
LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY box1 is
	PORT (
		e1, e2, e3	: in std_logic;
		saida		: out std_logic);
END box1;
ARCHITECTURE STRUCTURAL OF box1 IS
	COMPONENT porta_and IS
		PORT (
			i1,i2	: in std_logic;
			o1		: out std_logic);
	END COMPONENT;
	COMPONENT porta_or IS
		PORT (
			i1,i2	: in std_logic;
			o1		: out std_logic);
	END COMPONENT;
	SIGNAL naum, trans1, trans2:std_logic;
BEGIN
	naum <= not e1;
	eee1:porta_and
	PORT MAP (i1 => e1, i2 => e2, o1 => trans1);
	eee2:porta_and
	PORT MAP (i1 => naum, i2 => e3, o1 => trans2);
	ouu1:porta_or
	PORT MAP (i1 => trans1, i2 => trans2, o1 => saida);
END ARCHITECTURE;

--- My black box number two ---
LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY box2 is
	PORT (
		e1, e2, e3	: in std_logic;
		saida		: out std_logic);
END box2;
ARCHITECTURE STRUCTURAL OF box2 IS
	COMPONENT porta_and IS
		PORT (
			i1,i2	: in std_logic;
			o1		: out std_logic);
	END COMPONENT;
	COMPONENT porta_or IS
		PORT (
			i1,i2	: in std_logic;
			o1		: out std_logic);
	END COMPONENT;
	COMPONENT porta_and3 IS
		PORT (
			i1,i2,i3	: in std_logic;
			o1			: out std_logic);
	END COMPONENT;
	COMPONENT porta_or3 IS
		PORT (
			i1,i2,i3	: in std_logic;
			o1			: out std_logic);
	END COMPONENT;
	SIGNAL n1, n2, n3, tp1, tp2, tp3:std_logic;
BEGIN
	n1 <= not e1;
	n2 <= not e2;
	n3 <= not e3;
	eee1:porta_and
	PORT MAP(i1 => e1, i2 => n2, o1 => tp1);
	eee2:porta_and
	PORT MAP(i1 => e1, i2 => n3, o1 => tp2);
	eee3:porta_and3
	PORT MAP(i1 => n1, i2 => e3, i3 => e2, o1 => tp3);
	oou1:porta_or3
	PORT MAP(i1 => tp1, i2 => tp2, i3 => tp3, o1 => saida);
END ARCHITECTURE;

--- My biggest black box ---
LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY au2703 is 
	PORT (
		x0,x1,x2,y0,y1,y2,w0,w1,w2	: in std_logic;
		z0,z1,z2					: out std_logic);
END au2703;

LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY au2703 is 
	PORT (
		x0,x1,x2,y0,y1,y2,w0,w1,w2	: in std_logic;
		z0,z1,z2					: out std_logic);
END au2703;
ARCHITECTURE STRUCTURAL OF au2703 IS
	COMPONENT porta_or3 IS
		PORT (
			i1,i2,i3	: in std_logic;
			o1			: out std_logic);
	END COMPONENT;
	COMPONENT porta_not IS
		PORT (
			i1	: in std_logic;
			o1	: out std_logic);
	END COMPONENT;
	COMPONENT box1 IS
		PORT (
			e1, e2, e3	: in std_logic;
			saida		: out std_logic);
	END COMPONENT;
	COMPONENT box2 IS
		PORT (
			e1, e2, e3	: in std_logic;
			saida		: out std_logic);
	END COMPONENT;
	SIGNAL sin1, sin2, sin3, sin4, sin5:std_logic;
BEGIN
	ouzzao:porta_or3
	PORT MAP(i1 => x2, i2 => x1, i3 => x0, o1 => sin1);
	caixa1:box1
	PORT MAP(e1 => sin1, e2 => y2, e3 => w2, saida => sin4);
	caixa2:box1
	PORT MAP(e1 => sin1, e2 => y1, e3 => w1, saida => sin3);
	caixa3:box1
	PORT MAP(e1 => sin1, e2 => y0, e3 => w0, saida => sin2);
	sin5 <= not sin2;
	z0 <= sin5;
	caixa4:box1
	PORT MAP(e1 => sin3, e2 => sin5, e3 => sin2, saida => z1);
	caixa5:box2
	PORT MAP(e1 => sin4, e2 => sin3, e3 => sin2, saida => z2);
END ARCHITECTURE;

