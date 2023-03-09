numberOfNodes = 144;
numberOfColumns = 18;
A = zeros(numberOfNodes);

% Verbindung zu relevanten Knoten
for i = 1:numberOfNodes
    if i-1>0 && mod(i, numberOfColumns) ~= 1
        A(i-1,i) = 1000;
    end
    if i+1<numberOfNodes+1 && mod(i,numberOfColumns) ~= 0
        A(i+1,i)= 1000;
    end
    if i+numberOfColumns<numberOfNodes+1
        A(i+numberOfColumns,i)=1000;
    end
    if i-numberOfColumns>0
        A(i-numberOfColumns,i)=1000;
    end
    if i+numberOfColumns+1 < numberOfNodes+1 && mod(i,numberOfColumns) ~= 0
        A(i+numberOfColumns+1,i) = sqrt(2)*1000;
    end
    if i+numberOfColumns-1 < numberOfNodes+1 && mod(i, numberOfColumns) ~= 1
        A(i+numberOfColumns-1,i) = sqrt(2)*1000;
    end
     if i-numberOfColumns+1 > 0 && mod(i,numberOfColumns) ~= 0
        A(i-numberOfColumns+1,i) = sqrt(2)*1000;
    end
    if i-numberOfColumns-1 > 0 && mod(i, numberOfColumns) ~= 1
        A(i-numberOfColumns-1,i) = sqrt(2)*1000;
    end
end

% Lösen der Station
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

%Graph = graph(A);

% Umrechung von Knoten in Koordinaten
xKnoten = zeros(numberOfNodes,1);
yKnoten = zeros(numberOfNodes,1);
row = 600;
col = 200;
for i = 1:numberOfNodes
    xKnoten(i) = col;
    yKnoten(i) = row;
    col = col + 400;
    if mod(i,numberOfColumns) == 0 
        col = 200;
        row = row + 400;
    end 
end

%% 
xRobot = 1500;
yRobot = 1200;

startKnoten = 0;
startKnotenArray = 0;
diff_x = zeros(size(xKnoten,1),1);
diff_y = zeros(size(yKnoten,1),1);

for i = 1:size(xKnoten,1)
    diff_x(i) = abs(xRobot-xKnoten(i));
end

for i = 1:size(yKnoten,1)
    diff_y(i) = abs(yRobot-yKnoten(i));
end

xMin = min(diff_x);
yMin = min(diff_y);

xStart = find(diff_x == xMin);
yStart = find(diff_y == yMin);

startKnotenArray = intersect(xStart, yStart);

startKnoten = startKnotenArray(1,1);


%% 
startnode = startKnoten;
endnode = 103;
xNode = xKnoten;
yNode = yKnoten;
xEnd = 4893;
yEnd = 2741;

Graph = graph(A);

%remoove nodes
%Graph = rmnode(Graph, [...]) 
numberOfNodes = 144;
%h = [7; 6; 5; 4; 6; 5; 4; 3; 5; 4; 3; 2; 4; 3; 2; 1; 3; 2; 1; 0];

openList = zeros(50,5);         % 1: Node, 2: f, 3: g, 4: ParentNode, 5: h
openList(1,1) = startnode;
closedList = zeros(50,4);       % 1: Node, 2: f, 3: g, 4: ParentNode, 5: h
f = sqrt(power(xNode(startnode)-xEnd,2) + power(yNode(startnode)-yEnd,2)); 
% weil f = g + h und g müsste bei Startknoten 0 sein
openList(1,2) = f;
g = zeros(numberOfNodes,1);
g(startnode) = 0;
openList(1,3) = g(startnode);
gParent = 0;
counter = 1;
nextNode = startnode;
actualNode = 0;
inClosedList = false;
inOpenList = false;

while (nextNode ~= endnode)
    
%Suche nach Node mit kleinstem f in openList
    for i = 1:numberOfNodes % alle Knoten aus openList durchgehen und kleinstes f(n) suchen
        if openList(i,1)~=0
            actualNode = openList(i,1);
        else
            break;
        end

        if actualNode > 1
            row1 = outedges(Graph,nextNode); % alle Zeilen in G (von Kanten) wo Knoten 6 beteiligt ist
            row2 = outedges(Graph,actualNode); % alle Zeilen in G wo aktueller Knoten beteiligt ist
            searchedRow = intersect(row1,row2);
            if openList(i,2) == 0
                g(actualNode) = gParent + Graph.Edges.Weight(searchedRow); %Gewichtung von Knoten in openList
                h = sqrt(power(xNode(actualNode)-xEnd,2) + power(yNode(actualNode)-yEnd,2)) ;
                f = g(actualNode) + h;
                openList(i,2) = f;
                openList(i,5) = h;
            end
        end
    end
    % Node mit kleinstem f finden
    if actualNode > 1
        Z=openList(:,2);
        Z(Z==0)=nan;
        fmin = min(Z);
        index = find(openList(:,2)==fmin);
        nextNode = openList(index(1),1);
        gParent = g(nextNode);
    else
        fmin = 0;
        nextNode = startnode;
        gParent = 0;
    end

 % Endknoten erreicht?
    if nextNode == endnode
        break;
    end
  
% nächstes Node in closed List einfügen und in openList löschen
    closedList(counter,1) = nextNode;
    closedList(counter,2) = fmin;
    closedList(counter,3) = gParent;
    if counter > 1
        closedList(counter,4) = closedList(counter-1,1);
    end
    %indexNextNode = find(openList(:,1)==nextNode);
    %openList(indexNextNode,:)=0;
    openList = zeros(50,4);
    counter = counter + 1;

 % Nachbarn suchen und openList hinzufügen
    neighborsArray = neighbors(Graph,nextNode);
    neighborsRow = outedges(Graph,nextNode);
    for n = 1:length(neighborsArray)
        actualNeighbor = neighborsArray(n);
        gNeighbor = gParent + Graph.Edges.Weight(neighborsRow(n));
        for index = 1:size(closedList,1)
            if closedList(index,1) == actualNeighbor
                inClosedList = true;
            end
             if openList(index,1) == actualNeighbor
                inOpenList = true;
             end
        end

        if gNeighbor < gParent  && inClosedList == true
            closedList(closedList(:,1)==actualNeighbor,3) = gNeighbor;
            closedList(closedList(:,1)==actualNeighbor,4) = nextNode;
        elseif gNeighbor < gParent && inOpenList == true
                openList(openList(:,1)==actualNeighbor,3) = gNeighbor;
                openList(openList(:,1)==actualNeighbor,4) = nextNode;         
        elseif inClosedList == false && inOpenList == false
                    nextIndex = find(openList(:,1)==0);
                    openList(nextIndex(1),1) = actualNeighbor;
                    openList(nextIndex(1),3) = gNeighbor;
        end
        inClosedList = false;
        inOpenList = false;
    end
end

closedList(counter,1) = endnode;
wayPointList = zeros(20,1);
for index = 1:counter
    wayPointList(index) = closedList(index,1);
end
