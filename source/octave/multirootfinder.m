
global values = csvread("octave/values.csv");
base_guesses = csvread("octave/guesses.csv");

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

[roots] = [-1,-1,-1,-1,-1,-1];
count = 0;
guesses = base_guesses;

while (any(any(roots < 0)))
	[roots] = fsolve(@f, guesses);
	rands = unifrnd(0.5,2,1,6);
	guesses = base_guesses.*rands;
	++count;
endwhile
csvwrite("octave/roots.csv", roots);