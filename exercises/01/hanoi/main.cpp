// Algorithmus bzw. C++-Quellcode für Hanoi-2k mit Zügen für Aufgabenteil a)

#include <iostream>

using namespace std;

unsigned int move_count; // enthält Anzahl der durchgeführten Züge

// rekursive Funktion um die normalen Türme von Hanoi zu lösen
void hanoi1(unsigned int count, char start, char help, char dest){
	if (count == 0)
		return;

	hanoi1(count-1, start, dest, help); // bewege Scheiben 1 bis n-1 auf Hilfstab

	cout << count << ": " << start << " -> " << dest << endl; // führe trivialen Zug für n. Scheibe aus
	move_count += 1;
	
	hanoi1(count-1, help, start, dest); // bewege restlichen Turm vom Hilfsstab auf das Ziel
}

// rekursive Funktion, um das 2k-Türme Problem zu lösen
void hanoi2(unsigned int count, char start, char help, char even, char odd){
	if (count == 0)
		return;

	hanoi1(2*count - 2, start, even, help); // räume obersten 2k-2 Scheiben mithilfe von hanoi1 auf Hilfsstab

	cout << 2*count-1 << ": " << start << " -> " << odd << endl; // trivialer Zug für größte ungerade Scheibe
	cout << 2*count << ": " << start << " -> " << even << endl; // trivialer Zug für größte gerade Scheibe
	move_count += 2;

	hanoi2(count-1, help, start, even, odd); // verfahre nun mit restlichem Turm der Höhe 2k-2 , wie mit Turm der Höhe 2k
}

int main(int argc, char const *argv[])
{
	move_count = 0;
	hanoi2(1, 'S', 'H', 'E', 'O'); // Turmhöhe 2
	cout << move_count << endl;

	move_count = 0;
	hanoi2(2, 'S', 'H', 'E', 'O'); // Turmhöhe 4
	cout << move_count << endl;

	move_count = 0;
	hanoi2(3, 'S', 'H', 'E', 'O'); // Turmhöhe 6
	cout << move_count << endl;

	return 0;
}

/*
S...Startstab
H...Hilfsstab
E..."gerader" Stab
O..."Ungerader" Stab

linke Zahl beschreibt Scheibe, welche bewegt wird

Züge für k = 1:
1: S -> O
2: S -> E

Züge für k = 2:
1: S -> E
2: S -> H
1: E -> H
3: S -> O
4: S -> E
1: H -> O
2: H -> E

Züge für k = 3:
1: S -> E
2: S -> H
1: E -> H
3: S -> E
1: H -> S
2: H -> E
1: S -> E
4: S -> H
1: E -> H
2: E -> S
1: H -> S
3: E -> H
1: S -> E
2: S -> H
1: E -> H
5: S -> O
6: S -> E
1: H -> E
2: H -> S
1: E -> S
3: H -> O
4: H -> E
1: S -> O
2: S -> E

*/
