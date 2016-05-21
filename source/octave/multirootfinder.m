
global values = csvread("values.csv");
guesses = csvread("guesses.csv");

function y = f(x)
	global values;
	y = zeros(6,1);
	y(1) = x(1) + x(2) + x(3) + x(4) - values(1);
	y(2) = x(5) + x(3) + x(4) - values(2);
	y(3) = x(6) + x(2) + x(4) - values(3);
	y(4) = ((x(1)*x(5))/x(3)) - values(4);
	y(5) = ((x(1)*x(6))/x(2)) - values(5);
	y(6) = ((x(3)*x(6))/x(4)) - values(6);
endfunction

[roots] = fsolve(@f, guesses);
csvwrite("roots.csv", roots);