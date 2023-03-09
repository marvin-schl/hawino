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

Graph = graph(A);
%%

startnode = 1;
endnode = 20;
h = [7; 6; 5; 4; 6; 5; 4; 3; 5; 4; 3; 2; 4; 3; 2; 1; 3; 2; 1; 0];

openList = zeros(30,4);         % 1: Node, 2: f, 3: g, 4: ParentNode
openList(1,1) = startnode;
closedList = zeros(30,4);       % 1: Node, 2: f, 3: g, 4: ParentNode
f = 0; % sqrt(power(xStart(actualNode)-xEnd,2) + power(yStart(actualNode)-yEnd,2)); 
% weil f = g + h und g müsste bei Startknoten 0 sein
openList(1,2) = f;
g = zeros(20,1);
g(startnode) = f;
openList(1,3) = g(startnode);
gParent = 0;
counter = 1;
nextNode = startnode;


while (nextNode ~= endnode)
    
%Suche nach Node mit kleinstem f in openList
    for i = 1:30 % alle Knoten aus openList durchgehen und kleinstes f(n) suchentrue
        if openList(i,1)~=0
            actualNode = openList(i,1);
            % actualNode ist wieder 2, weil erstes Element der Liste...
            % Macht keinen sinn und gibt keine Verbindung zum Knoten 6...
            % irgendwie abfangen, falls keine Verbindung...
        else
            break;
        end

        if actualNode > 1
            row1 = outedges(Graph,nextNode); % alle Zeilen in G (von Kanten) wo Knoten 6 beteiligt ist
            row2 = outedges(Graph,actualNode); % alle Zeilen in G wo aktueller Knoten beteiligt ist
            searchedRow = intersect(row1,row2);
            if openList(i,2) == 0%size(searchedRow,1) == 0
                g(actualNode) = gParent + Graph.Edges.Weight(searchedRow); %Gewichtung von Knoten in openList
                %h = sqrt(power(xStart(actualNode)-xEnd,2) + power(yStart(actualNode)-yEnd,2));
                f = g(actualNode) + h(actualNode);
                openList(i,2) = f;
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
    indexNextNode = find(openList(:,1)==nextNode);
    openList(indexNextNode,:)=0;
    counter = counter + 1;

 % Nachbarn suchen und openList hinzufügen
    neighborsArray = neighbors(Graph,nextNode);
    neighborsRow = outedges(Graph,nextNode);
    for n = 1:length(neighborsArray)
        actualNeighbor = neighborsArray(n);
        gNeighbor = gParent + Graph.Edges.Weight(neighborsRow(n));
        if gNeighbor < gParent && find(closedList(:,1)==actualNeighbor) ~= 0
            closedList(closedList(:,1)==actualNeighbor,3) = gNeighbor;
            closedList(closedList(:,1)==actualNeighbor,4) = nextNode;
        elseif gNeighbor < gParent && find(openList(:,1)==actualNeighbor) ~= 0
                openList(openList(:,1)==actualNeighbor,3) = gNeighbor;
                openList(openList(:,1)==actualNeighbor,4) = nextNode;         
        elseif (any(closedList(:,1)==actualNeighbor) && any(openList(:,1)==actualNeighbor)) == 0
                    nextIndex = find(openList(:,1)==0);
                    openList(nextIndex(1),1) = actualNeighbor;
                    openList(nextIndex(1),3) = gNeighbor;
        end
    end
end

closedList(counter,1) = endnode;

wayPointList = closedList(1:counter,1);