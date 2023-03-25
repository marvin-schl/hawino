A = zeros(144,144);
numberOfNotes = 144;

% Verbindung zu relevanten Knoten
for i = 1:numberOfNotes
    if i-1>0 && mod(i, 18) ~= 1
        A(i-1,i) = 1;
    end
    if i+1<numberOfNotes+1 && mod(i,18) ~= 0
        A(i+1,i)= 1;
    end
    if i+18<numberOfNotes+1
        A(i+18,i)=1;
    end
    if i-18>0
        A(i-18,i)=1;
    end
    if i+19 < numberOfNotes+1 && mod(i,18) ~= 0
        A(i+19,i) = sqrt(2);
    end
    if i+17 < numberOfNotes+1 && mod(i, 18) ~= 1
        A(i+17,i) = sqrt(2);
    end
     if i-19 > 0 && mod(i,18) ~= 1
        A(i-19,i) = sqrt(2);
    end
    if i-17 > 0 && mod(i, 18) ~= 0
        A(i-17,i) = sqrt(2);
    end
end

% Löschen der Verbindungen zu den Station
for i= 1:144
    A(92,i) = 0;
    A(i,92) = 0;
    A(93,i) = 0;
    A(i,93) = 0;
    A(96,i) = 0;
    A(i,96) = 0;
    A(99,i) = 0;
    A(i,99) = 0;
    A(102,i) = 0;
    A(i,102) = 0;
    A(110,i) = 0;
    A(i,110) = 0;
    A(111,i) = 0;
    A(i,111) = 0;
    A(114,i) = 0;
    A(i,114) = 0;
    A(117,i) = 0;
    A(i,117) = 0;
    A(120,i) = 0;
    A(i,120) = 0;
    A(124,i) = 0;
    A(i,124) = 0;
    A(125,i) = 0;
    A(i,125) = 0;
    A(142,i) = 0;
    A(i,142) = 0;
    A(143,i) = 0;
    A(i,143) = 0;
end

G = graph(A);

%% Koordinatensystem erstellen
x = zeros(20,1);
y = zeros(20,1);
row = 1;
col = 1;

for zaehler = 1:numberOfNotes
    x(zaehler) = col;
    y(zaehler) = row;
    col = col + 1;
    if mod(zaehler,18) == 0 && zaehler ~=1
        col = 1;
        row = row + 1;
    end
end

plot(G, "XData",x,"YData",y);

name = zeros(numberOfNotes,1);
for n = 1:numberOfNotes
    name(n) = n;
end

figure();
plot(G, "XData",x,"YData",y, "NodeLabel", name);




