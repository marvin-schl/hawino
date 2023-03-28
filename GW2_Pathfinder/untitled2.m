A = zeros(20,20);
% Verbindung zu relevanten Knoten
for i = 1:20
    if i-1>0 && mod(i, 4) ~= 1
        A(i-1,i) = 1;
    end
    if i+1<21 && mod(i,4) ~= 0
        A(i+1,i)= 1;
    end
    if i+4<21
        A(i+4,i)=1;
    end
    if i-4>0
        A(i-4,i)=1;
    end
    if i+5 < 21 && mod(i,4) ~= 0
        A(i+5,i) = sqrt(2);
    end
    if i+3 < 21 && mod(i, 4) ~= 1
        A(i+3,i) = sqrt(2);
    end
     if i-5 > 0 && mod(i,4) ~= 1
        A(i-5,i) = sqrt(2);
    end
    if i-3 > 0 && mod(i, 4) ~= 0
        A(i-3,i) = sqrt(2);
    end
end

% Lösen der Station
for i= 1:20
    A(3,i) = 0;
    A(i,3) = 0;
    A(7,i) = 0;
    A(i,7) = 0;
end

G = graph(A);


eid1 = outedges(G,6) % alle Zeilen in G, wo Knoten 6 an Kante beteiligt
eid2 = outedges(G,2)
val=intersect(eid1,eid2) % Arrays auf gleiche werte prüfen


openList = zeros(30,4);         % 1: Node, 2: f, 3: g, 4: ParentNode
openList(1,1) = startnode;
u = find(openList(:,1)==0)
openList(1,:)=0;
find(openList(:,1))
