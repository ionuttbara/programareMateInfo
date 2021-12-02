// Se genereaza toate combinarile de m elemente ale multimii {1,2, …,n}.

#include <iostream>
using namespace std;

int s[20], m, n;

void init(int k)
{
	if(k==1) // Verifica daca valoarea de pe nivelul k este strict mai mare decat oricare dintre valorile de pe niveuri inferioare.
		s[k]=0; // Nivelul k al stivei se va initializa cu valoarea 0, urmand ca la pasul urmator sa i se atribuie ca valoarea 1, adica primul numar din multime.
	else
		s[k]=s[k-1]; // Nivelul k al stivei se va initializa cu o valoare egala cu cea a elementului de pe nivelul k-1.
}

int succesor(int k)
{
    if(s[k]<n-m+k) // Verifica daca mai exista un element pentru nivelul k al solutiei (un succesor) care o valoare mai mica decat n-m+k.
    {

        s[k]=s[k]+1; // Daca mai exista un succesor, se trece la urmatorul element din multimea Ak.
        return 1; // De asemenea, functia va returna valoarea 1 (true).
    }
    else return 0; // Daca k >= n, inseamna ca pe aceasta pozitie din permutare nu mai poate fi pus nici un numar. Functia va returna valoarea 0 (false).
}

int valid(int k)
{
	int i;

    for(i=1;i<k;i++)   // Verifica daca numarul din pozitia k nu mai exista in cele k-1 pozitii anterioare.
		if(s[k]==s[i])
			return 0; // Daca este indeplinita conditia, functia va returna valoarea 0 (false).
		return 1; // Daca numarul nu indeplineste aceasta conditie, functia va returna valoarea 1 (true).
}

int solutie(int k)
{
    return k==m; // Verifica daca s-au gasit solutii de aranjare in permutare pentru toate cele m numere. Daca s-au gasit, intoarce valoarea 1; altfel, 0.
}

void tipar()
{
	int i;

    for(i=1;i<=n;i++)
        cout << s[i] << " "; // Afiseaza elementele solutiei. De obicei, afisarea solutiei consta in afisarea valorilor din stiva.
	cout << endl;
}

void bt(int k)
{
    init(k); // Se initializeaza stiva pentru elementul k al solutiei.

    while(succesor(k)) // Cat timp se gaseste succesor pentru elementul k al solutiei.
        if(valid(k)) // Daca succesorul este element al solutiei.
            if(solutie(k)) // Verifica daca s-au obtinut toate elementele solutiei.
                tipar(); // Daca s-au gasit, atunci se afiseaza elementele solutiei.
            else
                bt(k+1);  // Altfel, se apeleaza subprogramul pentru a gasi elementul k+1 al solutiei.
}

int main()
{
    cout << "Cat (n)? "; cin >> n;
	cout << "Cat (m)? "; cin >> m;
    bt(1); // Apeleaza functia bt pentru completarea pozitiei 1 din vectorul s.
}
