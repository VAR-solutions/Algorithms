program fibonacci;

var 
    i: integer;
    n: integer;

function fib(j:integer): integer;
begin
    if j = 1 then
        fib := 0
    else if v = 2 then
        fib := 1
    else
        fib := fib(j-1) + fib(j-2);
end;

begin
    readln(n);

    for i := 1 to n do
        write(fib(i), ' ');
end.
