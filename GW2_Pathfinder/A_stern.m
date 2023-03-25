%A*-Algorithmus
function wayPointList = fcn(startnode, G, endnode, xStart, yStart, xEnd, yEnd)

openList = zeros(30,2);
openList(1,1) = startnode;
closedList = zeros(30,2);
actualNode = startnode;
f = 0;
g = 0;
h = 0;

while (actualNode ~= endnode)
    gParent = g; %g von Elternknoten, bis zum vorherigen Knoten
    for i = 1:30 % alle Knoten aus openList durchgehen und kleinstes f(n) suchen
        gParent = g; %g von Elternknoten, bis zum vorherigen Knoten
        actualNode = openList(i,1); 
        row = find(G.Edges.EndNodes(:,1) == 1);
        searchedRow = find(G.Edges.EndNodes(row,2) == 20);
        g = gParent + G.Edges.Weight(searchedRow); %Gewichtung von Knoten in openList
        h = sqrt(power(xStart(actualNode)-xEnd,2) + power(yStart(actualNode)-yEnd,2));
        f = g + h;
    end
end
